#ifndef LINESLOGGRAPH_H
#define LINESLOGGRAPH_H
#include "ui_window.h"
#include "window.h"
#include "loggraph.h"
class LogGraph;


class LinesLogGraph : public LogGraph
{
private:
    Window *win;
public:
    LinesLogGraph();
    ~LinesLogGraph();
    void Initialize();
    void Plot(double x, double y);
    void Clear();
    void setWindow(Window *win);
};

#endif // LINESLOGGRAPH_H
