#include "brokerstatus.h"

/*Para pegar informações do broker é necessário
 *ter um cliente para subscrever nos tópicos de interesse,
 *esses tópicos contêm informações como a versão dos mesquitto entre outras.
*/
using std::cout;
using std::endl;

BrokerStatus::BrokerStatus(){}
BrokerStatus::~BrokerStatus(){}

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
    strcpy(clientsMaximum, string);
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
    mosquittoAPI->SubscribeTopic(NULL, brokerVersion, 0);
    mosquittoAPI->SubscribeTopic(NULL, brokertUptime, 0);
    mosquittoAPI->SubscribeTopic(NULL, brokerTimestamp, 0);
    mosquittoAPI->SubscribeTopic(NULL, brokerSubscriptions, 0);
    mosquittoAPI->SubscribeTopic(NULL, brokerClientsConnected, 0);
    mosquittoAPI->SubscribeTopic(NULL, brokerClientsDisconnected, 0);
    mosquittoAPI->SubscribeTopic(NULL, brokerClientsExpired, 0);
    mosquittoAPI->SubscribeTopic(NULL, brokerClientsMaximum, 0);
    mosquittoAPI->SubscribeTopic(NULL, brokerClientsTotal, 0);
    mosquittoAPI->SubscribeTopic(NULL, brokerMessageSent, 0);
    mosquittoAPI->SubscribeTopic(NULL, brokerMessageReceived, 0);
    mosquittoAPI->SubscribeTopic(NULL, brokerMessageStored, 0);
    mosquittoAPI->SubscribeTopic(NULL, brokerBytesSent, 0);
    mosquittoAPI->SubscribeTopic(NULL, brokerBytesReceived, 0);
}
void BrokerStatus::UnsubscribeAllTopics(){
    mosquittoAPI->UnsubscribeTopic(NULL, brokerVersion);
    mosquittoAPI->UnsubscribeTopic(NULL, brokertUptime);
    mosquittoAPI->UnsubscribeTopic(NULL, brokerTimestamp);
    mosquittoAPI->UnsubscribeTopic(NULL, brokerSubscriptions);
    mosquittoAPI->UnsubscribeTopic(NULL, brokerClientsConnected);
    mosquittoAPI->UnsubscribeTopic(NULL, brokerClientsDisconnected);
    mosquittoAPI->UnsubscribeTopic(NULL, brokerClientsExpired);
    mosquittoAPI->UnsubscribeTopic(NULL, brokerClientsMaximum);
    mosquittoAPI->UnsubscribeTopic(NULL, brokerClientsTotal);
    mosquittoAPI->UnsubscribeTopic(NULL, brokerMessageSent);
    mosquittoAPI->UnsubscribeTopic(NULL, brokerMessageReceived);
    mosquittoAPI->UnsubscribeTopic(NULL, brokerMessageStored);
    mosquittoAPI->UnsubscribeTopic(NULL, brokerBytesSent);
    mosquittoAPI->UnsubscribeTopic(NULL, brokerBytesReceived);
}

void BrokerStatus::SetMosquittoAPI(MosquittoAPI *_mosquittoAPI)
{
    mosquittoAPI = _mosquittoAPI;
}

void BrokerStatus::SetWindow(Window *win){
    window = win;
}
