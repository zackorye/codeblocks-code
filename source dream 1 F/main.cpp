/*#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

struct str
{
    char l[105];
    int k;
};
str s[55];

bool cmp(str a,str b)
{
    return a.k<b.k;
}

int main()
{
    int N,M;
    cin>>M>>N;
    for(int i=0;i<N;i++)
    {
        scanf("%s",s[i].l);
        s[i].k=0;
        for(int j=0;j<M-1;j++)
        {
            for(int p=j+1;p<M;p++)
            {
                if(s[i].l[j]>s[i].l[p])
                    s[i].k++;
            }
        }
    }
    sort(s,s+N,cmp);
    for(int i=0;i<N;i++)
        printf("%s\n",s[i].l);
    return 0;
}
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 105;
struct DNA {
    string str;
    int num;
} dnas[maxn];

bool cmp(const DNA& a, const DNA& b) {
    return a.num < b.num;
}

int main() {
    int n, m;

    while (scanf("%d%d", &n, &m) != EOF) {
        for (int i = 0; i < m; ++i) {
            cin >> dnas[i].str;
            dnas[i].num = 0;
            for (int k = 0; k < n; ++k) {
                for (int j = k + 1; j < n; ++j) {
                    if (dnas[i].str[k] > dnas[i].str[j]) {
                        dnas[i].num++;
                    }
                }
            }

        }

        sort(dnas,dnas+m,cmp);

        for(int i =0;i<m;++i){
            cout<<dnas[i].str<<endl;
        }
    }

    return 0;
}

