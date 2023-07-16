#include "header.h"
void scanMatriks(int N, Matriks matriks[N]) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < 2; j++) {
            for(int k = 0; k < 2; k++) {
                scanf("%d", &matriks[i].elemen[j][k]);
            }
        }
        scanf("%d", &matriks[i].banyakRotasi);

        matriks[i].banyakRotasi %= 4;
    }
}

void rotasikanMatriks(Matriks *matriks) {
    while((*matriks).banyakRotasi > 0) {
        Matriks temp = (*matriks);
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 2; j++) (*matriks).elemen[j][1 - i] = temp.elemen[i][j];
        }
        (*matriks).banyakRotasi--;
    }
}

void tukarMatriks(Matriks *matriksA, Matriks *matriksB) {
    Matriks temp = (*matriksA);
    (*matriksA) = (*matriksB);
    (*matriksB) = temp;
}

void quickSort(int kiri, int kanan, int N, Matriks matriks[N]) {
    if(kiri < kanan) {
        int pivot = matriks[(kiri + kanan) / 2].elemen[1][1];

        int iKiri = kiri, iKanan = kanan;
        while(iKiri <= iKanan) {
            while(matriks[iKiri].elemen[1][1] < pivot && iKiri < kanan) {
                iKiri++;
            }

            while(matriks[iKanan].elemen[1][1] > pivot && iKanan > kiri) {
                iKanan--;
            }

            if(iKiri <= iKanan) {
                tukarMatriks(&matriks[iKiri], &matriks[iKanan]);
                iKiri++;
                iKanan--;
            }
        }

        quickSort(kiri, iKanan, N, matriks);
        quickSort(iKiri, kanan, N, matriks);

    }
}

void insertionSort(int N, Matriks matriks[N]) {
    int j;
    for(int i = 1; i < N; i++) {
        j = i;
        while(j > 0 && matriks[j].elemen[1][1] < matriks[j - 1].elemen[1][1]) {
            tukarMatriks(&matriks[j], &matriks[j - 1]);
            j--;
        }
    }
}

void selectionSort(int N, Matriks matriks[N]) {
    int indeksMin;
    for(int i = 0; i < N; i++) {
        indeksMin = i;
        for(int j = i + 1; j < N; j++) {
            if(matriks[j].elemen[1][1] < matriks[indeksMin].elemen[1][1]) {
                indeksMin = j;
            }
        }

        tukarMatriks(&matriks[i], &matriks[indeksMin]);
    }
}

void tampilkan(int N, Matriks matriks[N]) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < 2; j++) {
            for(int k = 0; k < 2; k++) {
                printf("%d", matriks[i].elemen[j][k]);
                if(j != 1 || k != 1) {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
}