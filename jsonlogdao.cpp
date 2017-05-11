#include "jsonlogdao.h"

void JsonLogDao::save(Log *_log){

    cout << "salvando log txt" << endl;
    Json::FastWriter writer;
    ofstream SaveList("/Users/helbert/Desktop/loglist.json", ios::out | ios::app);
    if (!SaveList )
     {
        cout << " Arquivo não pode ser aberto " << endl;
        fflush (stdin);
        getchar();
     return;
     }

    Json::Value value;
    value["log"]["date"] = _log->GetDate();
    value["log"]["message"] = _log->GetMessage();

    SaveList << writer.write(value);

    SaveList.close();
}
