#ifndef JSONLOGDAO_H
#define JSONLOGDAO_H
#include <logdao.h>
#include <log.h>
#include <json/writer.h>

class JsonLogDao : public LogDao
{
public:
   void save(Log *_log);
};

#endif // JSONLOGDAO_H
