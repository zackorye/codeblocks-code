#include <iostream>
#include <cstring>
using namespace std;
char s[85];
int main()
{
    int N;
    cin>>N;
    for(int i=0; i<N; i++)
    {
        cin>>s;
        int len=strlen(s);
        bool flag;
        for(int j=1; j<=len; j++)
        {

            if(len%j==0)
            {
                flag=true;
                for(int k=0; k<len-j; k++)
                {
                    if(s[k]!=s[k+j])
                    {
                        flag=false;
                    }
                }
            }

            if(flag)
            {
                cout<<j<<endl;
                break;
            }
            else if(j==len)
            {
                cout<<len<<endl;
            }

        }
        if(i<N-1)
            cout<<endl;
    }
    return 0;
}
