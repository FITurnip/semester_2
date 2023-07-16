#include "header.h"
int main() {
    int banyakTiga;
    int konstanta;
    int valid;

    scanf("%d", &banyakTiga);

    Tiga tiga[banyakTiga];

    for(int i = 0; i < banyakTiga; i++) {
        for(int j = 0; j < 3; j++) {
            scanf("%d", &tiga[i].arr[j]);
        }
    }

    scanf("%d", &konstanta);

    for(int i = 0; i < banyakTiga; i++) {
        urutkanArray(tiga[i].arr);
    }

    valid = kevalidan(konstanta, banyakTiga, tiga);
    
    for(int i = 0; i < banyakTiga; i++) {
        for(int j = 0; j < 3; j++) {
            if(j > 0) printf(" ");
            printf("%d", tiga[i].arr[j]);
        }
        printf("\n");
    }

    if(valid == 0) {
        printf("tidak ");
    }
    
    printf("valid\n");

    return 0;
}