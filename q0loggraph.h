#ifndef Q0LOGGRAPH_H
#define Q0LOGGRAPH_H

#include "loggraph.h"
#include "ui_window.h"
#include "window.h"

class Q0LogGraph : public LogGraph
{
private:
    Ui::Window *ui;
public:
    void Plot(Log *_log);
    void SetWindow(Ui::Window *_window);
};

#endif // Q0LOGGRAPH_H
