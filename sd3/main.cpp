#include <iostream>
#include<math.h>
#include<cstdio>
using namespace std;

long long sx(long long  x)
{
    long long k=0;
    while(x)
    {
        k+=x%10;
        x/=10;
    }
    return k;
}

int main(){
    long long n;
    cin>>n;
    bool flag=0;
    int s=sqrt(n)/2;
    int j=1;
    for(long long i=sqrt(n);i>0;i--)
    {
        long long b=sx(i);
        if(i*i+i*b==n)
        {
            flag=1;
            cout<<i;
            break;
        }
    }
    if(!flag)
        cout<<"-1";
    return 0;
}



/*
int main()
{
    int louptemp=1,ver=3,edge=3;
    int loup;
    cin>>loup;
    bool flag=false;
    if(loup!=louptemp)
    {
        for(ver++,edge+=2;ver<=100;ver++,edge+=2)
        {
            int temp=0,tempedge=edge-2,tempver=ver-1;
            for(;edge<=tempedge+tempver;edge++)
            {
                temp++;
                for(int i=1;i<=temp;i++)
                {
                    louptemp++;
                    if(louptemp==loup)
                    {
                        flag=true;
                        break;
                    }

                }
                if(flag)
                    break;
            }
            if(flag)
                break;
        }
    }
    cout<<loup<<' '<<ver<<' '<<edge;
    return 0;
}



int sx(int x)
{
    int k=0;
    while(x)
    {
        k+=x%10;
        x/=10;
    }
    return k;
}

int main(){
    int n;
    cin>>n;
    for(double i=1.0;;i++)
    {
        if(2-n>0)
        {
            cout<<"-1"<<endl;
            break;
        }
        else
        {
        int b=sx(i);
        int s=i*i+b*i-n;
        if(i*i+i*b==n)
        {
            cout<<i;
            break;
        }
        else
            break;
        }
    }
}
int main()
{
    int n,i,j,k,l,m,ans[110][110];
    while(scanf("%d",&n)!=EOF)
    {
        memset(ans,0,sizeof(0));
        for(i=3;i<=100;i++)//求最大完全图
        {
            if(i*(i-1)*(i-2)/6>n)
            {
                k=i-1;
                break;
            }
        }
        for(i=1;i<=k;i++)
        {
            for(j=1;j<=k;j++)
            {
                if(i!=j)
                {
                    ans[i][j]=1;
                }
                else
                    ans[i][j]=0;
            }
        }
        n=n-k*(k-1)*(k-2)/6;
        while(n)
        {
            k++;//顶点数加1
            for(i=2;n>=i*(i+1)/2;i++);//添加边
            n-=i*(i-1)/2;
            for(j=1;j<=i;j++)
               ans[k][j]=ans[j][k]=1;
        }
        printf("%d\n",k);
        for(i=1;i<=k;i++)
        {
            for(j=1;j<=k;j++)
            {
                printf("%d",ans[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}

int a[1000][1000];
int main()
{
    int louptemp=1,ver=3,edge=3;
    int loup;
    cin>>loup;
    bool flag=false;
    if(loup!=louptemp)
    {
        for(ver++;ver<=100;ver++)
        {
            if(ver>4)
                edge--;
            int temp=0,tempedge=edge,tempver=ver-1;
            for(edge+=2;edge<=tempedge+tempver;edge++)
            {
                temp++;
                for(int i=1;i<=temp;i++)
                {
                    louptemp++;
                    if(louptemp==loup)
                    {
                        flag=true;break;
                    }

                }
                if(flag)
                    break;
            }
            if(flag)
                break;
        }
    }
    cout<<ver<<endl;
    for(int i=0;i<ver;i++)
    {
        for(int j=i;j<ver;j++)
        {
            if(i==j)
                a[i][j]=0;
            else if(edge&&(i!=j))
            {
                a[i][j]=1;
                a[j][i]=1;
                edge-=1;
            }
        }
    }
    for(int i=0;i<ver;i++)
    {
        for(int j=0;j<ver;j++)
        {
            printf("%d",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}


#include <iostream>
#include<math.h>
#include<algorithm>
#include<string.h>
#include<cstdio>
#include<fstream>
using namespace std;

int a[1000][1000];

int com(int n,int m)
{
    int x;
    int y;
    while(m!=(m-n))
    {
        x*=m;
        m--;
    }
    while(n!=0)
    {
        y*=n;
        n--;
    }
    return x/y;

}
int main()
{
    int via;
    int n;
    scanf("%d",&n);
    for(int i=3;i<1000;i++)
    {
        if((i*(i-1))>=n)
        {
            via=i;
            break;
        }
    }
    printf("%d\n",via);
    for(int i=0;i<via;i++)
    {
        for(int j=i;j<via;j++)
        {
            if(i==j)
                a[i][j]=0;
            else if(n&&(i!=j))
            {
                a[i][j]=1;
                a[j][i]=1;
                n-=1;
            }
        }
    }
    for(int i=0;i<via;i++)
    {
        for(int j=0;j<via;j++)
        {
            printf("%d",a[i][j]);
        }
        printf("\n");
    }
}































struct m{
    int x;
    int y;
};
bool cmp(m a,m b)
{
    return a.x>b.x;
}
bool cmp2(m a,m b)
{
    return a.y<b.y;

}
int main(){
    m a[1050];
    memset(a,0,sizeof(a));
    int n,k;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        cin>>a[i].x;
        a[i].y=i+1;
    }
    sort(a,a+n,cmp);
    cout<<a[k-1].x<<endl;
    sort(a,a+k,cmp2);
    for(int i=0;i<k-1;i++)
        cout<<a[i].y<<" ";
    cout<<a[k-1].y;
    return 0;
}



char s[111];
int main(){
    int n;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin>>n;
    memset(s,0,sizeof(s));
    for(int i=0;i<n;i++)
        cin>>s[i];
    int x=n/2;
    int j=0;
    for(int i=0;i<x;i++)
    {
        if(s[j]=='R'&&s[j+x]=='L')
            cout<<j+x+1<<" "<<j+1<<endl;
        else
            cout<<j+1<<" "<<j+x+1<<endl;
        j++;
    }
    return 0;
}







struct graph
{
    int loup,edge,ver;
};
graph a[100000];

int main()
{
    for(int i=0;i<100000;i++)
    {
        a[i].loup=i+1;
        a[i].edge=3;
        a
    }
}



int main()
{
    int n;
    scanf("%d",&n);
    if(n%2!=0)
    {
        printf("-1");
    }

    if(n%2==0)
    {
        int x=2,y=1;
        int count=n/2;
        for(int i=0;i<count-1;i++)
        {
            printf("%d %d ",x,y);
            x+=2;
            y+=2;
        }
        printf("%d %d",x,y);
    }
    return 0;
}
*/
