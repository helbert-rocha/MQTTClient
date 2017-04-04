#include "window.h"
#include "ui_window.h"
//#include "utils.h"
#include "client.h"
#include <iostream>

Window::Window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Window)
{
    ui->setupUi(this);
    disableComponents();
}

Window::~Window()
{
    delete ui;
}

void Window::on_pushButtonConnect_clicked()
{
    std::string address = ui->lineEditBrokerAddress->text().toStdString();
    const char *add = address.c_str();
    int port = ui->lineEditBrokerPort->text().toInt();
    std::cout << "Endereço: " << add << std::endl;
    std::cout << "Porta: " << port << std::endl;
    ui->lineEditBrokerAddress->setEnabled(false);
    ui->lineEditBrokerPort->setEnabled(false);
    ui->pushButtonConnect->setEnabled(false);
    client = new Client(NULL, NULL, add, port);
   enableComponents();
}

void Window::on_pushButtonDisconnect_clicked()
{
    ui->lineEditBrokerAddress->setEnabled(true);
    ui->lineEditBrokerPort->setEnabled(true);
    ui->pushButtonConnect->setEnabled(true);
    disableComponents();
   delete client;
}

void Window::on_pushButtonPublish_clicked()
{
    std::string topic = ui->comboBoxPublishTopic->currentText().toStdString();
    const char *_topic = topic.c_str();

    std::string message = ui->textEditMessage->toPlainText().toStdString();
    const char *_message = message.c_str();

    if (ui->radioButtonQoS0Publish->isChecked())
    {
        client->send_message(_message, _topic, 0);
    }else if(ui->radioButtonQoS1Publish->isChecked())
    {
        client->send_message(_message, _topic, 1);
    }else{
        client->send_message(_message, _topic, 2);
    }
}

void Window::enableComponents()
{
    ui->pushButtonPublish->setEnabled(true);
    ui->textEditMessage->setEnabled(true);
    ui->comboBoxPublishTopic->setEnabled(true);
    ui->radioButtonQoS0Publish->setEnabled(true);
    ui->radioButtonQoS1Publish->setEnabled(true);
    ui->radioButtonQoS2Publish->setEnabled(true);
    ui->comboBoxSubscribeTopic->setEnabled(true);
    ui->pushButtonSubscribe->setEnabled(true);
    ui->radioButtonQoS0Subscribe->setEnabled(true);
    ui->radioButtonQoS1Subscribe->setEnabled(true);
    ui->radioButtonQoS2Subscribe->setEnabled(true);
}

void Window::disableComponents()
{
    ui->pushButtonPublish->setEnabled(false);
    ui->textEditMessage->setEnabled(false);
    ui->comboBoxPublishTopic->setEnabled(false);
    ui->radioButtonQoS0Publish->setEnabled(false);
    ui->radioButtonQoS1Publish->setEnabled(false);
    ui->radioButtonQoS2Publish->setEnabled(false);
    ui->comboBoxSubscribeTopic->setEnabled(false);
    ui->pushButtonSubscribe->setEnabled(false);
    ui->radioButtonQoS0Subscribe->setEnabled(false);
    ui->radioButtonQoS1Subscribe->setEnabled(false);
    ui->radioButtonQoS2Subscribe->setEnabled(false);
}

void Window::on_pushButtonSubscribe_clicked()
{
    std::string topic = ui->comboBoxSubscribeTopic->currentText().toStdString();
    const char *_topic = topic.c_str();

    if (ui->radioButtonQoS0Subscribe->isChecked())
    {
        client->subscribe_topic(NULL, _topic, 0);
    }else if (ui->radioButtonQoS1Subscribe->isChecked())
    {
        client->subscribe_topic(NULL, _topic, 1);
    }else{
        client->subscribe_topic(NULL, _topic, 2);
    }

}
