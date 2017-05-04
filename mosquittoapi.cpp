#include "mosquittoapi.h"
#include <iostream>
//#include "utils.cpp"
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
//    strcpy(newMessage, ConvertToChar(message->payload));

//    cout << "mensagem do broker: "<< newMessage << " com topico " << message->topic << endl;
}

void MosquittoAPI::on_log(int level, const char *string)
{
//    cout << ">> MosquittoAPI Cliente subscribe >> Log de dados com level " << level << " e mensagem: " << string << endl;
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
