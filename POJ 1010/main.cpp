#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;



struct gun
{
    int len;
    bool flag;
};
gun su[70];
bool cmp(gun a,gun b)
{
    return a.len>b.len;
}

int main()
{
    int N;
    while(scanf("%d",&N)==1&&N!=0)
    {
        for(int i=0; i<70; i++)           //数组标记重置
            su[i].flag=false;
        int sumlen=0,maxlen=0;
        for(int i=0; i<N; i++)
        {
            scanf("%d",&su[i].len);
            sumlen+=su[i].len;
            maxlen=max(maxlen,su[i].len);
        }
        sort(su,su+N,cmp);
        for(int i=maxlen; i<=sumlen; i++)
        {
            int temp=i,count=N;
            if(sumlen%i==0)
            {
                for(int j=0; j<N; j++)
                    su[j].flag=true;

                for(int ci=0; ci<sumlen/i+1; ci++)
                {
                    for(int j=0; j<N; j++)
                    {
                        if(su[j].flag==true&&temp-su[j].len>=0)
                        {
                            temp=temp-su[j].len;
                            count--;
                            su[j].flag=false;
                            if(temp==0)
                            {
                                temp=i;
                                break;
                            }
                        }
                    }
                }
            }
            if(count==0)
            {
                cout<<i<<endl;
                break;
            }

        }

    }
    return 0;
}
