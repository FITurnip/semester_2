#include "header.h"
int main() {
    int N, M;
    char w[100];

    scanf("%d %d", &N, &M);
    dataWarna matriks[N][M];

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            scanf(" %s", matriks[i][j].warna);
            for(int k = 0; k < 3; k++) {
                scanf(" %d", &matriks[i][j].rgb[k]);
            }
        }
    }

    scanf(" %s", w);

    for(int i = 0; i < N; i++) {
        tampilkanBatas('=');
        printf("Baris %d:\n", i + 1);
        cari(w, M, matriks[i]);
    }
    tampilkanBatas('=');

    return 0;
}