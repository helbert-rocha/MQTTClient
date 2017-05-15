#ifndef POINTLOGGRAPH_H
#define POINTLOGGRAPH_H
#include <iostream>
#include "loggraph.h"
#include "ui_window.h"
#include "window.h"
class LogGraph;

class PointLogGraph : public LogGraph
{
private:
    Window *win;
public:
    PointLogGraph();
    ~PointLogGraph();
    void Plot(double x, double y);
    void SetWindow(Window *_win);
    void Initialize();
    void Clear();
};

#endif // POINTLOGGRAPH_H
