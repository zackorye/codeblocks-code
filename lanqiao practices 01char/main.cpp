#include<iostream>
using namespace std;

int main()
{
	int a[5]={0};
	for(int k=0;k<32;k++)
	{
		for(int i=0;i<5;i++)
		cout<<a[i];
		cout<<endl;
		a[4]++;
		for(int j=4;j>=0;j--)
		{
			if(a[j]>1&&j-1>=0)
			{
				a[j]=0;
				a[j-1]++;
			}
		}
	}
	return 0;
}
