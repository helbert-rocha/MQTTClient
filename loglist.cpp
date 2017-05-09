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
        cout << "Adicionar Log" << endl;
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
    pEIAux = LLog.getFirst();
    cout << "correndo lista" << endl;
    while(NULL != pEIAux)
    {
        cout << "entrou no while da lista" << endl;
        pLLAux = pEIAux->getInfo();
        cout << "Data " << pLLAux->GetDate() << "Log " << pLLAux->GetMessage() << endl;
        pEIAux = pEIAux->getNext();
    }
}

void LogList::ListLogs2(){
    Element<Log>* pEIAux = NULL;
    Log* pLLAux = NULL;
    pEIAux = LLog.getCurrent();

    while(NULL!=NULL){
        pLLAux = pEIAux->getInfo();
        cout << "Data " << pLLAux->GetDate() << "Log " <<  pLLAux->GetMessage() << endl;
        pEIAux = pEIAux->getPrev();
    }
}
