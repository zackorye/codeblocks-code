#include<string>
#include<iostream>
#include<iosfwd>
#include<cmath>
#include<cstring>
#include<stdlib.h>
#include<stdio.h>
#include<cstring>
using namespace std;

int dig[150];

int main()
{
    char c[8];
    int m;
    while(cin>>c>>m)
    {
        memset(dig,0,sizeof(dig));
        int count=0,n=0;
        int len=strlen(c);
        for(int i=0;i<len;i++)
        {
            if(isdigit(c[i]))
            {
                n=n*10+(c[i]-48);
            }
            else
                count=i;
        }
        int truelen=len;
        for(int i=0;i<truelen;i++)
        {
            if(n%10==0)
            {
                n/=10;
                len--;
            }
            else
                break;
            if(len==count+1)
                break;
        }
        len--;
        dig[0]=1;
        for(int i=0;i<m;i++)
        {
            int temp=n;
            int j=0;
            while(temp||j<150)
            {
                if(j==0)
                    temp=n*dig[j];
                else
                {
                    temp=n*dig[j]+temp;
                }
                dig[j++]=temp%10;
                temp/=10;
            }
        }
        bool flag=false;
        for(int i=149;i>=0;i--)
        {
            if(dig[i]!=0||i+1==(len-count)*m)
            {
                if((len-count)*m==i+1)
                    cout<<'.';
                flag=true;
            }
            if(flag)
                cout<<dig[i];
        }
        cout<<endl;
    }
    return 0;
}
