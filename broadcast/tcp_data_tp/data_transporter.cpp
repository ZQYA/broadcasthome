#include "data_transporter.hpp"
#include "../broadcast.hpp"
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <cstdlib>
extern std::string local_ip; 
const int MAXTCPBUFFSIZE = 1024;
void bd_so::DataClient::send_self_ip() {
    char *buffer = (char *)malloc(MAXTCPBUFFSIZE+1); 
    int n = 0 ; //read count;        
    int socket_fd = socket(AF_INET,SOCK_STREAM,0);
    if(-1==socket_fd) 
       perror("tcp client socket create failed"), exit(1);

    sockaddr_in *server_addr = new sockaddr_in();
    bzero(server_addr,sizeof(sockaddr_in));
    (*server_addr).sin_family = AF_INET;
    (*server_addr).sin_port = htons(SERVER_PORT);
    (*server_addr).sin_addr.s_addr = inet_addr(server_ip);

    int con_stat = connect(socket_fd,(const struct sockaddr *)server_addr,(socklen_t)sizeof(sockaddr_in));
    if(-1 == con_stat)
       perror("tcp connect failed"),exit(1); 

    write(socket_fd,local_ip.c_str(),local_ip.length());//write local ip to server 
    while((n = read(socket_fd,buffer,MAXTCPBUFFSIZE))>0) {
        buffer[n] = 0;
        if(n >= 2) {
          printf("buf:%s",buffer); 
          close(socket_fd);
        }
    }
    free(buffer);
    delete server_addr;
}


bd_so::DataServer::DataServer(int p) {
   int socket_fd = socket(AF_INET,SOCK_STREAM,0) ;
   if( -1 == socket_fd) 
       perror("tcp server socket create fail"),exit(1);
   sockaddr_in *server_addr = new sockaddr_in();
   bzero(server_addr,sizeof(sockaddr_in));
   server_addr->sin_addr.s_addr = htonl(INADDR_ANY);
   server_addr->sin_port = htons(p);
   int bind_stat = bind(socket_fd,(const struct sockaddr *)server_addr,(socklen_t)sizeof(sockaddr_in)); 

   if(-1 == bind_stat)
       perror("tcp server bind fail"),exit(1);
   int listen_stat = listen(socket_fd,10);
   if(-1 == listen_stat)
       perror("linsten server fail"),exit(1);           
   while(1){
		sockaddr_in con_addr;
        socklen_t socklen = sizeof(con_addr);
		bzero(&con_addr,socklen);
        int accept_stat = accept(socket_fd,(struct sockaddr *)(&con_addr),&socklen);
        if(-1 == accept_stat)
             perror("accept server fail"),exit(1);
        int n = 0;
        char *buffer = (char *)malloc(MAXDATASIZE+1);
        bzero(buffer,MAXDATASIZE);
        while((n = read(socket_fd,buffer,MAXDATASIZE))>0){
            buffer[n] = 0; 
            printf("buf:%s",buffer);
            bzero(buffer,MAXDATASIZE);
            write(socket_fd,"ok",2);//write response
        }
        free(buffer);
    }  
    delete server_addr; 
};
