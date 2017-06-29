#ifndef COMMON_H
#define COMMON_H

#include "userserver.h"

class Common
{
public:
    static  UserServer* getServerInstance();  
private:
    Common();
    static UserServer* _m_userServer;
};

#endif // COMMON_H

