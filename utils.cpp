#include "utils.h"
#include <iostream>
#include <stdio.h>
#include <string.h>

using std::cout;
using std::endl;


Utils::Utils()
{}

Utils::~Utils(){}

char* Utils::ConvertToChar(const void *payload){
    char buf[256];
    memset(buf, 0, 256*sizeof(char));
    memcpy(buf, payload, 255*sizeof(char));
    cout <<  "buffer " << buf << endl;
    return buf;
}
