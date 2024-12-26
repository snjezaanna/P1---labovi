#include <stdio.h>
#include <stdlib.h>
/*Definisati tip DOKUMENT kojim se reprezentuju podaci o dokumentu èiji su atributi naziv, ekstenzija i
velièina (u bajtovima). Napisati program koji sa standardnog ulaza uèitava podatke za n dokumenata i formira
odgovarajuæi dinamièki niz, a zatim ispisuje podatke o dokumentima èija je velièina veæa od velièine koja se
uèitava sa standardnog ulaza.
Za formiranje dinamièkog niza podataka o dokumentima treba definisati i koristiti funkciju èiji je prototip:
DOKUMENT* formiraj(int *);
Za ispis podataka o jednom dokumentu treba definisati i koristiti funkciju èiji je prototip:
void ispisi(DOKUMENT);
pri èemu podatke o dokumentu treba ispisati u obliku:
naziv.ekstenzija | velicina [B]*/

typedef struct dokument{
    int velicina;
    char naziv[20],ekstenzija[8];
}DOKUMENT;

DOKUMENT* formiraj(int *);
void ispisi(DOKUMENT);

int main()
{
    int n;
    DOKUMENT *dokumenti=formiraj(&n);
    if(dokumenti!=NULL){
        int vel;
        printf("Unesi odgovarajucu velicinu: ");
        scanf("%d", &vel);
        for(int i=0;i<n;i++){
            if(dokumenti[i].velicina>vel){
                ispisi(dokumenti[i]);
            }
        }
        free(dokumenti);
        dokumenti=NULL;
    }else{
        printf("Alokacija memorije nije bila moguca.");
    }
    return 0;
}
DOKUMENT* formiraj(int *n){
    do{
        printf("Unesi broj dokumenata: ");
        scanf("%d", n);
    }while(*n<1);
    DOKUMENT *dok = (DOKUMENT *)malloc(sizeof(DOKUMENT)**n);
    if(dok==NULL){
        return NULL;
    }
    for(int i=0;i<*n;i++){
        printf("Unesi podatak za %d. dokument:\n",i+1);
        printf("Naziv: ");
        scanf("%s", &dok[i].naziv);
        printf("Ekstenzija: ");
        scanf("%s", &dok[i].ekstenzija);
        printf("Velicina [B]: ");
        scanf("%d", &dok[i].velicina);
    }
    return dok;
}

void ispisi(DOKUMENT d){
    printf("%s.%s | %d [B]\n", d.naziv,d.ekstenzija,d.velicina);
}
