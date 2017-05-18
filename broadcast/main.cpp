#include "bd_tool.hpp"
#include "broadcast.hpp"
#include <string>
#include <iostream>
using namespace bd_so;
int main() {
#ifdef SENDER
	bd_so::BroadcastCenter center(true);
	center.startSend();
#else 
	bd_so::BroadcastCenter center(false);
	center.startReceiving();
#endif
	return 1;
}
