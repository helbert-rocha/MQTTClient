#ifndef BROKERSTATUS_H
#define BROKERSTATUS_H
#include <mosquittopp.h>
#include "window.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
#include "utils.h"
#include "mosquittoapi.h"
class Window;
class MosquittoAPI;

class BrokerStatus
{
private:
    char version[50];
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
    Window *window;
    MosquittoAPI *mosquittoAPI;

//    void on_connect(int rc);
//    void on_disconnect(int rc);
//    void on_subscribe(int mid, int qos_count, const int *granted_qos);
//    void on_message(const mosquitto_message *message);
//    void on_log(int level, const char *string);

public:
//    BrokerStatus(const char *_host, int _port);
    BrokerStatus();
    ~BrokerStatus();
    const char *brokerVersion = "$SYS/broker/version";
    const char *brokertUptime = "$SYS/broker/uptime";
    const char *brokerTimestamp = "$SYS/broker/timestamp";
    const char *brokerSubscriptions = "$SYS/broker/subscriptions/count";
    const char *brokerClientsConnected = "$SYS/broker/clients/connected";
    const char *brokerClientsDisconnected = "$SYS/broker/clients/disconnected";
    const char *brokerClientsExpired = "$SYS/broker/clients/expired";
    const char *brokerClientsMaximum = "$SYS/broker/clients/maximum";
    const char *brokerClientsTotal = "$SYS/broker/clients/total";
    const char *brokerMessageSent = "$SYS/broker/messages/sent";
    const char *brokerMessageReceived = "$SYS/broker/messages/received";
    const char *brokerMessageStored = "$SYS/broker/messages/stored";
    const char *brokerBytesSent = "$SYS/broker/bytes/sent";
    const char *brokerBytesReceived = "$SYS/broker/bytes/received";
    void SetWindow(Window *win);
    void SetVersion(const char *string);
    void SetUptime(const char *string);
    void SetTimestamp(const char *string);
    void SetSubscriptions(const char *string);
    void SetClientsConnected(const char *string);
    void SetClientsDisconnected(const char *string);
    void SetClientsExpired(const char *string);
    void SetClientsMaximum(const char *string);
    void SetClientsTotal(const char *string);
    void SetMessageSent(const char *string);
    void SetMessageReceived(const char *string);
    void SetMessageStored(const char *string);
    void SetBytesSent(const char *string);
    void SetBytesReceived(const char *string);
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
//    bool SubscribeTopic(int *mid, const char *_topic, int _qos);
//    bool UnsubscribeTopic(int *mid, const char *_topic);
    void SubscribeAllTopics();
    void UnsubscribeAllTopics();
    void SetMosquittoAPI(MosquittoAPI *mosquittoAPI);

};

#endif // BROKERSTATUS_H
