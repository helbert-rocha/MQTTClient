#include "utils.h"
#include <string.h>

Utils::Utils()
{

}
Utils::ConvertToChar(std::string text)
{
    std::string str = text;
    const char *textConverted = str.c_str();
    return textConverted;
}
