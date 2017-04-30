#ifndef BROKERSTATUS_H
#define BROKERSTATUS_H
#include <mosquittopp.h>

class BrokerStatus: public mosqpp::mosquittopp
{
private:
    char version[100];
    char uptime[50];
    char timestamp[50];
    char subscriptions[50];
    char clientsConnected[50];
    char clientsDisconnected[50];
    char clientsExpired[50];
    char clientsMaximum[50];
    char clientsTotal[50];
    char messagesSent[50];
    char messagesReceived[50];
    char messagesStored[50];
    char bytesSent[50];
    char bytesReceived[50];

    void on_connect(int rc);
    void on_disconnect(int rc);
    void on_subscribe(int mid, int qos_count, const int *granted_qos);
    void on_message(const mosquitto_message *message);
//    void on_log(int level, const char *string);

public:
    BrokerStatus(const char *_host, int _port);
    BrokerStatus();
    ~BrokerStatus();
    char* GetVersion();
    char* GetUptime();
    char* GetTimestamp();
    char* GetSubscriptions();
    char* GetClientsConnected();
    char* GetClientsDisconnected();
    char* GetClientsExpired();
    char* GetClientsMaximum();
    char* GetClientsTotal();
    char* GetMessageSent();
    char* GetMessageReceived();
    char* GetMessageStored();
    char* GetBytesSent();
    char* GetBytesReceived();
    bool SubscribeTopic(int *mid, const char *_topic, int _qos);
    bool UnsubscribeTopic(int *mid, const char *_topic);
    void SubscribeAllTopics();
    void UnsubscribeAllTopics();

};

#endif // BROKERSTATUS_H
