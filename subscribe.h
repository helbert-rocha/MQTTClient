#ifndef SUBSCRIBE_H
#define SUBSCRIBE_H
#include "mosquittoapi.h"

class MosquittoAPI;

class Subscribe
{
private:
    MosquittoAPI *mosquittoAPI;
public:
//    Subscribe(const char *_host, int _port);
    Subscribe();
    ~Subscribe();
    void setMosquittoAPI(MosquittoAPI *api);
    MosquittoAPI* getMosquittoAPI();
    bool SubscribeTopic(int *mid, const char *_topic, int _qos);
    bool UnsubscribeTopic(int *mid, const char *_topic);
};

#endif // SUBSCRIBE_H
