#ifndef CSVLOGDAO_H
#define CSVLOGDAO_H
#include "logdao.h"

class CSVLogDao : public LogDao
{
public:
    void save(Log *_log);
};

#endif // CSVLOGDAO_H
