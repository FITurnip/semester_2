#include <stdio.h>
typedef struct{
    int elemen[2][2];
    int banyakRotasi;
} Matriks;
void scanMatriks(int N, Matriks matriks[N]);
void rotasikanMatriks(Matriks *matriks);
void quickSort(int kiri, int kanan, int N, Matriks matriks[N]);
void insertionSort(int N, Matriks matriks[N]);
void selectionSort(int N, Matriks matriks[N]);
void tampilkan(int N, Matriks matriks[N]);