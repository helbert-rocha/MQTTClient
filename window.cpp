#include "window.h"
#include "ui_window.h"
//#include "utils.h"
#include <iostream>
#include <unistd.h>
#include <string.h>
#include <list.h>
#include "logdao.h"
#include "txtlogdao.h"
using std::cout;
using std::endl;
using std::string;

Window::Window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Window)
{
    ui->setupUi(this);
    DisableComponents();

}


Window::~Window()
{
    delete ui;
    delete publish;
    delete subscribe;
    delete brokerStatus;
    delete mosquittoAPI;
    delete logList;
}

void Window::on_pushButtonConnect_clicked()
{
    string address = ui->lineEditBrokerAddress->text().toStdString();
    const char *add = address.c_str();
    int port = ui->lineEditBrokerPort->text().toInt();
    cout << "Endereço: " << add << endl;
    cout << "Porta: " << port << endl;
    DisableConnectComponents();
    mosquittoAPI = new MosquittoAPI(add, port);
    mosquittoAPI->SetWindow(this);
    publish = new Publish();
    publish->setMosquittoAPI(mosquittoAPI);
    subscribe = new Subscribe();
    subscribe->setMosquittoAPI(mosquittoAPI);
    brokerStatus = new BrokerStatus(add, port);
    brokerStatus->SetWindow(this);
    Log *log = new Log("Start the program");
    logList = new LogList();
    logList->AddLog(log);
    logList->ListLogs();
    EnableComponents();
}

void Window::on_pushButtonDisconnect_clicked()
{
    mosquittoAPI->disconnect();
    brokerStatus->disconnect();
    DisableComponents();
    EnableConnectComponents();
}

void Window::on_pushButtonPublish_clicked()
{
    string topic = ui->comboBoxPublishTopic->currentText().toStdString();
    const char *_topic = topic.c_str();

    string message = ui->textEditMessage->toPlainText().toStdString();
    const char *_message = message.c_str();

    if (ui->radioButtonQoS0Publish->isChecked())
    {
        publish->SendMessage(_message, _topic, 0);
    }else if(ui->radioButtonQoS1Publish->isChecked())
    {
        publish->SendMessage(_message, _topic, 1);
    }else{
        publish->SendMessage(_message, _topic, 2);
    }
}

void Window::EnableComponents()
{
    ui->pushButtonPublish->setEnabled(true);
    ui->textEditMessage->setEnabled(true);
    ui->comboBoxPublishTopic->setEnabled(true);
    ui->radioButtonQoS0Publish->setEnabled(true);
    ui->radioButtonQoS1Publish->setEnabled(true);
    ui->radioButtonQoS2Publish->setEnabled(true);
    ui->comboBoxSubscribeTopic->setEnabled(true);
    ui->pushButtonSubscribe->setEnabled(true);
    ui->pushButtonUnsubscribe->setEnabled(true);
    ui->radioButtonQoS0Subscribe->setEnabled(true);
    ui->radioButtonQoS1Subscribe->setEnabled(true);
    ui->radioButtonQoS2Subscribe->setEnabled(true);
    ui->pushButtonStatusStart->setEnabled(true);
    ui->pushButtonStatusStop->setEnabled(true);
}

void Window::DisableComponents()
{
    ui->pushButtonPublish->setEnabled(false);
    ui->textEditMessage->setEnabled(false);
    ui->comboBoxPublishTopic->setEnabled(false);
    ui->radioButtonQoS0Publish->setEnabled(false);
    ui->radioButtonQoS1Publish->setEnabled(false);
    ui->radioButtonQoS2Publish->setEnabled(false);
    ui->comboBoxSubscribeTopic->setEnabled(false);
    ui->pushButtonSubscribe->setEnabled(false);
    ui->pushButtonUnsubscribe->setEnabled(false);
    ui->radioButtonQoS0Subscribe->setEnabled(false);
    ui->radioButtonQoS1Subscribe->setEnabled(false);
    ui->radioButtonQoS2Subscribe->setEnabled(false);
    ui->pushButtonStatusStart->setEnabled(false);
    ui->pushButtonStatusStop->setEnabled(false);
}

void Window::EnableConnectComponents()
{
    ui->lineEditBrokerAddress->setEnabled(true);
    ui->lineEditBrokerPort->setEnabled(true);
    ui->pushButtonConnect->setEnabled(true);
}

void Window::DisableConnectComponents()
{
    ui->lineEditBrokerAddress->setEnabled(false);
    ui->lineEditBrokerPort->setEnabled(false);
    ui->pushButtonConnect->setEnabled(false);
}

