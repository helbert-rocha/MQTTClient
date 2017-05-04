#ifndef TXT_H
#define TXT_H
#include "savetoformat.h"

class TXT:public SaveToFormat
{
public:
    TXT();
    ~TXT();
    void save();
};

#endif // TXT_H
