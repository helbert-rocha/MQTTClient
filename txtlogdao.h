#ifndef TXTLOGDAO_H
#define TXTLOGDAO_H
#include "logdao.h"

class TXTLogDao : public LogDao
{
public:
    void save(Log *_log);
};

#endif // TXTLOGDAO_H
