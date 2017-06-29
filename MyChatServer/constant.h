#ifndef CONSTANT_H
#define CONSTANT_H

// 请求
typedef enum {
    RequestLogin = 1,               // 登入
    RequestRegister = 2,           // 注册
    RequestOnline = 3,
}RequestCode_t;

// 响应
typedef enum {
    ResponseLoginSuccess = 1,    // 登入成功
    ResponseLoginNoAccount = 2,  // 没有这个用户
    ResponseWrongPwd = 3,        // 密码错误
    ResponseHaveLogined = 4,     // 用户已登入了
    ResponseGetAllSuccess = 5,
    ResponseUserOnline = 6,      // 上线
    ResponseUserOffline = 7,     // 下线
    ResponseOfflineSuccess = 8,  // 本人下线
    ResponseRegisterExist = 9,   // 该账号已被注册了
    ResponseRegisterSuccess = 10,  // 注册成功

}ResponseCode_t;

//临时表字段
typedef enum{
    KIND = 0,
    SENDER = 1,
    RECEIVER = 2,
    TEXT = 3
}MessageType_t;

//好友类型表字段
typedef enum{
    VERIFYING = 0,
    FRIEND = 1,
    MYSELF = 5
}FriendsType_t;

typedef enum{
    MESSAGE = 1,                // 普通信息
    REQUEST_FRIEND = 2,         //请求添加好友
    AGREE_FRIEND = 3,           //同意好友请求
    DISAGREE_FRIEND = 4,        //拒绝好友请求
    END_FRIEND = 5,             //添加好友结束
    BE_DELETED = 8,             //被好友删除
    TALK_MESSAGE = 9,           //聊天信息
}AddFriendsMessage_t;

#endif // CONSTANT_H
