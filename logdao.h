#ifndef LOGDAO_H
#define LOGDAO_H
#include "log.h"
#include "iostream"
using std::cout;
using std::endl;
#include <fstream>
using std::ofstream;
using std::ios;

class LogDao
{
public:
    virtual void save(Log *_log)=0;
};

#endif // LOGDAO_H
