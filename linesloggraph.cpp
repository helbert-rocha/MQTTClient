#include "linesloggraph.h"
using std::cout;
using std::endl;


LinesLogGraph::LinesLogGraph()
{

}

LinesLogGraph::~LinesLogGraph()
{

}

void LinesLogGraph::Initialize()
{
    win->ui->widgetGraph3->addGraph();
    win->ui->widgetGraph3->graph(0)->setScatterStyle(QCPScatterStyle::ssDisc);
    win->ui->widgetGraph3->graph(0)->setLineStyle(QCPGraph::lsLine);
    win->ui->widgetGraph3->xAxis->setLabel("Tempo milisegundos");
    win->ui->widgetGraph3->yAxis->setLabel("Bytes");
}

void LinesLogGraph::Plot(double x, double y)
{
    qv_x.append(x);
    qv_y.append(y);
    win->ui->widgetGraph3->graph(0)->setData(qv_x, qv_y);
    win->ui->widgetGraph3->rescaleAxes();
    win->ui->widgetGraph3->replot();
}

void LinesLogGraph::Clear()
{
    qv_x.clear();
    qv_y.clear();
    win->ui->widgetGraph3->clearItems();
    win->ui->widgetGraph3->rescaleAxes();
    win->ui->widgetGraph3->replot();
}

void LinesLogGraph::setWindow(Window *_win)
{
    win = _win;
    Initialize();
}



