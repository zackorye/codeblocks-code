#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
    string a,b;
    while(cin>>a>>b)
    {
        bool flags=false;
        int j=0;
        for(int i=0;i<b.length();i++)
        {
            if(a[j]==b[i])
            {
                j++;
                if(j==a.length())
                {
                    flags=true;
                    break;
                }

            }
        }
        if(flags)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}
