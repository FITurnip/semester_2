#include "header.h"
void tukar(int *A, int *B) {
    int temp = (*A);
    (*A) = (*B);
    (*B) = temp;
}

void insertionSort(int n, int arr[n]) {
    // Deklarasi Variable
    int i, j; // Iterator
    int temp; // Penampungan sementara

    // Urutkan dengan algoritma insertion sort
    for(i = 1; i < n; i++) {
        j = i - 1;
        temp = arr[i];

        while(j >= 0 && temp < arr[j]) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = temp;
    }
}

void konversiKeFormatJam(int jumlahDetik, FormatJam *formatJam) {
    (*formatJam).fj[0] = jumlahDetik / 3600;
    jumlahDetik %= 3600;
    (*formatJam).fj[1] = jumlahDetik / 60;
    jumlahDetik %= 60;
    (*formatJam).fj[2] = jumlahDetik;
}