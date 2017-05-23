#include "broadcast.hpp"
#include "bd_tool.hpp"
#include <iostream>
#include <netdb.h>
#include <sys/socket.h>
#ifndef SENDER
const int PORT = 7773;
#else 
const int PORT = 7774;
#endif
void bd_so::BroadcastCenter::startSend(std::string msg) {
//	if(this->is_casting || !this->is_sender || this->is_receiving) {
//		std::cerr << "isn't a client or is broadcasting" << std::endl;
//		return;
//	}else {
		this->is_casting = true;
		strcpy(buf,msg.c_str());
		sendto(socket_fd,buf,strlen(buf),0,(struct sockaddr *)&my_addr,sizeof(my_addr));
		this->is_casting = false;
//	}
}

void bd_so::BroadcastCenter::init_addr() {
	my_addr.sin_family = AF_INET;
	my_addr.sin_port = htons(PORT); 
	std::string bd_address = boardcast_addr();
	my_addr.sin_addr.s_addr = inet_addr(bd_address.c_str());
	
	user_addr.sin_family = AF_INET;
	user_addr.sin_port = htons(PORT); 
	user_addr.sin_addr.s_addr = htonl(INADDR_ANY); 
	socket_fd = socket(AF_INET,SOCK_DGRAM,0);
	if(-1 == socket_fd) {
		perror("socket init failed");
		exit(1);
	}
	setsockopt(socket_fd,SOL_SOCKET,SO_BROADCAST,&so_broadcast,sizeof(so_broadcast));
	if((bind(socket_fd,(struct sockaddr *)&user_addr,sizeof(struct sockaddr)))==-1){
		perror("bind failed");
		exit(1);
	}
}

void bd_so::BroadcastCenter::startReceiving() {
	if(is_sender == true || is_receiving) {
		std::cerr << "not receiver or is receiving" << std::endl;
		exit(1);
	}
	this->is_receiving = true;
	socklen_t size = sizeof(user_addr);
	recvfrom(socket_fd,buf,MAXDATASIZE,0,(struct sockaddr *)&user_addr,&size);
	std::cout<<"buffer:"<<std::string(buf)<<std::endl;
	strcpy(my_ip,inet_ntoa(user_addr.sin_addr));
	std::cout<<std::string(my_ip)<<std::endl;
	while(1) {
		bzero(buf,sizeof(buf));
		size = sizeof(user_addr);
		recvfrom(socket_fd,buf,MAXDATASIZE,0,(struct sockaddr *)&user_addr,&size);
		std::cout<<"buffer:"<<std::string(buf)<<std::endl;
	}
}
