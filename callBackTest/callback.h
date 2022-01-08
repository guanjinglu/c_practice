#ifndef __CALLBACK_H__
#define __CALLBACK_H__
typedef void(*callBack)(int hour,int min, int sec);

struct REAL_TIME{
    int hour;
    int min;
    int sec;
};

class CCALLBACK{
public:
    callBack p_cb;
public:
    CCALLBACK();
    ~CCALLBACK();
    void use_callBack();
    void regist_callback(callBack cb);
};


#endif