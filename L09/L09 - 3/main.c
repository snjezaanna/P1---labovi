#include <stdio.h>
#include <stdlib.h>
#define max 100

typedef struct {
    double re, im;
} kompleks;
int main()
{
    int n;
    kompleks niz[max];
    double moduo[max];

    do {
        printf("broj kompleksnih brojeva: ");
        scanf("%d", &n);
    }
    while(n<=0);

    printf("unos kompleksnih brojeva:\n");
    for(int i=0; i<n; i++) {
        scanf("%lf %lf", &niz[i].re, &niz[i].im);
        moduo[i]=sqrt(niz[i].re*niz[i].re+niz[i].im*niz[i].im);
    }

    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(moduo[i]<moduo[j]) {
                kompleks temp=niz[i];
                niz[i]=niz[j];
                niz[j]=temp;
                double tempModuo=moduo[i];
                moduo[i]=moduo[j];
                moduo[j]=tempModuo;
            }
        }
    }
    printf("Sortirani niz:\n");
    for(int i=0; i<n; i++) {
        printf("%.2lf + %.2fi (moduo: %.2f)\n", niz[i].re, niz[i].im, moduo[i]);
    }

    return 0;
}
