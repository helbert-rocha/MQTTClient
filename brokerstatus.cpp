#include "brokerstatus.h"

/*Para pegar informações do broker é necessário
 *ter um cliente para subscrever nos tópicos de interesse,
 *esses tópicos contêm informações como a versão dos mesquitto entre outras.
*/
using std::cout;
using std::endl;
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

BrokerStatus::BrokerStatus(const char *_host, int _port)
{
    mosqpp::lib_init();
    this->connect(_host, _port, 60);
    this->loop_start();
}
BrokerStatus::BrokerStatus(){}
BrokerStatus::~BrokerStatus(){
    this->loop_stop();
    mosqpp::lib_cleanup();
}


bool BrokerStatus::SubscribeTopic(int *mid, const char *_topic, int _qos){
    this->subscribe(NULL, _topic, 0);
}

bool BrokerStatus::UnsubscribeTopic(int *mid, const char *_topic){
    this->unsubscribe(NULL, _topic);
}

void BrokerStatus::on_message(const mosquitto_message *message){
    char newMessage[256];
    strcpy(newMessage, Utils::ConvertToChar(message->payload));

    if (0==strcmp(message->topic, brokerVersion))
    {
        strcpy(version, newMessage);
    }else if (0 == strcmp(message->topic, brokertUptime))
    {
        strcpy(uptime, newMessage);
    }
    else if (0 == strcmp(message->topic, brokerTimestamp))
    {
        strcpy(timestamp, newMessage);
    }
    else if (0 == strcmp(message->topic, brokerSubscriptions))
    {
        strcpy(subscriptions, newMessage);
    }
    else if (0 == strcmp(message->topic, brokerClientsConnected))
    {
        strcpy(clientsConnected, newMessage);
    }
    else if (0 == strcmp(message->topic, brokerClientsDisconnected))
    {
        strcpy(clientsDisconnected, newMessage);
    }
    else if (0 == strcmp(message->topic, brokerClientsExpired))
    {
        strcpy(clientsExpired, newMessage);
    }
    else if (0 == strcmp(message->topic, brokerClientsMaximum))
    {
        strcpy(clientsMaximum, newMessage);
    }
    else if (0 == strcmp(message->topic, brokerClientsTotal))
    {
        strcpy(clientsTotal, newMessage);
    }
    else if (0 == strcmp(message->topic, brokerMessageSent))
    {
        strcpy(messagesSent, newMessage);
    }
    else if (0 == strcmp(message->topic, brokerMessageReceived))
    {
        strcpy(messagesReceived, newMessage);
    }
    else if (0 == strcmp(message->topic, brokerMessageStored))
    {
        strcpy(messagesStored, newMessage);
    }
    else if (0 == strcmp(message->topic, brokerBytesSent))
    {
        strcpy(bytesSent, newMessage);
    }
    else if (0 == strcmp(message->topic, brokerBytesReceived))
    {
        strcpy(bytesReceived, newMessage);
    }
    cout << "mensagem do broker: " << newMessage << "com topico " << message->topic << endl;
    window->GetBrokerInfos();
}

void BrokerStatus::on_connect(int rc){
    cout << ">> Broker status conectado" << endl;
}

void BrokerStatus::on_disconnect(int rc){
    cout << ">> Broker status - desconectado (" << rc << ")" << endl;
}

void BrokerStatus::on_subscribe(int mid, int qos_count, const int *granted_qos){
    cout << ">> Broker status subscrito com id: " << mid << endl;
}

void BrokerStatus::on_log(int level, const char *string)
{
//    cout << ">> BrokerStatus Cliente subscribe >> Log de dados com level " << level << " e mensagem: " << string << endl;
}

