#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    string a,b,c;
    cout<<"����ԭ�ַ���"<<endl;
    getline(cin,a);
    cout<<"���뱻�滻���ַ���"<<endl;
    getline(cin,b);
    cout<<"�����滻���ַ���"<<endl;
    getline(cin,c);
    int lenb=b.length();
    int lena=a.length();
    for(int i=0; i<lena; i++)
    {
        if(a[i]==b[0])
        {
            bool flag=true;
            for(int j=0; j<lenb; j++)
            {
                if(a[i+j]!=b[j])
                {
                    flag=false;
                    break;
                }
            }
            if(flag)
                cout<<c;
            i=i+lenb-1;
        }
        else
            cout<<a[i];
    }
    return 0;
}
