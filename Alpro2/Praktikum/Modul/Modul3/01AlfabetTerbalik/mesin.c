#include "header.h"
void tampilkan(char alfabet, int baseCase) {
    if(alfabet >= 'A' && alfabet <= 'Z') {
        tampilkan(alfabet + 1, 0);
        printf("%c", alfabet);

        if(baseCase == 0) {
            printf(" ");
        } else {
            printf("\n");
        }
    }
}