#include "header.h"
int berupaBilPrima(int n) {
    int benar = 1;
    if(n >= 2) {
        int i = 2;
        while(i * i <= n && benar == 1) {
            if(n % i == 0) {
                benar = 0;
            }
            i++;
        }
    } else {
        benar = 0;
    }

    return benar;
}

void konversiKeDigit(int n, Digit *digit) {
    int i = 0;

    while(n != 0) {
        (*digit).bil[i] = n % 10;
        n /= 10;
        i++;
    }

    (*digit).banyak = i;
}

void tukar(int *p, int *q) {
    int temp = (*p);
    (*p) = (*q);
    (*q) = temp;
}

void permutasikan(Digit digit, Permutasi *permut, int idxKiri) {
    if(idxKiri != digit.banyak - 1) {
        for(int i = idxKiri; i < digit.banyak; i++) {
            tukar(&digit.bil[i], &digit.bil[idxKiri]);
            permutasikan(digit, permut, idxKiri + 1);
            tukar(&digit.bil[i], &digit.bil[idxKiri]);
        }
    } else {
        (*permut).bil[(*permut).banyak] = digit.bil[0];
        for(int i = 1; i < digit.banyak; i++) {
            (*permut).bil[(*permut).banyak] *= 10;
            (*permut).bil[(*permut).banyak] += digit.bil[i];
        }

        (*permut).banyak++;
    }
}