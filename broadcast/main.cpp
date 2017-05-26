#include "bd_tool.hpp"
#include "broadcast.hpp"
#include <string>
#include <iostream>
#include <unistd.h>
using namespace bd_so;
int main() {
#ifdef SENDER
	usleep(5*1000*1000);
	bd_so::BroadcastCenter center(true);
	center.startSend("hello");
#else 
	bd_so::BroadcastCenter::start_listen_thread();
#endif
	return 1;
}
