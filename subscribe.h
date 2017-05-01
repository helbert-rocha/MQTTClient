#ifndef SUBSCRIBE_H
#define SUBSCRIBE_H
#include <mosquittopp.h>
#include "window.h"

class Subscribe: public mosqpp::mosquittopp
{
private:
    const char *host;
    const char *id;
    const char *topic;
    int *mid;

    int port;
    int keepalive;

    void on_connect(int rc);
    void on_disconnect(int rc);
    void on_subscribe(int mid, int qos_count, const int *granted_qos);
    void on_unsubscribe(int mid);
    void on_message(const mosquitto_message *message);
    void on_log(int level, const char *string);
    Window *window;
public:
    Subscribe(const char *_host, int _port);
    Subscribe();
    ~Subscribe();
    bool SubscribeTopic(int *mid, const char *_topic, int _qos);
    bool UnsubscribeTopic(int *mid, const char *_topic);
    void setWindow(Window w);
};

#endif // SUBSCRIBE_H
