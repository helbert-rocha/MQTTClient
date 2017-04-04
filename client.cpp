#include "client.h"
#include <iostream>
#include <mosquittopp.h>

Client::Client(const char *_id, const char *_topic, const char *_host, int _port) : mosquittopp(_id)
{
    mosqpp::lib_init();
    this->keepalive = 60;
    this->id = _id;
    this->topic = _topic;
    this->host = _host;
    this->port = _port;
    mosqpp::mosquittopp::connect(host, port, keepalive);
    mosqpp::mosquittopp::loop_start();
}

Client::~Client()
{
    mosqpp::mosquittopp::disconnect();
    mosqpp::mosquittopp::loop_stop();
    mosqpp::lib_cleanup();
}

void Client::on_connect(int rc)
{
    if (0 == rc){
        std::cout << ">> Cliente - conectado ao servidor." << std::endl;
    }else{
        std::cout << ">> Cliente - impossivel de conectar ao servidor (" << rc << ")" <<std::endl;
    }
}

void Client::on_disconnect(int rc)
{
    std::cout << "Cliente - desconectado (" << rc << ")" << std::endl;
}

void Client::on_publish(int mid){
    std::cout << ">> Cliente mensagem - (" << mid <<") foi publicada com sucesso. " << std::endl;
}

bool Client::send_message(const char *_message, const char *_topic, int _qos)
{
    mosqpp::mosquittopp::publish(NULL, _topic, strlen(_message), _message, _qos, false);
}

bool Client::subscribe_topic(int *_mid, const char *_sub, int _qos){
    mosqpp::mosquittopp::subscribe(NULL, _sub, _qos);
}

void Client::on_subscribe(int mid, int qos_count, const int *granted_qos)
{
    std::cout << "Subscrito no tópico. " << mid << std::endl;
}

