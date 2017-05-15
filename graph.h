#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include "qcustomplot.h"
//#include "window.h"
//#include "ui_window.h"
//class Window;

class Graph
{
protected:
//   Ui::Window *ui;
    QVector<double> qv_x, qv_y;
public:
    virtual void Plot(double x, double y)=0;
//    void SetWindow(Ui::Window *_window);
};

#endif // GRAPH_H
