#include "header.h"
int komp(Pecahan a, Pecahan b) {
    if(a.pmb * b.pny < b.pmb * a.pny) {
        return 1;
    } else {
        return 0;
    }
}

void qsTengah(Pecahan arr[], int kiri, int kanan) {
    int i, j;
    Pecahan temp, pivot;
    i = kiri, j = kanan;
    pivot = arr[(kanan + kiri) / 2];
    do {
        while (komp(arr[i], pivot) == 1 && (i <= j)) { // (arr[i] < pivot)
            i++;
        }

        while (komp(pivot, arr[j]) == 1 && (i <= j)) { // (arr[j] > pivot)
            j--;
        }
        
        if (i < j) {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    } while (i < j);
    // printArr(arr);
    if (kiri < j && j < kanan) {
        qsTengah(arr, kiri, j);
    }
    if (i < kanan && i > kiri) {
        qsTengah(arr, i, kanan);
    }
}

void bubbleSort(Pecahan arr[], int n) {
    int key, i, j, swap;
    Pecahan temp;

    do {
        swap = 0; // inisialisasi
        for (i = 0; i < n - 1; i++)
        { // jika data i lebih besar dari i+1
            if (komp(arr[i + 1], arr[i]) == 1)
            { // tukar data
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;


                // tanda bahwa ada data yang ditukar
                swap = 1;
            }
        }
    } while (swap  == 1);
}