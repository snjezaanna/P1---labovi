#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int dan;
    int mjesec;
    int godina;
} DATUM;

typedef struct dokument {
    int velicina;
    char naziv[20], ekstenzija[8];
    DATUM datum;
} DOKUMENT;

DOKUMENT* formiraj(int *);
void ispisi(DOKUMENT);
void ispisi2022(DOKUMENT *, int);

int main() {
    int n;
    DOKUMENT *dokumenti = formiraj(&n);
    if(dokumenti != NULL) {
        int vel;
        printf("Unesi odgovarajucu velicinu: ");
        scanf("%d", &vel);
        for(int i = 0; i < n; i++) {
            if(dokumenti[i].velicina > vel) {
                ispisi(dokumenti[i]);
            }
        }
        printf("Dokumenti nastali 2022. godine:\n");
        ispisi2022(dokumenti, n);

        free(dokumenti);
        dokumenti = NULL;
    } else {
        printf("Alokacija memorije nije bila moguca.");
    }
    return 0;
}

DOKUMENT* formiraj(int *n) {
    do {
        printf("Unesi broj dokumenata: ");
        scanf("%d", n);
    } while(*n < 1);

    DOKUMENT *dok = (DOKUMENT *)malloc(sizeof(DOKUMENT) * *n);
    if(dok == NULL) {
        return NULL;
    }

    for(int i = 0; i < *n; i++) {
        printf("Unesi podatak za %d. dokument:\n", i + 1);
        printf("Naziv: ");
        scanf("%s", dok[i].naziv);
        printf("Ekstenzija: ");
        scanf("%s", dok[i].ekstenzija);
        printf("Velicina [B]: ");
        scanf("%d", &dok[i].velicina);
        printf("Datum nastanka (dan mjesec godina): ");
        scanf("%d %d %d", &dok[i].datum.dan, &dok[i].datum.mjesec, &dok[i].datum.godina);
    }
    return dok;
}

void ispisi(DOKUMENT d) {
    printf("%s.%s | %d [B] | Datum: %02d.%02d.%04d\n", d.naziv, d.ekstenzija, d.velicina, d.datum.dan, d.datum.mjesec, d.datum.godina);
}

void ispisi2022(DOKUMENT *dokumenti, int n) {
    for(int i = 0; i < n; i++) {
        if(dokumenti[i].datum.godina == 2022) {
            ispisi(dokumenti[i]);
        }
    }
}
