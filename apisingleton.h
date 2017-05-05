#ifndef APISINGLETON_H
#define APISINGLETON_H


class APISingleton
{
public:
    static APISingleton *Instance();
protected:
    APISingleton();
private:
    static APISingleton *_instance;
};

#endif // APISINGLETON_H
