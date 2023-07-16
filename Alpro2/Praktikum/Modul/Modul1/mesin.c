#include "header.h"
void cari(int x, struct matriks arr, int a[]) { 
    int i = 0, j, ditemukan = 0;
    while(i < arr.n && ditemukan == 0) { // looping hingga ditemukan
        j = 0;
        while(j < arr.m && ditemukan == 0) {
            if(arr.arr[i][j] == x) {
                a[0] = i; // masukkan nilai baris
                a[1] = j; // masukkan nilai kolom
                ditemukan = 1; // tandai karena ditemukan
            }
            j++;
        }
        i++;
    }
}

int banding(struct matriks arr1, struct matriks arr2) {
    if(arr1.n != arr2.n && arr1.m == arr2.m) {
        return 0; // karena ordonya berbeda, matriks pasti berbeda
    } else {
        int i = 0, j;
        while(i < arr1.n) {
            while(j < arr1.m) {
                if(arr1.arr[i][j] != arr2.arr[i][j]) {
                    return 0; // karena ditemukan nilai berbeda, matriks berbeda
                }
                j++;
            }
            i++;
        }
        return 1; // karena tidak ditemukan nilai berbeda, matriks sama
    }
}