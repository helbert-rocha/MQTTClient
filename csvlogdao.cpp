#include "csvlogdao.h"

void CSVLogDao::save(Log *_log){

    cout << "salvando log csv" << endl;
    ofstream SaveList("/Users/helbert/Desktop/loglist.csv", ios::out | ios::app);
    if (!SaveList )
     {
        cout << " Arquivo não pode ser aberto " << endl;
        fflush (stdin);
        getchar();
     return;
     }

    SaveList << _log->GetDate() << ";" << _log->GetMessage() << endl;

    SaveList.close();
}

