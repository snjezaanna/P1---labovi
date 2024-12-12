#include <stdio.h>
#include <stdlib.h>

// Struktura za trougao
typedef struct {
    double a;
    double b;
    double c;
} TROUGAO;

int main() {
    TROUGAO t;
    double obim, povrsina, s;

    // Uèitavanje stranica trougla
    printf("Unesite duzine stranica trougla:\n");
    scanf("%lf %lf %lf", &t.a, &t.b, &t.c);

    // Provera da li je trougao validan
    if (t.a + t.b > t.c && t.a + t.c > t.b && t.b + t.c > t.a) {
        // Izraèunavanje obima
        obim = t.a + t.b + t.c;

        // Izraèunavanje površine koristeæi Heronovu formulu
        s = obim / 2;
        povrsina = sqrt(s * (s - t.a) * (s - t.b) * (s - t.c));

        // Ispis rezultata
        printf("Obim trougla: %.2f\n", obim);
        printf("Povrsina trougla: %.2f\n", povrsina);
    } else {
        printf("Unete stranice ne cine validan trougao.\n");
    }

    return 0;
}
