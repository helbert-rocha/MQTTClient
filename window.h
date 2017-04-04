#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>
#include "client.h"
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

private:
    Ui::Window *ui;
    Client *client;
};

#endif // WINDOW_H
