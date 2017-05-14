#include "window.h"
#include "ui_window.h"
#include <iostream>
#include <unistd.h>
#include <string.h>
#include <list.h>
#include "logdao.h"
#include "txtlogdao.h"
using std::cout;
using std::endl;
using std::string;
#include <QTime>

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
   Initialize();

}

void Window::on_pushButtonDisconnect_clicked()
{
    mosquittoAPI->disconnect();
//    brokerStatus->disconnect();
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

void Window::UpdateGraph(double x, double y, LogGraph *logGraph)
{
    logGraph->Plot(x, y);
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

    QListWidgetItem * item = new QListWidgetItem(_topic);
    ui->listWidgetTopics->addItem(item);
    ui->pushButtonSubscribe->setEnabled(false);
}

void Window::on_pushButtonUnsubscribe_clicked()
{
    string topic = ui->comboBoxSubscribeTopic->currentText().toStdString();
    const char *_topic = topic.c_str();
    subscribe->UnsubscribeTopic(NULL, _topic);
    ui->listWidgetTopics->clear();
    ui->listWidgetMessages->clear();
    ui->pushButtonSubscribe->setEnabled(true);
    pointLogGraph->Clear();
    barLogGraph->Clear();
    linesLogGraph->Clear();
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
    const QDateTime now = QDateTime::currentDateTime();
    const QString timestamp = now.toString(QLatin1String("dd-MM-yyyy hhmmsszzz"));
    char date[50];
    char messages[2000];
    strcpy(date, timestamp.toStdString().c_str());
    strcat(date, " ");
    strcpy(messages, strcat(date, _message));
    QListWidgetItem * item = new QListWidgetItem(messages);
    ui->listWidgetMessages->addItem(item);
}

void Window::UpdateLogList(const char *_message){

    cout << "update log" << endl;
    Log *newlog = new Log(strdup(_message));
    logList->AddLog(newlog);
    char logs[3000];
    char date[50];
    strcpy(date,newlog->GetDate());
    strcat(date, "  ");
    char message[2000];
    strcpy(message, newlog->GetMessage());
    char cat[2500];
    strcpy(cat,strcat(date, message));
    strcpy(logs, cat);
    QListWidgetItem * item = new QListWidgetItem(logs);
    ui->listWidgetLogs->addItem(item);
    saveLog(&txtLogDao, newlog);
    saveLog(&csvLogDao, newlog);
    saveLog(&jsonLogDao, newlog);

    int qos0 = strstr(newlog->GetMessage(), "q0") != NULL;
    int qos1 = strstr(newlog->GetMessage(), "q1") != NULL;
    int qos2 = strstr(newlog->GetMessage(), "q2") != NULL;
    int sendPub = strstr(newlog->GetMessage(), "sending PUBLISH") != NULL;
    int getRec = strstr(newlog->GetMessage(), "received PUBLISH") != NULL;
    int sendPuback = strstr(newlog->GetMessage(), "sending PUBACK") != NULL;
    int sendPubcomp = strstr(newlog->GetMessage(), "sending PUBCOMP") != NULL;

    if(sendPub == 1){
        timeSend = QDateTime::fromString(newlog->GetDate(),QLatin1String("dd-MM-yyyy hhmmsszzz"));
        payload = Utils::GetPayloadSize(newlog->GetMessage());
        if (qos0 == 1){
            qos = 0;
        }else if (qos1 == 1){
            qos = 1;
        }else if (qos2 == 1){
            qos = 2;
        }
        sendPub = 0;
    }else if(getRec == 1 && qos == 0){
        timeReceive = QDateTime::fromString(newlog->GetDate(),QLatin1String("dd-MM-yyyy hhmmsszzz"));
        cout << ">>>>>> resultado payload " << payload << endl;
        cout << "converter para date" << timeSend.time().msecsTo(timeReceive.time()) <<endl;
        UpdateGraph((double) timeSend.time().msecsTo(timeReceive.time()), payload, pointLogGraph);
        UpdateGraph((double) timeSend.time().msecsTo(timeReceive.time()), payload, barLogGraph);
        UpdateGraph((double) timeSend.time().msecsTo(timeReceive.time()), payload, linesLogGraph);
    } else if(sendPuback == 1 && qos == 1){
        timeReceive = QDateTime::fromString(newlog->GetDate(),QLatin1String("dd-MM-yyyy hhmmsszzz"));
         cout << ">>>>>> resultado payload " << payload << endl;
         cout << "converter para date" << timeSend.time().msecsTo(timeReceive.time()) <<endl;
         UpdateGraph((double) timeSend.time().msecsTo(timeReceive.time()), payload, pointLogGraph);
         UpdateGraph((double) timeSend.time().msecsTo(timeReceive.time()), payload, barLogGraph);
         UpdateGraph((double) timeSend.time().msecsTo(timeReceive.time()), payload, linesLogGraph);
         sendPuback = 0;
    }else if(sendPubcomp == 1 && qos == 2){
        timeReceive = QDateTime::fromString(newlog->GetDate(),QLatin1String("dd-MM-yyyy hhmmsszzz"));
         cout << ">>>>>> resultado payload " << payload << endl;
         cout << "converter para date" << timeSend.time().msecsTo(timeReceive.time()) <<endl;
         UpdateGraph((double) timeSend.time().msecsTo(timeReceive.time()), payload, pointLogGraph);
         UpdateGraph((double) timeSend.time().msecsTo(timeReceive.time()), payload, barLogGraph);
         UpdateGraph((double) timeSend.time().msecsTo(timeReceive.time()), payload, linesLogGraph);
         sendPubcomp = 0;
    }
}

void Window::saveLog(LogDao *_logDao, Log *_log){
    _logDao->save(_log);
}

void Window::Initialize()
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
    brokerStatus = new BrokerStatus();
    brokerStatus->SetWindow(this);
    brokerStatus->SetMosquittoAPI(mosquittoAPI);
    mosquittoAPI->SetBrokerStatus(brokerStatus);
    Log *log = new Log("Start the program");
    logList = new LogList();
    logList->AddLog(log);
    pointLogGraph = new PointLogGraph();
    pointLogGraph->SetWindow(this);
    barLogGraph = new BarLogGraph();
    barLogGraph->SetWindow(this);
    linesLogGraph = new LinesLogGraph();
    linesLogGraph->setWindow(this);
    EnableComponents();
}



