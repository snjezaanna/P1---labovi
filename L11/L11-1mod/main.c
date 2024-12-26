#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    char oznaka[2];
    double x, y;
} TACKA;

typedef struct {
    TACKA A, B, C;
} TROUGAO;

void citaj(TACKA *);
int ifTrougao(TACKA *);
TROUGAO trougao(TACKA *);
double obim(TROUGAO);
int isPravougli(TROUGAO);

int main() {
    TACKA A, B, C;
    citaj(&A);
    citaj(&B);
    citaj(&C);
    TACKA niz[] = {A, B, C};
    if (ifTrougao(niz)) {
        TROUGAO tr = trougao(niz);
        double o = obim(tr);
        printf("Obim trougla je %.2lf\n", o);
        if (isPravougli(tr)) {
            printf("Trougao je pravougli.\n");
        } else {
            printf("Trougao nije pravougli.\n");
        }
    } else {
        printf("Trougao datih mjera ne postoji!\n");
    }
    return 0;
}

void citaj(TACKA *t) {
    printf("\nUnesi oznaku tjemena trougla! ");
    scanf("%s", &(t->oznaka));
    printf("\nUnesi koordinate tacke %s ", t->oznaka);
    scanf("%lf %lf", &(t->x), &(t->y));
}

int ifTrougao(TACKA tjeme[3]) {
    double s1 = sqrt(pow(tjeme[0].x - tjeme[1].x, 2) + pow(tjeme[0].y - tjeme[1].y, 2));
    double s2 = sqrt(pow(tjeme[0].x - tjeme[2].x, 2) + pow(tjeme[0].y - tjeme[2].y, 2));
    double s3 = sqrt(pow(tjeme[1].x - tjeme[2].x, 2) + pow(tjeme[1].y - tjeme[2].y, 2));
    if (s1 + s2 <= s3 || s2 + s3 <= s1 || s1 + s3 <= s2)
        return 0;
    return 1;
}

TROUGAO trougao(TACKA tjeme[3]) {
    TROUGAO t = {tjeme[0], tjeme[1], tjeme[2]};
    return t;
}

double obim(TROUGAO tr) {
    double s1 = sqrt(pow(tr.A.x - tr.B.x, 2) + pow(tr.A.y - tr.B.y, 2));
    double s2 = sqrt(pow(tr.A.x - tr.C.x, 2) + pow(tr.A.y - tr.C.y, 2));
    double s3 = sqrt(pow(tr.B.x - tr.C.x, 2) + pow(tr.B.y - tr.C.y, 2));
    return s1 + s2 + s3;
}

int isPravougli(TROUGAO tr) {
    double s1 = sqrt(pow(tr.A.x - tr.B.x, 2) + pow(tr.A.y - tr.B.y, 2));
    double s2 = sqrt(pow(tr.A.x - tr.C.x, 2) + pow(tr.A.y - tr.C.y, 2));
    double s3 = sqrt(pow(tr.B.x - tr.C.x, 2) + pow(tr.B.y - tr.C.y, 2));

    // Provjera da li je trougao pravougli koristeæi Pitagorinu teoremu
    if (fabs(s1 * s1 + s2 * s2 - s3 * s3) < 1e-9 ||
        fabs(s1 * s1 + s3 * s3 - s2 * s2) < 1e-9 ||
        fabs(s2 * s2 + s3 * s3 - s1 * s1) < 1e-9) {
        return 1;
    }
    return 0;
}
