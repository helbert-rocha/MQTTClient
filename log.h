#ifndef LOG_H
#define LOG_H
#include <string.h>
class Log
{
private:
    char date[50];
    char message[500];
public:
    Log(char* message);
    Log();
    ~Log();
    char* GetDate();
    char* GetMessage();
};

#endif // LOG_H
