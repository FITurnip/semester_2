/*
    Saya Franklin Impianro Turnip(2203211) mengerjakan evaluasi TP1 dalam mata kuliah Alpro II untuk keberkahanNya
    maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/
// PENGGUNAAN LIBRARY
#include <stdio.h> // Keperluan IO
/*
    keseragaman parameter
    N dan M adalah ordo matriks
    x adalah besar asli array p
*/
// Struct
typedef struct{ // Menampung ordo matriks N * M
    int N, M;
} Ordo;
// Procedure & Function
void tampilkan(Ordo ordoMatriks, int x, int p[x][x]); // Menampilkan matriks p dengan ordo N*M
void salin(Ordo ordoMatriks[], int x, int p[x][x], int q[x][x]); // Salinan p disimpan di q
void rotasi(Ordo *ordoMatriks, int x, int p[x][x], int putaran); // Rotasikan p sebanyak putaran kali
int banding(Ordo ordoMatriks[], int x, int p[x][x], int q[x][x]); // Cek kesamaan matriks p dan q
void refleksi(Ordo ordoMatriks, int x, int p[x][x]); // Refleksikan matriks p
void transpose(Ordo *ordoMatriks, int x, int p[x][x]); // Transpose matriks p