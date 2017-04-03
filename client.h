#ifndef CLIENT_H
#define CLIENT_H
#include <mosquittopp.h>

class Client : public mosqpp::mosquittopp
{
private:
    const char *host;
    const char *id;
    const char *topic;
    int port;
    int keepalive;

    void on_connect(int rc);
    void on_disconnect(int rc);
//    void on_publish(int mid);

public:
    Client(const char *_id, const char *_topic, const char *_host, int _port);
   ~Client();
    bool send_message(const char *message);
};

#endif // CLIENT_H
