#include "utils.h"

Utils::Utils()
{}

Utils::~Utils(){}

char* Utils::ConvertToChar(const void *payload){
    char buf[2000];
    memset(buf, 0, 2000*sizeof(char));
    memcpy(buf, payload, 2000*sizeof(char));
    return buf;
}
