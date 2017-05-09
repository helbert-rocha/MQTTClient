#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>
#include "publish.h"
#include "subscribe.h"
#include "brokerstatus.h"
#include <stdlib.h>
#include "mosquittoapi.h"
#include "log.h"
#include "loglist.h"

class Publish;
class Subscribe;
class BrokerStatus;

namespace Ui {
class Window;
}

class Window : public QMainWindow
{
    Q_OBJECT

public:
     explicit Window(QWidget *parent = 0);
    ~Window();
    void GetBrokerInfos();
    void UpdateMessageList(char *_topic, char *_message, int _qos);
    void UpdateLogList(const char *_message);
private slots:
    void on_pushButtonConnect_clicked();

    void on_pushButtonDisconnect_clicked();

    void on_pushButtonPublish_clicked();

    void on_pushButtonSubscribe_clicked();

    void on_pushButtonUnsubscribe_clicked();

    void on_pushButtonStatusStart_clicked();

    void on_pushButtonStatusStop_clicked();

    void on_pushButtonSaveLogTxt_clicked();

private:
    Ui::Window *ui;
    Publish *publish;
    Subscribe *subscribe;
    BrokerStatus *brokerStatus;
    MosquittoAPI *mosquittoAPI;
    LogList *logList;
    int login = 0;
    const char *_host;
    int _port;

    void EnableComponents();
    void DisableComponents();
    void EnableConnectComponents();
    void DisableConnectComponents();

};

#endif // WINDOW_H
