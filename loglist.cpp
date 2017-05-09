#include "loglist.h"
#include <ctime>
#include <iostream>
#include <fstream>
using std::cout;
using std::endl;
using std::ofstream;
using std::ios;
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
    cout << "salvando txt" << endl;
    ofstream SaveList("/Users/helbert/Desktop/loglist.txt", ios::out);
    if (!SaveList )
     {
        cout << " Arquivo não pode ser aberto " << endl;
        fflush (stdin);
        getchar();
     return;
     }

    Element<Log>* pEIAux = NULL;
    Log* pLLAux = NULL;
    pEIAux = LLog.getFirst();
    cout << "Salvando lista" << endl;
    while(NULL != pEIAux)
    {
        cout << "entrou no while da lista" << endl;
        pLLAux = pEIAux->getInfo();
        SaveList << pLLAux->GetDate() << "  " << pLLAux->GetMessage() << endl;
        pEIAux = pEIAux->getNext();
    }
    SaveList.close();
//csv
//    ofstream myfile;
//          myfile.open ("example.csv");
//          myfile << "This is the first cell in the first column.\n";
//          myfile << "a,b,c,\n";
//          myfile << "c,s,v,\n";
//          myfile << "1,2,3.456\n";
//          myfile << "semi;colon";
//          myfile.close();
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
