/*#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string a[100010];
string b[100010];
int main()
{
    int n,count1;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        count1=0;
        cin>>a[i];
        int L=a[i].size();
        for(int j=0; j<L; j++)
        {
            if(count1==3)
            {
                b[i]=b[i]+'-';                                  //加到第三位就加一个  '-'
                count1++;
            }


            if(a[i][j]=='A'||a[i][j]=='B'||a[i][j]=='C'||a[i][j]=='2')
            {
                b[i]=b[i]+'2';
                count1++;
            }
            else if(a[i][j]=='D'||a[i][j]=='E'||a[i][j]=='F'||a[i][j]=='3')
            {
                b[i]=b[i]+'3';
                count1++;
            }
            else if(a[i][j]=='G'||a[i][j]=='H'||a[i][j]=='I'||a[i][j]=='4')
            {
                b[i]=b[i]+'4';
                count1++;
            }
            else if(a[i][j]=='J'||a[i][j]=='K'||a[i][j]=='L'||a[i][j]=='5')
            {
                b[i]=b[i]+'5';
                count1++;
            }
            else if(a[i][j]=='M'||a[i][j]=='N'||a[i][j]=='O'||a[i][j]=='6')
            {
                b[i]=b[i]+'6';
                count1++;
            }
            else if(a[i][j]=='P'||a[i][j]=='R'||a[i][j]=='S'||a[i][j]=='7')
            {
                b[i]=b[i]+'7';
                count1++;
            }
            else if(a[i][j]=='T'||a[i][j]=='U'||a[i][j]=='V'||a[i][j]=='8')
            {
                b[i]=b[i]+'8';
                count1++;
            }
            else if(a[i][j]=='W'||a[i][j]=='X'||a[i][j]=='Y'||a[i][j]=='9')
            {
                b[i]=b[i]+'9';
                count1++;
            }
            else if(a[i][j]=='1')
            {
                b[i]=b[i]+'1';
                count1++;
            }
            else if(a[i][j]=='0')
            {
                b[i]=b[i]+'0';
                count1++;
            }
        }
    }
    sort(b,b+n);
    int count=0,count2=1;
    for(int i=1; i<n; i++)
    {
        if(b[i]==b[i-1]&&i<n-1)
        {
            count2++;
        }
        else if(b[i]==b[i-1]&&i==n-1)
        {
            count2++;
            printf("%s%d\n",b[i-1].c_str(),count2);
            count++;
        }
        else if(count2>1)
        {
            printf("%s%d\n",b[i-1].c_str(),count2);
            count2=1;
            count++;
        }
    }
    if(count==0)
        cout<<"No duplicates.";
    return 0;
}*/


#include <map>
#include <cstdio>
#include <cstring>
using namespace std;
map<char, int> key;
int pre(char *s)
{
    int re = 0;
    int p = 0;
    while (s[p] != '\0')
    {
        if (s[p] != '-')
        {
            if (s[p] >= '0' && s[p] <= '9')
                re = re * 10 + s[p] - '0';
            else
                re = re * 10 + key[s[p]];
        }
        ++p;
    }
    return re;
}
int main()
{
    int n;
    char s[1000];

    key['A'] = key['B'] = key['C'] = 2;
    key['D'] = key['E'] = key['F'] = 3;
    key['G'] = key['H'] = key['I'] = 4;
    key['J'] = key['K'] = key['L'] = 5;
    key['M'] = key['N'] = key['O'] = 6;
    key['P'] = key['R'] = key['S'] = 7;
    key['T'] = key['U'] = key['V'] = 8;
    key['W'] = key['X'] = key['Y'] = 9;

    scanf("%d",&n);
    map<int, int> mp;
    for (int i = 0; i < n; ++i)
    {
        scanf("%s", s);
        ++mp[pre(s)];
    }
    map<int, int>::iterator it;
    bool flag = 0;
    for (it = mp.begin(); it != mp.end(); ++it)
    {
        if (it->second >= 2)
        {
            printf("%03d-%04d %d\n", it->first/10000, it->first%10000, it->second);
            flag = 1;
        }
    }
    if (!flag)
        printf("No duplicates.\n");
    return 0;
}

