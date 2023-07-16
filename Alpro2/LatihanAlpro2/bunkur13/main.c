#include "header.h"
int main() {
    char metodePengurutan[100];
    int N, M;
    scanf(" %s %d", metodePengurutan, &N);
    Matriks matriksA[N];
    scanMatriks(N, matriksA);

    scanf("%d", &M);
    scanf("%d", &M);
    Matriks matriksB[M];
    scanMatriks(M, matriksB);

    Matriks matriks[N + M];

    for(int i = 0; i < N; i++) {
        urutkanMatriks(&matriksA[i]);
        matriks[i] = matriksA[i];
        matriks[i].elemen[1][1] *= matriks[i].konstanta;
    }

    for(int i = 0; i < M; i++) {
        urutkanMatriks(&matriksB[i]);
        matriks[i + N] = matriksB[i];
        matriks[i + N].elemen[1][1] *= matriks[i + N].konstanta;
    }

    switch(metodePengurutan[0]) {
        case 'q':
        quickSort(0, N + M - 1, N + M, matriks);
        break;
        case 'i':
        insertionSort(N + M, matriks);
        break;
        case 's':
        selectionSort(N + M, matriks);
        break;
    }

    tampilkan(N + M, matriks);
    return 0;
}