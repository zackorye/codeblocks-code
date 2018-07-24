#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<int> a,b;
    int n,m,k;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>k;
        a.push(k);
    }
    for(int i=0;i<m;i++)
    {
        cin>>k;
        b.push(k);
    }
    int as=0,bs=0,count=0;
    as+=a.front();
    a.pop();
    bs+=b.front();
    b.pop();
    while(!a.empty()||!b.empty())
    {
        if(as==bs)
        {
            count++;
            as+=a.front();
            a.pop();
            bs+=b.front();
            b.pop();
        }
        if(as<bs)
        {
            as+=a.front();
            a.pop();
        }
        else if(bs<as)
        {
            bs+=b.front();
            b.pop();
        }
    }
    cout<<count+1;
    return 0;
}
