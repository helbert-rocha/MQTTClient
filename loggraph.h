#ifndef LOGGRAPH_H
#define LOGGRAPH_H
#include "log.h"
#include <iostream>
#include "qcustomplot.h"
//#include "window.h"
//#include "ui_window.h"

//class Window;

class LogGraph
{
protected:
//   Ui::Window *ui;
public:
    virtual void Plot(Log *_log)=0;
//    void SetWindow(Ui::Window *_window);
};

#endif // LOGGRAPH_H
