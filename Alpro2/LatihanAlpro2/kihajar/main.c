#include "header.h"
int main() {
    int N;
    scanf("%d", &N);

    int murid = 1;
    int jurus;
    int bilanganPrima = 2;

    while(murid <= N) {
        // printf("%d %d\n", murid, jurus);
        while(ialahBilanganPrima(bilanganPrima) == 0) {
            bilanganPrima++;
        }

        jurus = murid * bilanganPrima;

        printf("%d %d\n", murid, jurus);
        bilanganPrima++;
        murid++;
    }
    return 0;
}