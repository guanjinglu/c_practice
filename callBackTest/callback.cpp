#include"callback.h"
#include<time.h>

CCALLBACK::CCALLBACK(){}
CCALLBACK::~CCALLBACK(){}
void CCALLBACK::regist_callback(callBack cb)
{
    p_cb = cb;
}

void CCALLBACK::use_callBack()
{
    //获取当前的时间
    time_t now = time(0);
    tm *ltm = localtime(&now);
    //回调函数
    p_cb(ltm->tm_hour,ltm->tm_min,ltm->tm_sec);
}
