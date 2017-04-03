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
