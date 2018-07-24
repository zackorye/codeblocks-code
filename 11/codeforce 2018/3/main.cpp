#include <iostream>

using namespace std;

int main()
{
    int l,r,a;
    cin>>l>>r>>a;
    int team=0;
    while((l+a>0)&&(r+a>0))
    {
        if(l>0)
            l--;
        else
            a--;
        if(r>0)
            r--;
        else
            a--;
        if(a>=0)
            team+=2;
    }
    cout<<team;
    return 0;
}
