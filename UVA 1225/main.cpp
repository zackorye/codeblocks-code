#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int a[10];

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        memset(a,0,sizeof(a));
        int N;
        cin>>N;
        for(int j=1;j<=N;j++)
        {
            int temp=j;
            while(temp)
            {
                a[temp%10]++;
                temp/=10;
            }
        }
        for(int j=0;j<10;j++)
        {
            cout<<a[j];
            if(j<9)
                cout<<" ";
        }
        cout<<endl;

    }
    return 0;
}
