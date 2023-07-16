/*
    Saya Franklin Impianro Turnip(2203211) mengerjakan evaluasi Kuis 1 dalam mata kuliah Alpro II untuk keberkahanNya
    maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/
// PENGGUNAAN LIBRARY
#include <stdio.h> // Keperluan IO

// STRUCT
typedef struct{ // Menampung ordo matriks N * M
    int N, M;
} Ordo;

typedef struct { // Menampung nilai RGB
    int r, g, b;
} RGB;

typedef struct { // Menampung posisi baris dan kolom
    int posB, posK;
} Posisi;

// PROCEDURE
void rotasi(Ordo *ordoMatriks, int x, RGB p[x][x], int putaran); // Memutar matriks P dengan ordo x * x sebanyak putaran