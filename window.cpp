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
    ui->pushButtonPublish->setEnabled(false);
    ui->textEditMessage->setEnabled(false);
    ui->comboBoxTopic->setEnabled(false);
    ui->radioButtonQoS0->setEnabled(false);
    ui->radioButtonQoS1->setEnabled(false);
    ui->radioButtonQoS2->setEnabled(false);
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
    ui->pushButtonPublish->setEnabled(true);
    ui->textEditMessage->setEnabled(true);
    ui->comboBoxTopic->setEnabled(true);
    ui->radioButtonQoS0->setEnabled(true);
    ui->radioButtonQoS1->setEnabled(true);
    ui->radioButtonQoS2->setEnabled(true);
}

void Window::on_pushButtonDisconnect_clicked()
{
    ui->lineEditBrokerAddress->setEnabled(true);
    ui->lineEditBrokerPort->setEnabled(true);
    ui->pushButtonConnect->setEnabled(true);
    ui->pushButtonPublish->setEnabled(false);
    ui->textEditMessage->setEnabled(false);
    ui->comboBoxTopic->setEnabled(false);
    ui->radioButtonQoS0->setEnabled(false);
    ui->radioButtonQoS1->setEnabled(false);
    ui->radioButtonQoS2->setEnabled(false);
   delete client;
}

void Window::on_pushButtonPublish_clicked()
{
    std::string topic = ui->comboBoxTopic->currentText().toStdString();
    const char *_topic = topic.c_str();

    std::string message = ui->textEditMessage->toPlainText().toStdString();
    const char *_message = message.c_str();

    if (ui->radioButtonQoS0->isChecked())
    {
        client->send_message(_message, _topic, 0);
    }else if(ui->radioButtonQoS1->isChecked())
    {
        client->send_message(_message, _topic, 1);
    }else{
        client->send_message(_message, _topic, 2);
    }
}
