#include "broadcast.hpp"
void bd_so::BroadcastCenter::startSend() {
	this->is_sender = true;
}

void bd_so::BroadcastCenter::startReceiving() {
	this->is_receiving = true;
}
