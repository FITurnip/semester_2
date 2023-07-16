#include <stdio.h>
#include <string.h>
typedef struct{
    char nama[100];
    int nilai;
} dataMahasiswa;
int tukar(int *p, int *q);
int cariNama(char nama[], int N, int M, dataMahasiswa mhs[N][M]);
int bagi(int p, int q);
int mod(int p, int q);
void cariNilai(int N, int M, dataMahasiswa mhs[N][M]);