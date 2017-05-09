#ifndef LOGLISTDAO_H
#define LOGLISTDAO_H
#include "loglist.h"
class LogListDAO
{
protected:
    char paht[100];
public:
    virtual void save(LogList *_logList) = 0;
};
#endif // LOGLISTDAO_H
