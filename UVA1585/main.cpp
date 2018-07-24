#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    int N,count,sum;
    char c[85];
    cin>>N;
    for(int i=0;i<N;i++)
    {
        cin>>c;count=0;sum=0;
        int len=strlen(c);
        for(int j=0;j<len;j++)
        {
            if(c[j]=='O')
                sum+=++count;
            else
                count=0;
        }
        cout<<sum<<endl;
    }
    return 0;
}
