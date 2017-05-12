#include "q0loggraph.h"

void Q0LogGraph::Plot(Log *_log){
    ui->widgetGraphQ0->addGraph();
//    ui->widgetGraphQ0->graph(0)->setData(x, y);
    // give the axes some labels:
    ui->widgetGraphQ0->xAxis->setLabel("x");
    ui->widgetGraphQ0->yAxis->setLabel("y");
    // set axes ranges, so we see all data:
    ui->widgetGraphQ0->xAxis->setRange(-1, 1);
    ui->widgetGraphQ0->yAxis->setRange(0, 1);
    ui->widgetGraphQ0->replot();
}

void Q0LogGraph::SetWindow(Ui::Window *_window){
    ui = _window;
}
