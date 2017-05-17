#include "bd_tool.hpp"
#include <string>
#include <iostream>
int main(int args, const char *argv[]) {
	std::string bcaddr = boardcast_addr();
	std::cout<<bcaddr;
	return 1;
}
