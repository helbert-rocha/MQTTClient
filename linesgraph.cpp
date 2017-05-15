#include "linesgraph.h"
using std::cout;
using std::endl;


LinesGraph::LinesGraph()
{

}

LinesGraph::~LinesGraph()
{

}

void LinesGraph::Initialize()
{
    win->ui->widgetGraph3->addGraph();
    win->ui->widgetGraph3->graph(0)->setScatterStyle(QCPScatterStyle::ssDisc);
    win->ui->widgetGraph3->graph(0)->setLineStyle(QCPGraph::lsLine);
    win->ui->widgetGraph3->xAxis->setLabel("Tempo milisegundos");
    win->ui->widgetGraph3->yAxis->setLabel("Bytes");
}

void LinesGraph::Plot(double x, double y)
{
    qv_x.append(x);
    qv_y.append(y);
    win->ui->widgetGraph3->graph(0)->setData(qv_x, qv_y);
    win->ui->widgetGraph3->rescaleAxes();
    win->ui->widgetGraph3->replot();
}

void LinesGraph::Clear()
{
    qv_x.clear();
    qv_y.clear();
    win->ui->widgetGraph3->clearItems();
    win->ui->widgetGraph3->rescaleAxes();
    win->ui->widgetGraph3->replot();
}

void LinesGraph::setWindow(Window *_win)
{
    win = _win;
    Initialize();
}



