#ifndef POINTGRAPH_H
#define POINTGRAPH_H
#include <iostream>
#include "graph.h"
#include "ui_window.h"
#include "window.h"
class Graph;

class PointGraph : public Graph
{
private:
    Window *win;
public:
    PointGraph();
    ~PointGraph();
    void Plot(double x, double y);
    void SetWindow(Window *_win);
    void Initialize();
    void Clear();
};

#endif // POINTGRAPH_H
