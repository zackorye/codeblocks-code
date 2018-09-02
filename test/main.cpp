#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;

const int maxn=1e5+10;
const int INF=1e9+7;
int vis[maxn];
int n,minX,minY;

struct node
{
    int x,y,v;
}a[maxn];

bool cmp(node a,node b)
{
    if(a.x==b.x)
        return a.y<b.y;
    return a.x<b.x;
}

int dp(int x, int y, int k)
{
    if(vis[k]>=0)
        return vis[k];
    int ans=a[k].v;
    for(int i=k+1; i<=n; i++){
        if(x<a[i].x&&y<a[i].y){
            ans=max(ans,dp(a[i].x,a[i].y,i)+a[k].v);
        }
    }
    vis[k]=ans;
    return ans;
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        minX=INF,minY=INF;
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].v);
            minX=min(minX,a[i].x);
            minY=min(minY,a[i].y);
        }
        sort(a,a+n,cmp);
        memset(vis,-1,sizeof(vis));
        printf("%d\n",dp(0,0,0));
    }
    return 0;
}



