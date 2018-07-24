#include <iostream>
#include <string.h>
#include<ctype.h>
#include <stdio.h>
using namespace std;

int main()
{
    int N,count;
    double sum,fen;
    char c[85];
    cin>>N;
    for(int i=0;i<N;i++)
    {
        cin>>c;
        sum=0;
        count=0;
        fen=0;
        int len=strlen(c);
        for(int j=0;j<len;j++)
        {
            if(isalpha(c[j]))
            {
                if(c[j]=='C')
                    fen=12.01;
                else if(c[j]=='H')
                    fen=1.008;
                else if(c[j]=='O')
                    fen=16.00;
                else if(c[j]=='N')
                    fen=14.01;


            }
            else
            {
                count=count*10+(c[j]-48);
            }
            if(j<len-1&&isalpha(c[j+1]))
            {
                if(count==0)
                {
                    sum+=fen;
                }
                else
                {
                    sum+=fen*count;
                    count=0;
                }
            }
            else if(j==len-1)
            {
                if(count==0)
                {
                    sum+=fen;
                }
                else
                    sum+=fen*count;
            }
        }
        printf("%.3f\n",sum);
    }
    return 0;
}
