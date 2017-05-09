#include "txtlogdao.h"

void TXTLogDao::save(Log *_log){
    cout << "salvando log txt" << endl;
    ofstream SaveList("/Users/helbert/Desktop/loglist.txt", ios::out | ios::app);
    if (!SaveList )
     {
        cout << " Arquivo não pode ser aberto " << endl;
        fflush (stdin);
        getchar();
     return;
     }

    SaveList << _log->GetDate() << " " << _log->GetMessage() << endl;

    SaveList.close();
}
