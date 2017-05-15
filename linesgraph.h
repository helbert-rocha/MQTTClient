#ifndef LINESGRAPH_H
#define LINESGRAPH_H
#include "ui_window.h"
#include "window.h"
#include "graph.h"
class Graph;


class LinesGraph : public Graph
{
private:
    Window *win;
public:
    LinesGraph();
    ~LinesGraph();
    void Initialize();
    void Plot(double x, double y);
    void Clear();
    void setWindow(Window *win);
};

#endif // LINESGRAPH_H
