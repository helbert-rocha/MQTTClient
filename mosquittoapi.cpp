#include "mosquittoapi.h"

using std::cout;
using std::endl;

MosquittoAPI::MosquittoAPI(const char *_host, int _port)
{
    mosqpp::lib_init();
    this->host = _host;
    this->port = _port;
    this->keepalive = 60;
    this->connect(_host, _port, keepalive);
    this->loop_start();
    Log *log = new Log("Start the program");
    logList = new LogList();
    logList->AddLog(log);
}

MosquittoAPI::MosquittoAPI()
{
    delete logList;
}

MosquittoAPI::~MosquittoAPI(){
    this->loop_stop();
    mosqpp::lib_cleanup();
}

void MosquittoAPI::on_connect(int rc)
{
    if (0 == rc){
        cout << ">> Cliente MosquittoAPI - conectado ao servidor." << endl;
    }else{
        cout << ">> Cliente MosquittoAPI - impossivel de conectar ao servidor (" << rc << ")" << endl;
    }
}

void MosquittoAPI::on_disconnect(int rc)
{
    cout << ">> Cliente MosquittoAPI - desconectado (" << rc << ")" << endl;
}

void MosquittoAPI::on_publish(int mid)
{
    cout << ">> Cliente MosquittoAPI mensagem - (" << mid <<") foi publicada com sucesso. " << endl;
}

void MosquittoAPI::on_subscribe(int mid, int qos_count, const int *granted_qos)
{
    cout << ">> MosquittoAPI Subscrito no tópico" << mid << " com qualidade de serviço " << qos_count << " e qos garantido de " << granted_qos  << endl;
}

void MosquittoAPI::on_unsubscribe(int mid)
{
    cout << ">> MosquittoAPI Cancelado subscrição (" << mid << ")" << endl;
}

void MosquittoAPI::on_message(const mosquitto_message *message)
{
    char newMessage[256];
    strcpy(newMessage, Utils::ConvertToChar(message->payload));
    int systemFile = strstr(message->topic, "$SYS/broker/") != NULL;
    cout << "mensagem da API: "<< newMessage << " payloaden " << message->payloadlen << " com topico " << message->topic << endl;
    if (systemFile == 1){
        if (0==strcmp(message->topic, brokerStatus->brokerVersion))
        {
            brokerStatus->SetVersion(newMessage);
        }
        else if (0 == strcmp(message->topic, brokerStatus->brokertUptime))
        {
            brokerStatus->SetUptime(newMessage);
        }
        else if (0 == strcmp(message->topic, brokerStatus->brokerTimestamp))
        {
            brokerStatus->SetTimestamp(newMessage);
        }
        else if (0 == strcmp(message->topic, brokerStatus->brokerSubscriptions))
        {
            brokerStatus->SetSubscriptions(newMessage);
        }
        else if (0 == strcmp(message->topic, brokerStatus->brokerClientsConnected))
        {
            brokerStatus->SetClientsConnected(newMessage);
        }
        else if (0 == strcmp(message->topic, brokerStatus->brokerClientsDisconnected))
        {
            brokerStatus->SetClientsDisconnected(newMessage);
        }
        else if (0 == strcmp(message->topic, brokerStatus->brokerClientsExpired))
        {
            brokerStatus->SetClientsExpired(newMessage);
        }
        else if (0 == strcmp(message->topic, brokerStatus->brokerClientsMaximum))
        {
            brokerStatus->SetClientsMaximum(newMessage);
        }
        else if (0 == strcmp(message->topic, brokerStatus->brokerClientsTotal))
        {
            brokerStatus->SetClientsTotal(newMessage);
        }
        else if (0 == strcmp(message->topic, brokerStatus->brokerMessageSent))
        {
            brokerStatus->SetMessageSent(newMessage);
        }
        else if (0 == strcmp(message->topic, brokerStatus->brokerMessageReceived))
        {
            brokerStatus->SetMessageReceived(newMessage);
        }
        else if (0 == strcmp(message->topic, brokerStatus->brokerMessageStored))
        {
            brokerStatus->SetMessageStored(newMessage);
        }
        else if (0 == strcmp(message->topic, brokerStatus->brokerBytesSent))
        {
            brokerStatus->SetBytesSent(newMessage);
        }
        else if (0 == strcmp(message->topic, brokerStatus->brokerBytesReceived))
        {
            brokerStatus->SetBytesReceived(newMessage);
        }
        window->GetBrokerInfos();
        systemFile = 0;

    }else{
        window->UpdateMessageList(message->topic, newMessage, message->qos);
    }

}

void MosquittoAPI::on_log(int level, const char *string)
{
   cout << ">> MosquittoAPI Cliente subscribe >> Log de dados com level " << level << " e mensagem: " << string << endl;
   const int existConnect = strstr(string, "CONNECT") != NULL;
   const int existConnack = strstr(string, "CONNACK") != NULL;
   const int existPingreq = strstr(string, "PINGREQ") != NULL;
   const int existPingresp = strstr(string, "PINGRESP") != NULL;
//   int systemFile = strstr(string, "$SYS/broker/") != NULL;

   if(existConnect!=1 && existConnack!=1 && existPingreq!=1 && existPingresp!=1){

     Log *newLog = new Log(strdup(string));
     window->UpdateLogList(newLog);
     logList->AddLog(newLog);
     SaveLog(&txtLogDao, newLog);
     SaveLog(&csvLogDao, newLog);
     SaveLog(&jsonLogDao, newLog);
   }

}

void MosquittoAPI::SaveLog(LogDao *logDao, Log *log)
{
    logDao->save(log);
}

bool MosquittoAPI::PublishMessage(const char *_message, const char *_topic, int _qos){
    this->publish(NULL, _topic, strlen(_message), _message, _qos, false);
}

bool MosquittoAPI::SubscribeTopic(int *_mid, const char *_topic, int _qos)
{
    this->subscribe(NULL, _topic, _qos);
}

bool MosquittoAPI::UnsubscribeTopic(int *_mid, const char *_topic)
{
    this->unsubscribe(NULL, _topic);
}

void MosquittoAPI::SetWindow(Window *_window){
    window = _window;
}

void MosquittoAPI::SetBrokerStatus(BrokerStatus *_brokerStatus)
{
    brokerStatus = _brokerStatus;
}
