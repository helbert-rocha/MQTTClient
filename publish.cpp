#include "publish.h"
#include <iostream>

using std::cout;
using std::endl;

Publish::Publish(const char *_host, int _port)
{
    //Inicia a API do mosquitto
    mosqpp::lib_init();
    this->keepalive=60;
    this->host = _host;
    this->port = _port;
    //Conecta o publish
    this->connect(host, port, keepalive);
    this->loop_start();
}

Publish::Publish()
{

}

Publish::~Publish()
{
    this->loop_stop();
    mosqpp::lib_cleanup();
}

void Publish::on_connect(int rc)
{
    if (0 == rc){
        cout << ">> Cliente publish - conectado ao servidor." << endl;
    }else{
        cout << ">> Cliente publish - impossivel de conectar ao servidor (" << rc << ")" << endl;
    }
}

void Publish::on_disconnect(int rc)
{
    cout << ">> Cliente publish - desconectado (" << rc << ")" << endl;
}

void Publish::on_publish(int mid)
{
    cout << ">> Cliente publish mensagem - (" << mid <<") foi publicada com sucesso. " << endl;
}

void Publish::on_message(const mosquitto_message *message){
    cout << ">> Cliente publish >> tópico " << message->topic << " qualidade de serviço" << message->qos << " payload" << message->payload << endl;
}

void Publish::on_log(int level, const char *string)
{
    cout << ">> Cliente publish >> Log de dados com level " << level << " e mensagem: " << string << endl;
}

bool Publish::SendMessage(const char *_message, const char *_topic, int _qos){
    this->publish(NULL, _topic, strlen(_message), _message, _qos, false);
}
