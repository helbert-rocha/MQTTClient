#ifndef PUBLISH_H
#define PUBLISH_H
#include <mosquittopp.h>

class Publish: public mosqpp::mosquittopp
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
    void on_publish(int mid);
    void on_message(const mosquitto_message *message);
    void on_log(int level, const char *string);

public:
    Publish(const char *_host, int _port);
    Publish();
    ~Publish();
    bool SendMessage(const char *_message, const char *_topic, int _qos);
};

#endif // PUBLISH_H
