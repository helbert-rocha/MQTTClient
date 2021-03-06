#include "bargraph.h"

BarGraph::BarGraph()
{

}

BarGraph::~BarGraph()
{

}

void BarGraph::Initialize()
{
    win->ui->widgetGraph2->addGraph();
    win->bar = new QCPBars(win->ui->widgetGraph2->xAxis, win->ui->widgetGraph2->yAxis);
    win->ui->widgetGraph2->xAxis->setLabel("Tempo milissegundos");
    win->ui->widgetGraph2->yAxis->setLabel("Bytes");
}

void BarGraph::Plot(double x, double y)
{
    qv_x.append(x);
    qv_y.append(y);
    win->bar->setData(qv_x, qv_y);
    win->ui->widgetGraph2->rescaleAxes();
    win->ui->widgetGraph2->replot();
}

void BarGraph::Clear()
{
    qv_x.clear();
    qv_y.clear();
    win->ui->widgetGraph2->clearItems();
    win->ui->widgetGraph2->rescaleAxes();
    win->ui->widgetGraph2->replot();
}

void BarGraph::SetWindow(Window *_win)
{
    win = _win;
    Initialize();
}