void BrokerStatus::SetVersion(const char *string){
    strcpy(version, string);
}
void BrokerStatus::SetUptime(const char *string){
    strcpy(uptime, string);
}
void BrokerStatus::SetTimestamp(const char *string){
    strcpy(timestamp, string);
}
void BrokerStatus::SetSubscriptions(const char *string){
    strcpy(subscriptions, string);
}
void BrokerStatus::SetClientsConnected(const char *string){
    strcpy(clientsConnected, string);
}
void BrokerStatus::SetClientsDisconnected(const char *string){
    strcpy(clientsDisconnected, string);
}
void BrokerStatus::SetClientsExpired(const char *string){
    strcpy(clientsExpired, string);
}
void BrokerStatus::SetClientsMaximum(const char *string){
    strcpy(version, string);
}
void BrokerStatus::SetClientsTotal(const char *string){
    strcpy(clientsTotal, string);
}
void BrokerStatus::SetMessageSent(const char *string){
    strcpy(messagesSent, string);
}
void BrokerStatus::SetMessageReceived(const char *string){
    strcpy(messagesReceived, string);
}
void BrokerStatus::SetMessageStored(const char *string){
    strcpy(messagesStored, string);
}
void BrokerStatus::SetBytesSent(const char *string){
    strcpy(bytesSent, string);
}
void BrokerStatus::SetBytesReceived(const char *string){
    strcpy(bytesReceived, string);
}

char *BrokerStatus::GetVersion(){
    return version;
}

char *BrokerStatus::GetUptime(){
    return uptime;
}

char *BrokerStatus::GetTimestamp(){
    return timestamp;
}

char *BrokerStatus::GetSubscriptions(){
    return subscriptions;
}

char *BrokerStatus::GetClientsConnected(){
    return clientsConnected;
}

char *BrokerStatus::GetClientsDisconnected(){
    return clientsDisconnected;
}

char *BrokerStatus::GetClientsExpired(){
    return clientsExpired;
}

char *BrokerStatus::GetClientsMaximum(){
    return clientsMaximum;
}

char *BrokerStatus::GetClientsTotal(){
    return clientsTotal;
}

char *BrokerStatus::GetMessageSent(){
    return messagesSent;
}

char *BrokerStatus::GetMessageReceived(){
    return messagesReceived;
}

char *BrokerStatus::GetMessageStored(){
    return messagesStored;
}

char *BrokerStatus::GetBytesSent(){
    return bytesSent;
}

char *BrokerStatus::GetBytesReceived(){
    return bytesReceived;
}

void BrokerStatus::SubscribeAllTopics(){
    SubscribeTopic(NULL, brokerVersion, 0);
    SubscribeTopic(NULL, brokertUptime, 0);
    SubscribeTopic(NULL, brokerTimestamp, 0);
    SubscribeTopic(NULL, brokerSubscriptions, 0);
    SubscribeTopic(NULL, brokerClientsConnected, 0);
    SubscribeTopic(NULL, brokerClientsDisconnected, 0);
    SubscribeTopic(NULL, brokerClientsExpired, 0);
    SubscribeTopic(NULL, brokerClientsMaximum, 0);
    SubscribeTopic(NULL, brokerClientsTotal, 0);
    SubscribeTopic(NULL, brokerMessageSent, 0);
    SubscribeTopic(NULL, brokerMessageReceived, 0);
    SubscribeTopic(NULL, brokerMessageStored, 0);
    SubscribeTopic(NULL, brokerBytesSent, 0);
    SubscribeTopic(NULL, brokerBytesReceived, 0);
}
void BrokerStatus::UnsubscribeAllTopics(){
    UnsubscribeTopic(NULL, brokerVersion);
    UnsubscribeTopic(NULL, brokertUptime);
    UnsubscribeTopic(NULL, brokerTimestamp);
    UnsubscribeTopic(NULL, brokerSubscriptions);
    UnsubscribeTopic(NULL, brokerClientsConnected);
    UnsubscribeTopic(NULL, brokerClientsDisconnected);
    UnsubscribeTopic(NULL, brokerClientsExpired);
    UnsubscribeTopic(NULL, brokerClientsMaximum);
    UnsubscribeTopic(NULL, brokerClientsTotal);
    UnsubscribeTopic(NULL, brokerMessageSent);
    UnsubscribeTopic(NULL, brokerMessageReceived);
    UnsubscribeTopic(NULL, brokerMessageStored);
    UnsubscribeTopic(NULL, brokerBytesSent);
    UnsubscribeTopic(NULL, brokerBytesReceived);
}

void BrokerStatus::SetWindow(Window *win){
    window = win;
}
