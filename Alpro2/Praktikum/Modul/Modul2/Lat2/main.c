#include "header.h"
int main() {
    int N, M;
    int pos[2];
    char nama[2][100];
    scanf("%d %d", &N, &M);

    dataMahasiswa mhs[N][M];
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            scanf(" %s %d", mhs[i][j].nama, &mhs[i][j].nilai);
        }
    }

    for(int i = 0; i < 2; i++) scanf(" %s", nama[i]);

    for(int i = 0; i < 2; i++) pos[i] = cari(nama[i], N, M, mhs);
    tukar(&mhs[bagi(pos[0], N)][mod(pos[0], N)].nilai, &mhs[bagi(pos[1], N)][mod(pos[1], N)].nilai);

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            printf("%s %d\n", mhs[i][j].nama, mhs[i][j].nilai);
        }
    }
    return 0;
}