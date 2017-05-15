#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>
#include <stdlib.h>
#include "publish.h"
#include "subscribe.h"
#include "brokerstatus.h"
#include "mosquittoapi.h"
#include "log.h"
#include "logdao.h"
#include "txtlogdao.h"
#include "csvlogdao.h"
#include "jsonlogdao.h"
#include "graph.h"
#include "pointgraph.h"
#include "bargraph.h"
#include "linesgraph.h"

class Publish;
class Subscribe;
class BrokerStatus;
class Graph;
class PointGraph;
class BarGraph;
class LinesGraph;
class Log;

namespace Ui {
class Window;
}

class Window : public QMainWindow
{
    Q_OBJECT

public:
     explicit Window(QWidget *parent = 0);
    Ui::Window *ui;
    QCPBars *bar;
    ~Window();
    void GetBrokerInfos();
    void UpdateMessageList(char *_topic, char *_message, int _qos);
    void UpdateLogList(Log *log);
private slots:
    void on_pushButtonConnect_clicked();

    void on_pushButtonDisconnect_clicked();

    void on_pushButtonPublish_clicked();

    void on_pushButtonSubscribe_clicked();

    void on_pushButtonUnsubscribe_clicked();

    void on_pushButtonStatusStart_clicked();

    void on_pushButtonStatusStop_clicked();


private:
    Publish *publish;
    Subscribe *subscribe;
    BrokerStatus *brokerStatus;
    MosquittoAPI *mosquittoAPI;
    Graph *graph;
    PointGraph *pointGraph;
    BarGraph *barGraph;
    LinesGraph *linesGraph;
    int qos;
    int payload;
    const char *_host;
    int _port;
    QDateTime timeSend;
    QDateTime timeReceive;
//    void saveLog(LogDao *logDao, Log *_log);
    void Initialize();
    void EnableComponents();
    void DisableComponents();
    void EnableConnectComponents();
    void DisableConnectComponents();
    void UpdateGraph(double x, double y, Graph *graph);
};

#endif // WINDOW_H
