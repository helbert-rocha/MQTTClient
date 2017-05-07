#include "log.h"

Log::Log(){}

Log::~Log(){}

char* Log::GetDate()
{
    return date;
}

char* Log::GetMessage()
{
    return message;
}
