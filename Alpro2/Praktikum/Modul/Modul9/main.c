#include <stdio.h>
#include "header.h"

int main() {
    // deklarasi variabel pita
    char pita[50];
    int banyakSukuKata = 0;
    int valid = 0;
    char temp;

    // meminta masukan pita
    printf("Masukan pita : ");
    scanf("%49[^\n]s", pita);

    // memulai mesin dan membaca pita
    START(pita);
    do {
        temp = GETCC();
        switch(valid) {
            case 0:
            if(temp == 'm') {
                valid++;
            }
            break;
            case 1:
            if(temp == 'a') {
                banyakSukuKata++;
            }
            valid = 0;
            break;
        }
        printf("%c", temp);
        INC(pita);
    } while (EOP() == 0);

    printf("\n");

    printf("Jumlah suku kata: %d\n", banyakSukuKata);

    return 0;
}