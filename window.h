#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>
#include "publish.h"
#include "subscribe.h"

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

private:
    Ui::Window *ui;
    Publish *publish;
    Subscribe *subscribe;

    void EnableComponents();
    void DisableComponents();
    void EnableConnectComponents();
    void DisableConnectComponents();

};

#endif // WINDOW_H
