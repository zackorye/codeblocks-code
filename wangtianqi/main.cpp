#include<iostream>
#include<cstdio>
#include"List.h"
using namespace std;

int main()
{
	List L;
	L.Init();
	int n;
	printf("��Ҫ���뼸����\n");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
    {
        int k;
        cin>>k;
        L.Push_back(k);
    }
/*
    printf("������Ҫ���뵽�ĸ�Ԫ�غͲ��������\n");
    int place ,temp;
    cin>>place>>temp;
    L.Insert(L.Find(place),temp);
    L.display();

    printf("������Ҫɾ����Ԫ��\n");
    cin>>temp;
    L.Erase(temp);
    L.display();
*/
    printf("������������\n");
    L.Sort();
    L.display();

    printf("��ת���������\n");
    L.Reverse();
    L.display();


	return 0;
}
