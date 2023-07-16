#include <stdio.h>
#include "header.h"

int main() {
    char A, B;
    int a, x, y;
    int map[3][3];
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) map[i][j] = 0;
    }
    for(int i = 0; i < 6; i++) {
        scanf(" %c%d %c %d %d", &A, &a, &B, &x, &y);
        map[x][y] = a;
    }
    int pemenang = 0;
    for(int i = 0; i < 2; i++) {
        pemenang += menang(map, i + 1);
    }
    if(pemenang % 3 == 0) printf("tidak ada\n");
    else printf("P%d\n", pemenang);
    return 0;
}