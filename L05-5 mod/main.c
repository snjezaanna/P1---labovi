#include <stdio.h>
#include <stdlib.h>
                //suma cifara prvih n
int main()
{
    int n;
    printf("Unesi neki prirodan broj!\n");
    do {
        scanf("%d", &n);
    }
    while (n<=0);
    for(int i=1; i<=n; i++) {
        int sum=0;
        int num=i;
    while(num>0) {
        sum+=num%10;
        num/=10;
    }

        printf("Suma cifara je %d.\n", sum);
    }

    return 0;
}
