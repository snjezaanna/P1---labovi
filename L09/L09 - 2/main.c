#include <stdio.h>
#include <stdlib.h>
#define max 10

/* Napisati program koji učitava dvije matrice realnih brojeva, a zatim ispisuje njihov zbir (ako matrice mogu da
se saberu) i proizvod (ako matrice mogu da se pomnože). Učitavanje jedne matrice podrazumijeva učitavanje
njenih dimenzija nxm (n ≤ 10, m ≤ 10) i elemenata. Ako matrice ne mogu da se saberu, potrebno je ispisati
odgovarajuću poruku. Takođe, ako matrice ne mogu da se pomnože, potrebno je ispisati odgovarajuću poruku.   */

typedef struct  {
    int mat[max][max];
    int n, m;
}matrica;

matrica scan()    {
    matrica matr;
    int i, j;
    do  {
        printf("dimenzije matrice: ");
        scanf("%d %d", &matr.n, &matr.m);
    }
    while(matr.n<=0 || matr.m<=0 || matr.n>10 || matr.m>10);
    for(int i=0; i<matr.n; i++) {
        for(int j=0; j<matr.m; j++) {
            printf("mat[%d][%d]", i,j);
            scanf("%d", &matr.mat[i][j]); //adresirano pa ne treba &
        }
    }
    return matr;
}

void write(matrica matr) {
    int i,j;
    printf("Matrica %dx%d: \n", matr.n, matr.m);
    for(int i=0; i<matr.n; i++) {
        for(int j=0; j<matr.m; j++) {
            printf("%d ", matr.mat[i][j]);
        }
        printf("\n");
    }
}

matrica sumarum(matrica matr1, matrica matr2)  {
    matrica sum;
    if(matr1.n==matr2.n && matr1.m==matr2.m)  {
        sum.n=matr1.n;
        sum.m=matr1.m;
        for(int i=0; i<matr1.n; i++) {
            for(int j=0; j<matr1.m; j++)  {
                sum.mat[i][j]=matr1.mat[i][j]+matr2.mat[i][j];
            }
        }
    }
    else {
        printf("Matrice se ne mogu sabrati jer nisu istih dimenzija!\n");
        sum.n=0;
    }
    return sum;
}

matrica product(matrica matr1, matrica matr2)   {
    matrica prod;
    if(matr1.m==matr2.n)  {
        prod.n=matr1.n;
        prod.m=matr2.m;
        for(int i=0; i<matr1.n; i++)  {
            for(int j=0; j<matr2.m; j++)  {
                    prod.mat[i][j]=0;
                for (int k = 0; k < matr1.m; k++) {
                    prod.mat[i][j] += matr1.mat[i][k] * matr2.mat[k][j];
}            }
        }
    }
    else {
        printf("Matrice se ne mogu pomnoziti!\n");
        prod.n=0;
    }
    return prod;

}

int main()
{
    matrica matr1, matr2, sum, prod;

    printf("Unesi dimenzije matrice 1: ");
    matr1=scan();
    write(matr1);

    printf("Unesi dimenzije matrice 2: ");
    matr2=scan();
    write(matr2);

    sum=sumarum(matr1, matr2);
    if(sum.n!=0)  {
        printf("Zbir matrica je ");
        write(sum);
    }

    prod=product(matr1, matr2);
    if(prod.n!=0)   {
        printf("Proizvod matrica je ");
        write(prod);
    }

    return 0;
}
