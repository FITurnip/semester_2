#include "header.h"

int main() {
    int banyakPecahan;
    int cari;
    scanf("%d", &banyakPecahan);

    Pecahan pecahan[banyakPecahan];
    for(int i = 0; i < banyakPecahan; i++) {
        for(int j = 0; j < 4; j++) {
            scanf("%d", &pecahan[i].arr[j]);
        }
    }

    scanf("%d", &cari);

    for(int i = 0; i < banyakPecahan; i++) {
        urutkan(&pecahan[i]);
    }

    int ditemukan = dicari(cari, banyakPecahan, pecahan);

    for(int i = 0; i < banyakPecahan; i++) {
        for(int j = 0; j < 4; j++) {
            if(j > 0) {
                printf(" ");
            }
            printf("%d", pecahan[i].arr[j]);
        }
        printf("\n");
    }

    if(ditemukan == 0) printf("tidak ");
    printf("valid\n");

    return 0;
}