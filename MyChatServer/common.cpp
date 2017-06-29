#include "common.h"
#include "userserver.h"

UserServer* Common::_m_userServer = NULL;

UserServer *Common::getServerInstance()
{
    if (_m_userServer == NULL) {
        _m_userServer = new UserServer;
    }
    return _m_userServer;
}

Common::Common()
{
}
