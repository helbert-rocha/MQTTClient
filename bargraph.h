#ifndef BARGRAPH_H
#define BARGRAPH_H
#include "ui_window.h"
#include "window.h"
#include "graph.h"
class Graph;

class BarGraph : public Graph
{
private:
    Window *win;
public:
    BarGraph();
    ~BarGraph();
    void Initialize();
    void Plot(double x, double y);
    void Clear();
    void SetWindow(Window *win);
};

#endif // BARGRAPH_H
