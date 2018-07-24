#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int p,e,i,d,count=1;
    while(scanf("%d%d%d%d",&p,&e,&i,&d)==4)
    {
        if(p<0||e<0||i<0||d<0)
            break;
        int t;
        p%=23;
        e%=28;
        i%=33;
        t=max(p,e);
        t=max(t,i);
        t=max(t,d);
        if(t<=d)
            t++;
        do
        {
            if((t-p)%23==0&&(t-e)%28==0&&(t-i)%33==0)
                break;
        }
        while(t++);
        printf("Case %d: the next triple peak occurs in %d days.\n",count++,t-d);
    }

    return 0;
}
