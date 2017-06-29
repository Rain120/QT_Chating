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
#endif // CONSTANT_H
