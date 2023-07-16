#include "header.h"
int komp(Mahasiswa a, Mahasiswa b) {
    if(strcmp(a.nama, b.nama) < 0) {
        return 1;
    } else if(strcmp(a.nama, b.nama) == 0 && strcmp(a.nim, b.nim) > 0) {
        return 1;
    } else {
        return 0;
    }
}

void merge(Mahasiswa arr1[], int n1, Mahasiswa arr2[], int n2, Mahasiswa arr3[]) {
    int i1 = 0, i2 = 0, i3 = 0;

    // ulangi hingga arr1 habis atau arr2 habis
    while ((i1 < n1) && (i2 < n2)) {
        // jika elemen teratas arr1 lebih kecil dari arr2
        if (komp(arr1[i1], arr2[i2]) == 1) {
            // masukkan elemen teratas arr1 ke dalam arr3
            arr3[i3] = arr1[i1];
            i3++;
            i1++;
        }
        // jika elemen teratas arr1 lebih besar dari arr2
        else {
            // masukkan elemen teratas arr2 ke dalam arr3
            arr3[i3] = arr2[i2];
            i3++;
            i2++;
        }
    }

    // masukkan sisa arr1 jika ada
    while(i1 < n1) {
        arr3[i3] = arr1[i1];
        i3++;
        i1++;
    }
    // masukkan sisa arr2 jika ada
    while(i2 < n2) {
        arr3[i3] = arr2[i2];
        i3++;
        i2++;
    }
}

void qsTengah(Mahasiswa arr[], int kiri, int kanan) {
    int i, j;
    Mahasiswa temp, pivot;
    i = kiri, j = kanan;
    pivot = arr[(kanan + kiri) / 2];
    do {
        while (komp(arr[i], pivot) == 1 && (i <= j)) {
            i++;
        }

        while (komp(pivot, arr[j]) == 1 && (i <= j)) {
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
    
    if (kiri < j && j < kanan) {
        qsTengah(arr, kiri, j);
    }
    if (i < kanan && i > kiri) {
        qsTengah(arr, i, kanan);
    }
}

void scanElement(int n, Mahasiswa arr[]) {
    for(int i = 0; i < n; i++) {
        scanf(" %s %s", arr[i].nama, arr[i].nim);
    }
}