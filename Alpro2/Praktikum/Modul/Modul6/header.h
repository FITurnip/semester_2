#include <stdio.h>
#include <string.h>

typedef struct {
    char nama[100], nim[8];
} Mahasiswa;

int komp(Mahasiswa a, Mahasiswa b);
void merge(Mahasiswa arr1[], int n1, Mahasiswa arr2[], int n2, Mahasiswa arr3[]);
void qsTengah(Mahasiswa arr[], int kiri, int kanan);
void scanElement(int n, Mahasiswa arr[]);