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
}

Window::~Window()
{
    delete ui;
}

void Window::on_pushButtonConnect_clicked()
{
    std::cout << "Tentando conectar" << std::endl;
    std::string address = ui->lineEditBrokerAddress->text().toStdString();
    const char *add = address.c_str();
    int port = ui->lineEditBrokerPort->text().toInt();
    std::cout << "Endereço: " << add << std::endl;
    std::cout << "Porta: " << port << std::endl;
    ui->lineEditBrokerAddress->setEnabled(false);
    ui->lineEditBrokerPort->setEnabled(false);
    ui->pushButtonConnect->setEnabled(false);
    client = new Client(NULL, NULL, add, port);
}

void Window::on_pushButtonDisconnect_clicked()
{
    ui->lineEditBrokerAddress->setEnabled(true);
    ui->lineEditBrokerPort->setEnabled(true);
    ui->pushButtonConnect->setEnabled(true);
   delete client;
}
