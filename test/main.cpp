#include<iostream>
#include<cstdio>
#include<cstring>
#include<math.h>
#include<vector>
#include<map>
using namespace std;

int cnt;  //组件类型数目
map<string,int> id;
int ID(string s)
{
    if(!id.count(s))
        id[s]=cnt++;优选
    return id[s];
}

const int maxn=1000+5;

struct Component
{
    int price;
    int quality;
};

int n,b;   //组件数目，预算
vector<Component> comp[maxn];

bool ok(int q)
{
    int sum=0;
    for(int i=0;i<cnt;i++){
        int cheapest=b+1,m=comp[i].size();
        for(int j=0;j<m;j++)
            if(comp[i][j].quality>=q) cheapest=min(cheapest,comp[i][j].price);
        if(cheapest==b+1)
            return false;
        sum+=cheapest;
        if(sum>b)
            return false;
    }
    return true;
}

int main()
{
    int T;
    cin>>T;
    while(T--){
        scanf("%d%d",&n,&b);
        cnt=0;
        for(int i=0;i<n;i++){
                comp[i].clear();
        }
        id.clear();
        int maxq=0;
        for(int i=0;i<n;i++){
            char type[30],name[30];
            int p,q;
            scanf("%s%s%d%d",type,name,&p,&q);
            maxq=max(maxq,q);
            comp[ID(type)].push_back((Component{p,q}));
        }
        int L=0,R=maxq;
        while(L<R){
            int M=L+(R-L+1)/2;
            if(ok(M))
                L=M;
            else
                R=M-1;
        }
        printf("%d\n",L);
    }
    return 0;
}



/*
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

const int maxn=102;
int G[maxn][maxn];
int N,M;

struct node
{
    int y,maxV;
};


int K[maxn]={0};
node jilu[maxn];
vector<node> V[maxn];
int vis[maxn];

int dp(int i,int cnt)
{
    if(cnt==N)
        return 0;
    cnt++;
    if(vis[i]){
        return K[i]+dp(jilu[i].y,cnt);
    }
    vis[i]=1;
    int tempk=0;
    for(vector<node>::iterator it=V[i].begin();it!=V[i].end();it++){
        int temp=(*it).maxV+dp((*it).y,cnt);
        if(tempk<temp)
        {
            jilu[i].y=(*it).y;
            tempk=temp;
        }
    }
    return tempk;
}


int main()
{
    while(scanf("%d%d",&N,&M)==2){
        for(int i=1;i<=M;i++){
            vis[i]=0;
            for(int j=1;j<=M;j++){
                scanf("%d",&G[i][j]);
                K[i]=max(K[i],G[i][j]);
            }
        }
        node nd;
        for(int i=1;i<=M;i++){
            for(int j=1;j<=M;j++){
                if(G[i][j]==K[i]){
                    nd.y=j;
                    nd.maxV=K[i];
                    V[i].push_back(nd);
                }
            }
        }
        int temp=0;
        for(int i=1;i<=N;i++){
            temp=max(dp(i,1),temp);
        }
        for(int i=1;i<=M;i++){
            V[i].clear();
        }
        cout<<temp<<endl;
    }
    return 0;
}
*/



/*
#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=2010;


int G[maxn][maxn];

struct node
{
    int a,b;
    bool operator<(const node &x)const
    {
        if(a!=x.a)
            return a<x.a;
        return b<x.b;
    }

};

node A[100000];
node K[100000];

int main()
{
    int N,M,cnt;
    while(scanf("%d%d",&N,&M)==2)
    {
        cnt=0;
        memset(G,0,sizeof(G));
        //memset(vis,0,sizeof(vis));
        int x,y,T,i;
        cin>>T;
        for(i=0; i<T; i++)
        {
            scanf("%d%d",&x,&y);
            G[x][y]=1;
            A[i].a=x,A[i].b=y;
            cnt++;
        }

        sort(A,A+i);
        node temp=A[0],nd;
        int k,result=N*M;
        for(;;)
        {
            if(cnt==result)
            {
                printf("%d %d\n",temp.a,temp.b);
                //cout<<temp.a<<" "<<temp.b<<endl;
                break;
            }
            k=0;
            for(int j=0;j<i;j++){
                nd=A[j];
                if(nd.a+1<=N&&G[nd.a+1][nd.b]==0)
                {
                    K[k].a=nd.a+1,K[k].b=nd.b;
                    k++;
                    G[nd.a+1][nd.b]=1;
                    cnt++;
                }
                if(nd.a-1>=1&&G[nd.a-1][nd.b]==0)
                {
                    K[k].a=nd.a-1,K[k].b=nd.b;
                    k++;
                    G[nd.a-1][nd.b]=1;
                    cnt++;
                }
                if(nd.b+1<=M&&G[nd.a][nd.b+1]==0)
                {
                    K[k].a=nd.a,K[k].b=nd.b+1;
                    k++;
                   G[nd.a][nd.b+1]=1;
                    cnt++;
                }
                if(nd.b-1>=1&&G[nd.a][nd.b-1]==0)
                {
                    K[k].a=nd.a,K[k].b=nd.b-1;
                    k++;
                    G[nd.a][nd.b-1]=1;
                    cnt++;
                }
            }
            temp=K[0];
            for(i=0;i<k;i++){
                nd.a=K[i].a,nd.b=K[i].b;
                A[i]=nd;
                temp=min(A[i],temp);
            }
        }

    }
    return 0;
}
*/
