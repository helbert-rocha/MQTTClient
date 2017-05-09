#include "txtloglistdao.h"
#include <fstream>
#include <iostream>
using std::ofstream;
using std::cout;
using std::endl;
using std::ios;
TXTLogListDAO::TXTLogListDAO()
{}
TXTLogListDAO::~TXTLogListDAO(){}

void TXTLogListDAO::save(LogList *_logList){

    cout << "salvando txt" << endl;
    ofstream SaveList("/Users/helbert/Desktop/loglist.txt", ios::out);
    if (!SaveList )
     {
        cout << " Arquivo não pode ser aberto " << endl;
        fflush (stdin);
        getchar();
     return;
     }

    SaveList << "testando salvamento" << endl;

    SaveList.close();
}
