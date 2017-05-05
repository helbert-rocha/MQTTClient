#include "apisingleton.h"

APISingleton* APISingleton::_instance = 0;

APISingleton* APISingleton::Instance()
{
    if(_instance == 0){
        _instance = new APISingleton;
    }
    return _instance;
}
