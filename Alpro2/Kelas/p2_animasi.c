#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void tukar(char *p, char*q) {
    char temp;
    temp = *p;
    *p = *q;
    *q = temp;
}
void wait(float x) {
    time_t start;
    time_t current;
    time(&start);
    do {
        time(&current);
    } while(difftime(current, start) < x);
}
int main() {
    int N, M;
    printf("Masukkan besar matriks: ");
    scanf("%d %d", &N, &M);

    char matriks[N][M];
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            matriks[i][j] = ' ';
        }
    }

    matriks[0][0] = '#';

    int x = 0, y = 0, k = 1;

    while(1) {
        system("clear");
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) printf("%c", matriks[i][j]);
            printf("\n");
        }
        matriks[x][y] = ' ';
        if(x == 0 || y == 0) k = 1;
        else if(x == N - 1 || y == M - 1) k = -1;
        x += k;
        y += k;
        matriks[x][y] = '#';

        wait(0.0000001);
    }
    return 0;
}