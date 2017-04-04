#ifndef CLIENT_H
#define CLIENT_H
#include <mosquittopp.h>

class Client : public mosqpp::mosquittopp
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
    void on_subscribe(int mid, int qos_count, const int *granted_qos);

public:
    Client(const char *_id, const char *_topic, const char *_host, int _port);
   ~Client();
    bool send_message(const char *_message, const char *_topic, int _qos);
    bool subscribe_topic(int *mid, const char *sub, int qos);

};

#endif // CLIENT_H
