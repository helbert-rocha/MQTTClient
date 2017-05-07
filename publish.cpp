#include "publish.h"

Publish::Publish(){}

Publish::~Publish(){}

void Publish::setMosquittoAPI(MosquittoAPI *api){
    mosquittoAPI = api;
}

MosquittoAPI* Publish::getMosquittoAPI()
{
    return mosquittoAPI;
}

bool Publish::SendMessage(const char *_message, const char *_topic, int _qos){
    mosquittoAPI->PublishMessage(_message, _topic, _qos);
}
