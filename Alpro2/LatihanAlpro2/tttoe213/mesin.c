#include "header.h"
int hv(int map[3][3], int a) {
    int h = 0, v = 0;
    int i = 0, j;
    while(i < 3 && h < 3 && v < 3) {
        j = 0;
        while(j < 3 && (h < 3 || v < 3)) {
            if(map[i][j] == a) h++;
            else h == 4;
            if(map[j][i] == a) v++;
            else v == 4;
            j++;
        }
        if(h != 3) h = 0;
        if(v != 3) v = 0;
        i++;
    }
    if(h == 3 || v == 3) return 1;
    else return 0;
}

int miring(int map[3][3], int a) {
    int baris = 0;
    int i = 0, j = 2;
    int d1 = 0, d2 = 0;
    while(baris < 3) {
        if(map[baris][i] == a) d1++;
        if(map[baris][j] == a) d2++;
        i++;
        j--;
        baris++;
    }
    if(d1 == 3 || d2 == 3) return 1;
    else return 0; 
}

int menang(int map[3][3], int a) {
    if(hv(map, a) == 1) return a;
    else if(miring(map, a) == 1) return a;
    else return 0;
}