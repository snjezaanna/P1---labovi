#include <stdio.h>
#include <stdlib.h>
#define max 1000

int main()
{
    int n, fakt[max]={1}, prenos;
    do {
        printf("Unesi prirodan broj manji ili jednak 100! ");
        scanf("%d", &n);
    }
    while(n>100 || n<0);

    for(int i=2; i<=n; i++) {
        for(int j=0, prenos=0; j<max; j++)  {
            int pom=fakt[j]*i+prenos;
            fakt[j]=pom%10;
            prenos=pom/10;
        }
    }
    int indeksPrvi = max-1;
    while(indeksPrvi>=0 && fakt[indeksPrvi]==0)
        indeksPrvi--;

    if(indeksPrvi<0) {
        printf("faktorijel broja %d je 0\n", n);
    }
    else {
        printf("\nFaktorijel broja %d je ", n);
        for(int j=indeksPrvi; j>=0; j--)   {
            printf("%d", fakt[j]);
        }
        printf("\n");
    }

    return 0;
}
