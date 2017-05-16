#include "pointgraph.h"

PointGraph::PointGraph()
{

}

PointGraph::~PointGraph()
{

}

void PointGraph::Plot(double x, double y){
    qv_x.append(x);
    qv_y.append(y);
    win->ui->widgetGraph1->graph(0)->setData(qv_x, qv_y);
    win->ui->widgetGraph1->rescaleAxes();
    win->ui->widgetGraph1->replot();
}

void PointGraph::SetWindow(Window *_win)
{
    win = _win;
    Initialize();

}

void PointGraph::Initialize()
{
    win->ui->widgetGraph1->addGraph();
    win->ui->widgetGraph1->graph(0)->setScatterStyle(QCPScatterStyle::ssCircle);
    win->ui->widgetGraph1->graph(0)->setLineStyle(QCPGraph::lsNone);
    win->ui->widgetGraph1->xAxis->setLabel("Tempo milissegundos");
    win->ui->widgetGraph1->yAxis->setLabel("Bytes");
//    ui->widgetGraph1->xAxis->setRange(0, 50);
//    ui->widgetGraph1->yAxis->setRange(0, 50);
//    QLinearGradient gradient(0, 0, 0, 400);
//    gradient.setColorAt(0, QColor(150, 150, 150));
//    gradient.setColorAt(0.38, QColor(200, 200, 200));
//    gradient.setColorAt(1, QColor(130, 130, 130));
//     win->ui->widgetGraph1->setBackground(QBrush(gradient));
}

void PointGraph::Clear()
{
    qv_x.clear();
    qv_y.clear();
    win->ui->widgetGraph1->clearItems();
    win->ui->widgetGraph1->rescaleAxes();
    win->ui->widgetGraph1->replot();
}


