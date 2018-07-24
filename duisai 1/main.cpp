#include<iostream>
#include<cstdio>
using namespace std;
 int a[2005][2005]={0};
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for(int i=0;i<n;i++)
        {
            int vis=0;
            while(a[i][vis]!=0)
            {
                vis++;
                if(vis==i)
                    vis++;
            }
            if((vis-1)==n)
            {
                printf("No");
                return 0;
            }
            vis=0;
            while(a[vis][i]==0)
            {
                vis++;
                if(vis==i)
                    vis++;
            }
            if((vis-1)==n)
            {
                printf("NO");
                return 0;
            }
        }
        printf("YES");
        return 0;

}



