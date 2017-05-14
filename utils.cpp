#include "utils.h"


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

int Utils::GetPayloadSize(string message)
{
    size_t last_index = message.find_last_of("/((");
    string result = message.substr(last_index+1);
    std::istringstream iss(result);
    int payload;
    iss >> payload;
    return payload;
}
