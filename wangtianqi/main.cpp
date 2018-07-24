#include<iostream>
#include<cstdio>
#include"List.h"
using namespace std;

int main()
{
	List L;
	L.Init();
	int n;
	printf("你要输入几个数\n");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
    {
        int k;
        cin>>k;
        L.Push_back(k);
    }
/*
    printf("输入你要插入到哪个元素和插入的数字\n");
    int place ,temp;
    cin>>place>>temp;
    L.Insert(L.Find(place),temp);
    L.display();

    printf("输入你要删除的元素\n");
    cin>>temp;
    L.Erase(temp);
    L.display();
*/
    printf("排序后的数据是\n");
    L.Sort();
    L.display();

    printf("翻转后的数据是\n");
    L.Reverse();
    L.display();


	return 0;
}
