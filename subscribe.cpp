#include "subscribe.h"

Subscribe::Subscribe() {}

Subscribe::~Subscribe(){}

void Subscribe::setMosquittoAPI(MosquittoAPI *api){
    mosquittoAPI = api;
}

MosquittoAPI* Subscribe::getMosquittoAPI()
{
    return mosquittoAPI;
}

bool Subscribe::SubscribeTopic(int *mid, const char *_topic, int _qos)
{
    mosquittoAPI->SubscribeTopic(NULL, _topic, _qos);
}


bool Subscribe::UnsubscribeTopic(int *mid, const char *_topic)
{
    mosquittoAPI->UnsubscribeTopic(NULL, _topic);
}
