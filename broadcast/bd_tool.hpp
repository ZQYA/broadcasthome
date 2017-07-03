#ifndef __BD_TOOL__
#define __BD_TOOL__
#include <string>
std::string boardcast_addr(char *ip);
#define dk_perror(fmt) printf("ERROR:%s: function: %s line:%d\n",__FILE__,__func__,__LINE__);perror(fmt)
#endif
