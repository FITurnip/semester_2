/*
    Saya Franklin Impianro Turnip(2203211) mengerjakan evaluasi UTS dalam mata kuliah Alpro II untuk keberkahanNya
    maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/
// PENGGUNAAN LIBRARY
#include <stdio.h>
#include <string.h>

typedef struct { // Menyimpan kandungan/berat emas
    int emas;
    int campuran;
    int katalis;
    int lainnya;
} Berat;

typedef struct { // Menyimpan kode nama dan berat emas
    char kodeNama[51];
    Berat berat;
} Emas;

void hitungKemurniaanEmas(Emas *src); // menghitung kemurnian emas
void scanElement(int n, Emas *emas); // menginputkan n elemen emas
int komparasi(int p, int q); // mengembalikan nilai flag lebih besar p atau q
void tukar(Emas *p, Emas *q); // menukarkan data emas p dan q
// Sorting
void quicksort(Emas arr[], int kiri, int kanan); // sorting dari index kiri sampai kanan
void insertionSort(int n, Emas *arr); // sorting seluruh arr
void selectionSort(int n, Emas arr[n]); // sorting seluruh arr
void bubbleSort(int n, Emas arr[n]); // sorting seluruh arr
void merge(Emas arr1[], int n1, Emas arr2[], int n2, Emas arr3[]); // merge arr1 dan arr2 ke dalam arr3
