#include <stdio.h>
#include "header.h"
void scanning(struct matriks *arr) { // untuk menginput nilai matriks dengan ordo n * m
    scanf("%d %d", &(*arr).n, &(*arr).m);
    
    for(int i = 0; i < (*arr).n; i++) {
        for(int j = 0; j < (*arr).m; j++) {
            scanf("%d", &(*arr).arr[i][j]);
        }
    }
}

int main() {
    struct matriks arr1; // Inisiasi matriks arr1
    scanning(&arr1); // Input matriks pertama
    int p;
    scanf("%d", &p); // input menu
    switch(p) {
        case 1:
        int x;
        scanf("%d", &x); // input nilai yang dicari
        int a[2] = {-1, -1};
        cari(x, arr1, a); // cari x pada arr1
        printf("Letak dari nilai 4 pada matriks yaitu baris ke-%d dan kolom ke-%d\n", a[0] + 1, a[1] + 1);
        break;
        case 2:
        scanf("%d", &x); // input konstanta
        for(int i = 0; i < arr1.n; i++) {
            for(int j = 0; j < arr1.m; j++) {
                printf("%d ", x * arr1.arr[i][j]); // tampilkan nilai matriks langsung dikalikan konstanta
            }
            printf("\n");
        }
        break;
        case 3:
        for(int i = 0; i < arr1.m; i++) { // looping terhadap kolom
            for(int j = 0; j < arr1.n; j++) { // looping terhadap baris
                printf("%d ", arr1.arr[j][i]);
            }
            printf("\n");
        }
        break;
        case 4:
        for(int i = arr1.n - 1; i >= 0; i--) { // looping secara descending
            for(int j = arr1.m - 1; j >= 0; j--) {
                printf("%d ", arr1.arr[i][j]);
            }
            printf("\n");
        }
        break;
        case 5:
        struct matriks arr2;
        scanning(&arr2); // input matriks ke-dua
        if(banding(arr1, arr2) == 1) printf("Kedua matriks memiliki nilai yang sama!\n");
        else printf("Kedua matriks memiliki nilai yang berbeda!\n");
        break;
    }
    return 0;
}