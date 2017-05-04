#include "subscribe.h"
#include <iostream>
#include <cstdio>
#include <cstring>
#include <stdio.h>

using std::cout;
using std::endl;

//Subscribe::Subscribe(const char *_host, int _port )
//{
////    //Inicia a API do mosquitto
////    mosqpp::lib_init();
////    this->keepalive=60;
////    this->host = _host;
////    this->port = _port;
////    //Conecta o subscribe
////    this->connect(host, port, keepalive);
////    this->loop_start();
//}

Subscribe::Subscribe() {}

Subscribe::~Subscribe()
{
//    this->loop_stop();
//    mosqpp::lib_cleanup();
}

/*void Subscribe::on_connect(int rc)
{
    if (0 == rc){
        cout << ">> Cliente subscribe - conectado ao servidor." << endl;
    }else{
        cout << ">> Cliente subscribe - impossivel de conectar ao servidor (" << rc << ")" << endl;
    }
}

void Subscribe::on_disconnect(int rc)
{
    cout << ">> Cliente subscribe - desconectado (" << rc << ")" << endl;
}

void Subscribe::on_subscribe(int mid, int qos_count, const int *granted_qos)
{
    cout << ">> Subscrito no tópico" << mid << " com qualidade de serviço " << qos_count << " e qos garantido de " << granted_qos  << endl;
}

void Subscribe::on_unsubscribe(int mid)
{
    cout << ">> Cancelado subscrição (" << mid << ")" << endl;
}

void Subscribe::on_message(const mosquitto_message *message)
{
    cout << ">> Cliente subscribe >> tópico: " << message->topic << " qualidade de serviço: " << message->qos << " payload " << message->payload << endl;
       char buf[256];
       memset(buf, 0, 51*sizeof(char));
        memcpy(buf, message->payload, 255*sizeof(char));
        cout << "msg " << buf << endl;
//        window.UpdateList(message);
}

void Subscribe::on_log(int level, const char *string)
{
//    cout << ">> Cliente subscribe >> Log de dados com level " << level << " e mensagem: " << string << endl;
}*/

void Subscribe::setMosquittoAPI(MosquittoAPI *api){
    mosquittoAPI = api;
}

MosquittoAPI* Subscribe::getMosquittoAPI()
{
    return mosquittoAPI;
}

bool Subscribe::SubscribeTopic(int *mid, const char *_topic, int _qos)
{
    mosquittoAPI->SubscribeTopic(NULL, _topic, _qos);
//    this->subscribe(NULL, _topic, _qos);
}


bool Subscribe::UnsubscribeTopic(int *mid, const char *_topic)
{
    mosquittoAPI->UnsubscribeTopic(NULL, _topic);
//    this->unsubscribe(NULL, _topic);
}

//bool Subscribe::setWindow(Window* w){
//    window = w;
//}
