#include "log.h"
#include <iostream>
#include "date.h"
#include <string>
using std::cout;
using std::endl;
using namespace date;
using namespace std::chrono;
Log::Log(char *_message){

    std::string s = date::format("%F %T", std::chrono::system_clock::now());
    strcpy(date, s.c_str());
    cout << "time " << s << endl;
    cout << "string " << _message << endl;
    strcpy(message, _message);
}

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
