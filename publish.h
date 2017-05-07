#ifndef PUBLISH_H
#define PUBLISH_H
#include "mosquittoapi.h"
class MosquittoAPI;

class Publish
{
private:
    MosquittoAPI *mosquittoAPI;
public:
    Publish();
    ~Publish();
    void setMosquittoAPI(MosquittoAPI *api);
    MosquittoAPI* getMosquittoAPI();
    bool SendMessage(const char *_message, const char *_topic, int _qos);
};

#endif // PUBLISH_H
