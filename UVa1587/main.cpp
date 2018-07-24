#include <iostream>
#include <algorithm>
using namespace std;

struct rectangular
{
    int length;
    int width;
};
rectangular a[6];

bool compare(rectangular a,rectangular b)
{
	if (a.length != b.length)
		return a.length > b.length;
	return a.width > b.width;
}

bool judge()
{
    if(a[0].width==a[2].length&&a[2].width==a[4].length&&a[4].width==a[0].length)
        return true;
    else
        return false;
}

int main()
{
    while(cin>>a[0].length>>a[0].width)
    {
        if(a[0].length>a[0].width)
            swap(a[0].length,a[0].width);
        for(int i=1; i<6; i++)
        {
            cin>>a[i].length>>a[i].width;
            if(a[i].length>a[i].width)
                swap(a[i].length,a[i].width);
        }
        sort(a,a+6,compare);
        bool flag=true;
        for(int i=0;i<=4;i+=2)
        {
            if(a[i].length!=a[i+1].length||a[i].width!=a[i].width)
                flag=false;
        }
        bool flags=false;
        for(int i=0;i<2;i++)
        {
            swap(a[0].length,a[0].width);
            for(int j=0;j<2;j++)
            {
                swap(a[2].length,a[2].width);
                for(int k=0;k<2;k++)
                {
                    swap(a[4].length,a[4].width);
                    if(judge())
                    {
                        flags=true;
                        break;
                    }

                }
                if(flags)
                    break;
            }
            if(flags)
                break;
        }
        if(flag&&flags)
            cout<<"POSSIBLE"<<endl;
        else
            cout<<"IMPOSSIBLE"<<endl;

    }
    return 0;
}
