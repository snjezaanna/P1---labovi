#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int brojilac;
    int imenilac;
} razlomak;

int main()
{
    razlomak r1, r2, rezultat;
    int gcd, temp, a, b;

    printf("Unesi prvi razlomak: ");
    scanf("%d %d", &r1.brojilac, &r1.imenilac);

    printf("\nUnesi drugi razlomak: ");
    scanf("%d %d", &r2.brojilac, &r2.imenilac);

    if(r1.imenilac==r2.imenilac)   {
        rezultat.brojilac=r1.brojilac+r2.brojilac;
        rezultat.imenilac=r1.imenilac;
    }
    else {
    rezultat.brojilac=r1.brojilac*r2.imenilac+r2.brojilac*r1.imenilac;
    rezultat.imenilac=r1.imenilac*r2.imenilac;
    }

    a=rezultat.brojilac;
    b=rezultat.imenilac;

    while(b!=0) {
        temp=b;
        b=a%b;
        a=temp;
    }
    gcd=a;
    rezultat.brojilac/=gcd;
    rezultat.imenilac/=gcd;

    printf("Rezultujuci razlomak je %d/%d\n", rezultat.brojilac, rezultat.imenilac);
    return 0;
}
