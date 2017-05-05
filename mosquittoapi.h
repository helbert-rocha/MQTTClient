#ifndef MOSQUITTOAPI_H
#define MOSQUITTOAPI_H
#include <mosquittopp.h>
#include "window.h"

class Window;
class MosquittoAPI: public mosqpp::mosquittopp
{
private:
    const char *host;
    int port;
    int keepalive;

    void on_connect(int rc);
    void on_disconnect(int rc);
    void on_publish(int mid);
    void on_subscribe(int mid, int qos_count, const int *granted_qos);
    void on_unsubscribe(int mid);
    void on_message(const mosquitto_message *message);
    void on_log(int level, const char *string);
    Window *window;
public:
    MosquittoAPI(const char *_host, int _port);
    ~MosquittoAPI();
    void SetWindow(Window *_window);
    bool PublishMessage(const char *_message, const char *_topic, int _qos);
    bool SubscribeTopic(int *mid, const char *_topic, int _qos);
    bool UnsubscribeTopic(int *mid, const char *_topic);
};

#endif // MOSQUITTOAPI_H
