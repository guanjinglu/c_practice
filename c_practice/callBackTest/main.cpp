#include"callback.h"
#include<iostream>
#include <string>
#include <cstring>
#include <unistd.h>

using namespace std;

void callbackFun(int hour,int min, int sec)
{
    char time_now[20];
    memset(time_now,0,20);
    if(hour>12)hour-=12;//将24小时制改为12小时制
    sprintf(time_now,"%02d/%02d/%02d",hour,min,sec);
    std::cout<<time_now<<endl;
}

int main()
{
    CCALLBACK m_callback;
    m_callback.regist_callback(callbackFun);
    while(1)
    {
        m_callback.use_callBack();
        sleep(1);
    }

    return 0;
}