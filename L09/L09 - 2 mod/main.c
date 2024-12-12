#include <stdio.h>
#include <stdlib.h>
#include <math.h> // Dodao ovu biblioteku za sqrt funkciju
#define max 100

typedef struct {
    double re, im;
} kompleks;

int main() {
    int n;
    kompleks niz[max], suma, proizvod;
    double moduo[max];

    // Inicijalizacija sume i proizvoda
    suma.re = suma.im = 0.0;
    proizvod.re = 1.0;
    proizvod.im = 0.0;

    do {
        printf("broj kompleksnih brojeva: ");
        scanf("%d", &n);
    } while (n <= 0);

    printf("unos kompleksnih brojeva:\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &niz[i].re, &niz[i].im);
        moduo[i] = sqrt(niz[i].re * niz[i].re + niz[i].im * niz[i].im);

        // Raèunanje sume
        suma.re += niz[i].re;
        suma.im += niz[i].im;

        // Raèunanje proizvoda
        kompleks tempProizvod = proizvod;
        proizvod.re = tempProizvod.re * niz[i].re - tempProizvod.im * niz[i].im;
        proizvod.im = tempProizvod.re * niz[i].im + tempProizvod.im * niz[i].re;
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (moduo[i] < moduo[j]) {
                kompleks temp = niz[i];
                niz[i] = niz[j];
                niz[j] = temp;
                double tempModuo = moduo[i];
                moduo[i] = moduo[j];
                moduo[j] = tempModuo;
            }
        }
    }

    printf("Sortirani niz:\n");
    for (int i = 0; i < n; i++) {
        printf("%.2lf + %.2lfi (moduo: %.2f)\n", niz[i].re, niz[i].im, moduo[i]);
    }

    // Ispis sume i proizvoda
    printf("Suma: %.2lf + %.2lfi\n", suma.re, suma.im);
    printf("Proizvod: %.2lf + %.2lfi\n", proizvod.re, proizvod.im);

    return 0;
}
