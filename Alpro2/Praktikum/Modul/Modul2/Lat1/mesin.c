#include "header.h"
void tampilkanBatas(char jenis) {
    for(int i = 0; i < 23; i++) printf("%c", jenis);
    printf("\n");
} 
void tampilkanIsi(dataWarna tampil) {
    char w[3][6] = {"Merah\0", "Hijau\0", "Biru \0"};
    for(int i = 0; i < 3; i++) printf("Detail Warna %s : %d\n", w[i], tampil.rgb[i]);
}
void cari(char dicari[100], int N, dataWarna arr[N]) {
    int ditemukan = 0;
    int i = 0;
    while(i < N) {
        if(strcmp(dicari, arr[i].warna) == 0) {
            ditemukan = 1;
            tampilkanIsi(arr[i]);
            tampilkanBatas('-');
        }
        i++;
    }

    if(ditemukan == 0) printf("Tidak ada warna %s\n", dicari);
}