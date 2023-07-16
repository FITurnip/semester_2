#include "header.h"
int kodekanArahMenghadap(char c) {
    int arah;
    switch(c) {
        case 'n':
        arah = 0;
        break;
        case 'e':
        arah = 1;
        break;
        case 's':
        arah = 2;
        break;
        case 'w':
        arah = 3;
        break;
    }

    return arah;
}

void gerakkanRobot(int kodeArahMenghadap, int banyakLangkah, Koordinat *koor) {
    if(kodeArahMenghadap > 1) {
        banyakLangkah *= (-1);
    }

    if(kodeArahMenghadap % 2 == 0) {
        (*koor).y += banyakLangkah;
        if((*koor).y < 0) {
            printf("-1\n");
            (*koor).y = 0;
        } else if((*koor).y > 9) {
            printf("-1\n");
            (*koor).y = 9;
        }
    } else {
        (*koor).x += banyakLangkah;
        if((*koor).x < 0) {
            printf("-1\n");
            (*koor).x = 0;
        } else if((*koor).x > 9) {
            printf("-1\n");
            (*koor).x = 9;
        }
    }
}

void rotasikan(int *kodeArahMenghadap, int banyakRotasi) {
    (*kodeArahMenghadap) = ((*kodeArahMenghadap) + banyakRotasi) % 4;
}

void tampilkan(Koordinat koor) {
    for(int y = 9; y >= 0; y--) {
        for(int x = 0; x <= 9; x++) {
            if(koor.x == x && koor.y == y) {
                printf("o");
            } else {
                printf("x");
            }
        }
        printf("\n");
    }
}