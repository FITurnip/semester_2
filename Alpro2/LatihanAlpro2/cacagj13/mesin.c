#include "header.h"
void tukar(int *A, int *B) {
    int temp = (*A);
    (*A) = (*B);
    (*B) = temp;
}

void urutkan(Pecahan *pecahan) {
    if((*pecahan).arr[2] * (*pecahan).arr[1] < (*pecahan).arr[3] * (*pecahan).arr[0]) {
        tukar(&(*pecahan).arr[2], &(*pecahan).arr[0]);
        tukar(&(*pecahan).arr[3], &(*pecahan).arr[1]);
    }
}

int dicari(int cari, int banyakPecahan, Pecahan pecahan[banyakPecahan]) {
    int ditemukan = 0;
    int i = 0;
    while(i < banyakPecahan && ditemukan == 0) {
        if(pecahan[i].arr[2] == cari * pecahan[i].arr[3]) {
            if(pecahan[i].arr[0] * pecahan[i].arr[3] * 2 == pecahan[i].arr[2] * pecahan[i].arr[1]) {
                ditemukan = 1;
            }
        }

        i++;
    }

    return ditemukan;
}