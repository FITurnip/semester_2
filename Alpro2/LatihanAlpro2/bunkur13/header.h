#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int elemen[2][2];
    int konstanta;
} Matriks;
void scanMatriks(int N, Matriks matriks[N]);
void urutkanMatriks(Matriks *matriks);
void quickSort(int kiri, int kanan, int N, Matriks matriks[N]);
void insertionSort(int N, Matriks matriks[N]);
void selectionSort(int N, Matriks matriks[N]);
void tampilkan(int N, Matriks matriks[N]);