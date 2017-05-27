#include <string>
#include <cstring>
#include <strings.h>
#include <cstdlib>

namespace bd_so {
    class DataClient  {
    private:
    char *server_ip;
	public:
	void send_self_ip();
	DataClient(std::string ip) {
		server_ip = (char *)malloc(20);
		bzero(server_ip,20);
		memcpy(server_ip,ip.c_str(),ip.length());
	}
    };
};

