#ifndef BARLOGGRAPH_H
#define BARLOGGRAPH_H
#include "ui_window.h"
#include "window.h"
#include "loggraph.h"
class LogGraph;

class BarLogGraph : public LogGraph
{
private:
    Window *win;
public:
    BarLogGraph();
    ~BarLogGraph();
    void Initialize();
    void Plot(double x, double y);
    void Clear();
    void SetWindow(Window *win);
};

#endif // BARLOGGRAPH_H