void Window::on_pushButtonSubscribe_clicked()
{
    string topic = ui->comboBoxSubscribeTopic->currentText().toStdString();
    const char *_topic = topic.c_str();

    if (ui->radioButtonQoS0Subscribe->isChecked())
    {
        subscribe->SubscribeTopic(NULL, _topic, 0);
    }else if (ui->radioButtonQoS1Subscribe->isChecked())
    {
        subscribe->SubscribeTopic(NULL, _topic, 1);
    }else{
        subscribe->SubscribeTopic(NULL, _topic, 2);
    }



//    QWidget *widgetTopic = new QWidget();
//    widgetTopic->x = 10;
//    widgetTopic->y = 70;
//    widgetTopic->width = 254;
//    widgetTopic->height = 80;

//    Qlabel labelTopicName = new QLabel();
//    labelTopicName.x = 20;
//    labelTopicName.y = 10;
//    labelTopicName.width = 60;
//    labelTopicName.height = 16;
//    labelTopicName.text = _topic;

//    QLabel labelTopicElements = new QLabel();
//    labelTopicElements.x = 180;
//    labelTopicElements.y = 10;
//    labelTopicElements.width = 60;
//    labelTopicElements.height = 16;
//    labelTopicElements.text = "1";

    QListWidgetItem * item = new QListWidgetItem(_topic);
    ui->listWidgetTopics->addItem(item);
}

void Window::on_pushButtonUnsubscribe_clicked()
{
    string topic = ui->comboBoxSubscribeTopic->currentText().toStdString();
    const char *_topic = topic.c_str();
    subscribe->UnsubscribeTopic(NULL, _topic);
    ui->listWidgetTopics->clear();
    ui->listWidgetMessages->clear();
}

void Window::on_pushButtonStatusStart_clicked()
{
    ui->pushButtonStatusStart->setEnabled(false);
    brokerStatus->SubscribeAllTopics();
    usleep(100000);
    GetBrokerInfos();
}

void Window::on_pushButtonStatusStop_clicked()
{
    brokerStatus->UnsubscribeAllTopics();
    ui->pushButtonStatusStart->setEnabled(true);
    ui->labelVersion->setText("");
    ui->labelUptime->setText("");
    ui->labelTimestamp->setText("");
    ui->labelSubscriptions->setText("");
    ui->labelClientConnected->setText("");
    ui->labelClientDisconnected->setText("");
    ui->labelClientExpired->setText("");
    ui->labelMaxClients->setText("");
    ui->labelTotalClients->setText("");
    ui->labelMessageSent->setText("");
    ui->labelMessageReceived->setText("");
    ui->labelMessageStored->setText("");
    ui->labelBytesSent->setText("");
    ui->labelBytesReceived->setText("");
}

void Window::GetBrokerInfos(){
    cout << "Atualizando informacoes" <<  endl;
        ui->labelVersion->setText(brokerStatus->GetVersion());
        ui->labelUptime->setText(brokerStatus->GetUptime());
        ui->labelTimestamp->setText(brokerStatus->GetTimestamp());
        ui->labelSubscriptions->setText(brokerStatus->GetSubscriptions());
        ui->labelClientConnected->setText(brokerStatus->GetClientsConnected());
        ui->labelClientDisconnected->setText(brokerStatus->GetClientsDisconnected());
        ui->labelClientExpired->setText(brokerStatus->GetClientsExpired());
        ui->labelMaxClients->setText(brokerStatus->GetClientsMaximum());
        ui->labelTotalClients->setText(brokerStatus->GetClientsTotal());
        ui->labelMessageSent->setText(brokerStatus->GetMessageSent());
        ui->labelMessageReceived->setText(brokerStatus->GetMessageReceived());
        ui->labelMessageStored->setText(brokerStatus->GetMessageStored());
        ui->labelBytesSent->setText(brokerStatus->GetBytesSent());
        ui->labelBytesReceived->setText(brokerStatus->GetBytesReceived());
}

void Window::UpdateMessageList(char *_topic, char *_message, int _qos){
    QListWidgetItem * item = new QListWidgetItem(_message);
    ui->listWidgetMessages->addItem(item);
}

void Window::UpdateLogList(const char *_message){

        //    QListWidgetItem * item = new QListWidgetItem(_message);
        //    ui->listWidget->addItem(item);
        cout << "update log" << endl;
        Log *newlog = new Log(strdup(_message));
        cout << "volta depois de criar"<< endl;
        logList->AddLog(newlog);
            //    log = new Log("teste");
        //    logList->ListLogs();
        char logs[3000];
        char date[50];
        strcpy(date,newlog->GetDate());
        strcat(date, "  ");
        char message[2000];
        strcpy(message, newlog->GetMessage());
        char cat[2500];
        strcpy(cat,strcat(date, message));
        cout <<"concatenar " << cat << endl;
        strcpy(logs, cat);
        QListWidgetItem * item = new QListWidgetItem(logs);
        ui->listWidgetLogs->addItem(item);
        saveLog(&txtLogDao, newlog);
        saveLog(&csvLogDao, newlog);
        saveLog(&jsonLogDao, newlog);
}

void Window::saveLog(LogDao *_logDao, Log *_log){
    _logDao->save(_log);
}
