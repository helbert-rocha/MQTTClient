#ifndef UTILS_H
#define UTILS_H
#include <stdio.h>
#include <string.h>

class Utils
{
public:
    Utils();
    ~Utils();
    static char *ConvertToChar(const void *payload);
};

#endif // UTILS_H
