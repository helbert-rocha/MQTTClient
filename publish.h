#ifndef PUBLISH_H
#define PUBLISH_H
#include <mosquittopp.h>
#include "mosquittoapi.h"
class Publish
{
private:
//    const char *host;
//    const char *id;
//    const char *topic;
//    int *mid;

//    int port;
//    int keepalive;
    MosquittoAPI *mosquittoAPI;
public:
    Publish(const char *_host, int _port);
    Publish();
    ~Publish();
    void setMosquittoAPI(MosquittoAPI *api);
    MosquittoAPI* getMosquittoAPI();
    bool SendMessage(const char *_message, const char *_topic, int _qos);
};

#endif // PUBLISH_H
