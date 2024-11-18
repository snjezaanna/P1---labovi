#include <stdio.h>
#include <stdlib.h>
                //ispisi sve parove prijateljskih brojeva u opsegu [a,b]
int main()
{
    int a,b;

    printf("Unesi opseg ");

    do {
        scanf("%d %d", &a, &b);
    }
    while (a<=0 || b<=0 || b<=a);

    for(int i=a; i<=b; i++) {  //loop kroz opseg
        int sum1=0;
        for(int j=1; j<=i/2; j++){
            if(i%j==0)  {
                sum1+=j;
            }
        }
        if (sum1>i && sum1<=b)  {
                int sum2=0;
            for(int k=1; k<=sum1/2; k++)   {
        if(sum1%k==0)  {
            sum2+=k;
        }
            }
    if(sum2==i) {
        printf("Prijateljski brojevi: %d i %d\n", i, sum1);
        }

    }
}
    return 0;
}
