#include "header.h"
int tukar(int *p, int *q) {
    int temp = *p;
    *p = *q;
    *q = temp;
}
int cariNama(char nama[], int N, int M, dataMahasiswa mhs[N][M]) {
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
void cariNilai(int N, int M, dataMahasiswa mhs[N][M]) {
    int maks = 0;
    char nama[100];
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(mhs[i][j].nilai > maks) {
                maks = mhs[i][j].nilai;
                strcpy(nama, mhs[i][j].nama);
            }
        }
    }
    
    printf("%s %d\n", nama, maks);
}