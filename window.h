#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>
#include "publish.h"
#include "subscribe.h"
#include "brokerstatus.h"
#include <stdlib.h>

namespace Ui {
class Window;
}

class Window : public QMainWindow
{
    Q_OBJECT

public:
    explicit Window(QWidget *parent = 0);
    ~Window();
private slots:
    void on_pushButtonConnect_clicked();

    void on_pushButtonDisconnect_clicked();

    void on_pushButtonPublish_clicked();

    void on_pushButtonSubscribe_clicked();

    void on_pushButtonUnsubscribe_clicked();

    void on_pushButtonStatusStart_clicked();

    void on_pushButtonStatusStop_clicked();

    void on_pushButtonReload_clicked();

private:
    Ui::Window *ui;
    Publish *publish;
    Subscribe *subscribe;
    BrokerStatus *brokerStatus;
    const char *_host;
    int _port;

    void EnableComponents();
    void DisableComponents();
    void EnableConnectComponents();
    void DisableConnectComponents();
    void GetBrokerInfos();
    void UpdateList(const mosquitto_message *message);


};

#endif // WINDOW_H
