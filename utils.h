#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <sstream>
#include <cstddef>
#include <string>

using std::string;
class Utils
{
public:
    Utils();
    ~Utils();
    static char *ConvertToChar(const void *payload);
    static int GetPayloadSize(string message);
};

#endif // UTILS_H
