#include "header.h"
int tukar(int *p, int *q) {
    int temp = *p;
    *p = *q;
    *q = temp;
}
int cari(char nama[], int N, int M, dataMahasiswa mhs[N][M]) {
    int pos = -1;
    int i = 0, j;
    while(i < N && pos == -1) {
        j = 0;
        while(j < M && pos == -1) {
            if(strcmp(nama, mhs[i][j].nama) == 0) pos = i * N + j;
            j++;
        }
        i++;
    }
    return pos;
}
int bagi(int p, int q) {
    return p / q;
}
int mod(int p, int q) {
    return p % q;
}