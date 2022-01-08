#include <stdio.h>

int addTwoNum(int x,int y)
{
    x=x+10;
    y=y*10;

    return x*y;
}

int calSql(int n)
{
    int result;
    result  = n*n;

    return result;
}

int main(int argc, const char * argv[])
{

    int x = 10;
    int y=2;
    int result1 = addTwoNum(x,y);
    int result2 = calSql(result1);

    printf("result1 = %d\t",result1);
    printf("result2 = %d\t",result2);

    int result3;
    result3 = result1/0;
    printf("result3  = %d\t",result3);

    return 0;
}