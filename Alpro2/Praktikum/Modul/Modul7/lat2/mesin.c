#include "header.h"

int binarySearch(int n, Mahasiswa arr[], char target[]) {
    int kiri = 0, kanan = n - 1, tengah;
    int ditemukan = 0;
    int komp;
    int posisi = -1;

    while(ditemukan == 0 && kiri <= kanan) {
        tengah = (kiri + kanan) / 2;
        
        komp = strcmp(arr[tengah].nim, target);
        if(komp != 0) {
            if(komp > 0) {
                kanan = tengah - 1;
            } else {
                kiri = tengah + 1;
            }
        } else {
            ditemukan = 1;
        }
    }

    if(ditemukan != 0) {
        posisi = tengah;
    }

    return posisi;
}