#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int dan;
    int mjesec;
    int godina;
} DATUM;

typedef struct {
    int brojIndeksa;
    char ime[50];
    char prezime[50];
    DATUM datumRodjenja;
    double prosjek;
} STUDENT;

int main() {
    int n;
    STUDENT studenti[100];

    printf("Unesite broj studenata: ");
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        printf("Unesite podatke za studenta %d (broj indeksa, ime, prezime, datum rodjenja (dan mjesec godina), prosjek):\n", i + 1);
        scanf("%d %s %s %d %d %d %lf", &studenti[i].brojIndeksa, studenti[i].ime, studenti[i].prezime,
              &studenti[i].datumRodjenja.dan, &studenti[i].datumRodjenja.mjesec, &studenti[i].datumRodjenja.godina,
              &studenti[i].prosjek);
    }

    // Sortiranje studenata po datumu rodjenja
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (studenti[j].datumRodjenja.godina > studenti[j + 1].datumRodjenja.godina ||
               (studenti[j].datumRodjenja.godina == studenti[j + 1].datumRodjenja.godina &&
                studenti[j].datumRodjenja.mjesec > studenti[j + 1].datumRodjenja.mjesec) ||
               (studenti[j].datumRodjenja.godina == studenti[j + 1].datumRodjenja.godina &&
                studenti[j].datumRodjenja.mjesec == studenti[j + 1].datumRodjenja.mjesec &&
                studenti[j].datumRodjenja.dan > studenti[j + 1].datumRodjenja.dan)) {

                STUDENT temp = studenti[j];
                studenti[j] = studenti[j + 1];
                studenti[j + 1] = temp;
            }
        }
    }

    // Ispis formatiranog niza podataka
    printf("RB. PREZIME           IME               DATUM RODJ.   PROSJEK\n");
    printf("=== =============== =============== =========== =======\n");

    for (int i = 0; i < n; ++i) {
        printf("%-3d %-15s %-15s %02d.%02d.%04d. %.2f\n", i + 1, studenti[i].prezime, studenti[i].ime,
               studenti[i].datumRodjenja.dan, studenti[i].datumRodjenja.mjesec, studenti[i].datumRodjenja.godina,
               studenti[i].prosjek);
    }

    printf("=== =============== =============== =========== =======\n");

    return 0;
}
