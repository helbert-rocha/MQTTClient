#include "log.h"
#include <iostream>
#include "date.h"
#include <string>
using std::cout;
using std::endl;
using namespace date;
using namespace std::chrono;
#include <QTime>
Log::Log(char *_message){

//    std::string s = date::format("%F %T", std::chrono::system_clock::now());
//     std::string s = date::format("%F %T", std::chrono::system_clock::now());
    const QDateTime now = QDateTime::currentDateTime();
    const QString timestamp = now.toString(QLatin1String("dd-MM-yyyy hhmmsszzz"));
    strcpy(date, timestamp.toStdString().c_str());

    cout << "time " << date << endl;
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
