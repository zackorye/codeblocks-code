#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

string Maya[]={"imix","ik","akbal","kan","chicchan","cimi","manik","lamat","muluk","ok","chuen","eb","ben","ix","mem","cib","caban","eznab","canac","ahau"};
string Haan[]={"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};
struct dat
{
    int NU,Year;
    string NA;
};
int main()
{
    int N;
    scanf("%d",&N);
    dat *a=new dat[N];
    for(int i=0;i<N;i++)
    {
        int days=0;
        char c;
        cin>>a[i].NU>>c>>a[i].NA>>a[i].Year;
        for(int j=0;j<19;j++)
        {
            if(a[i].NA==Haan[j])
                days=j*20+a[i].NU+a[i].Year*365+1;
        }
        a[i].Year=days/260;
        int num=days%260;
        if(num==0)
        {
            a[i].Year--;
        }
        if(num%13==0)
        {
            a[i].NU=13;
        }
        else
            a[i].NU=num%13;
        int k=num%20;
        if(k==0)
            k=20;
        a[i].NA=Maya[k-1];
    }
    printf("%d\n",N);
    for(int i=0;i<N;i++)
    {
        cout<<a[i].NU<<' '<<a[i].NA<<' '<<a[i].Year<<endl;
    }
    return 0;
}
