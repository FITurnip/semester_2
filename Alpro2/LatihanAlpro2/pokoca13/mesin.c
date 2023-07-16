#include "header.h"
void tukar(int *A, int *B) {
    int temp = (*A);
    (*A) = (*B);
    (*B) = temp;
}

void urutkanArray(int arr[3]) {
    if(arr[0] > arr[1]) {
        tukar(&arr[0], &arr[1]);
    }
    if(arr[1] > arr[2]) {
        tukar(&arr[1], &arr[2]);
    }
    if(arr[0] > arr[1]) {
        tukar(&arr[0], &arr[1]);
    }
}

int kevalidan(int konstanta, int banyakTiga, Tiga tiga[banyakTiga]) {
    int valid = 0;
    int i = 0;
    while(i < banyakTiga && valid == 0) {
        if(tiga[i].arr[0] * konstanta == tiga[i].arr[2]) {
            valid = 1;
        }
        i++;
    }

    return valid;
}