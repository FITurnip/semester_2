#include "header.h"
void scanMatriks(int N, Matriks matriks[N]) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < 2; j++) {
            for(int k = 0; k < 2; k++) {
                scanf("%d", &matriks[i].elemen[j][k]);
            }
        }
        scanf("%d", &matriks[i].konstanta);
    }
}
void tukarBilangan(int *bilA, int *bilB) {
    int temp = (*bilA);
    (*bilA) = (*bilB);
    (*bilB) = temp;
}

void urutkanMatriks(Matriks *matriks) {
    int minIndeks;
    for(int i = 0; i < 4; i++) {
        minIndeks = i;
        for(int j = i + 1; j < 4; j++) {
            if((*matriks).elemen[j / 2][j % 2] < (*matriks).elemen[minIndeks / 2][minIndeks % 2]) {
                minIndeks = j;
            }
        }
        
        tukarBilangan(&(*matriks).elemen[i / 2][i % 2], &(*matriks).elemen[minIndeks / 2][minIndeks % 2]);
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