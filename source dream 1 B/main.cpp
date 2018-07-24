#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    double a;
    int count;
    while(scanf("%lf",&a)==1&&a!=0.00)
    {
        count=0;
        double s=0.0;
        for(;;)
        {
            count++;
            s=s+1.0/(count+1);
            if(s>=a)
                break;
        }
        printf("%d card(s)\n",count);
    }

    return 0;
}
