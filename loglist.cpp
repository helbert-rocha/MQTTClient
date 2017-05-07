#include "loglist.h"
#include <ctime>
#include <iostream>
using std::cout;
using std::endl;

LogList::LogList()
{}
LogList::~LogList()
{}

void LogList::ClearList(){
    LLog.clear();
}

void LogList::AddLog(Log *log){
    if (NULL != log){
        LLog.addInfo(log);
    }else{
        cout << "Erro! log não incluido." << endl;
    }
}

void LogList::SaveLogs(){

}

void LogList::RecoverLogs()
{

}

void LogList::ListLogs(){
    Element<Log>* pEIAux = NULL;
    Log* pLLAux = NULL;

    while(NULL != pEIAux)
    {
        pLLAux = pEIAux->getInfo();
        cout << "Data " << pLLAux->GetMessage() << "Log " << pLLAux->GetMessage() << endl;
    }
}
