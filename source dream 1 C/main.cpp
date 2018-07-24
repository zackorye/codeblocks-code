#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    float a,s=0;
    for(int i=0;i<12;i++)
    {
        scanf("%f",&a);
        s=s+a;
    }
    printf("$%.2f",s/12);
    return 0;
}
