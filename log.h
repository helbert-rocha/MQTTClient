#ifndef LOG_H
#define LOG_H


class Log
{
private:
    char date[50];
    char message[500];
public:
    Log();
    ~Log();

    char* GetDate();
    char* GetMessage();
};

#endif // LOG_H
