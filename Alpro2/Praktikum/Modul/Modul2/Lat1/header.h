#include <stdio.h>
#include <string.h>
typedef struct{
    char warna[100];
    int rgb[3];
} dataWarna;
void tampilkanBatas(char jenis);
void cari(char dicari[100], int N, dataWarna arr[N]);