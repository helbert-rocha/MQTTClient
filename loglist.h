#ifndef LOGLIST_H
#define LOGLIST_H
#include "log.h"
#include "list.h"
#include "element.h"
#include <cstdlib>

class LogList
{
private:
    List<Log> LLog;
public:
    LogList();
    ~LogList();
    void ClearList();
    void AddLog(Log *log);

    void ListLogs();
    void ListLogs2();

    void SaveLogs();
    void RecoverLogs();
};

#endif // LOGLIST_H
