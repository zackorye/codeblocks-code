#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int main()
{
    int N,T,n=1;
    cin>>N;
    while(n<=N)
    {
        double X,Y;
        cin>>X>>Y;
        T=floor(0.5*3.14*(X*X+Y*Y)/50.0+1);
        printf("Property %d: This property will begin eroding in year %d.\n",n++,T);
    }
    printf("END OF OUTPUT.");
    return 0;
}
