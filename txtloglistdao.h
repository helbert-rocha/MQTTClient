#ifndef TXTLOGLISTDAO_H
#define TXTLOGLISTDAO_H
#include "loglistdao.h"

class TXTLogListDAO : public LogListDAO
{
public:
    TXTLogListDAO();
    ~TXTLogListDAO();
    void save(LogList *_logList);
};

#endif // TXTLOGLISTDAO_H
