/*
    Saya Franklin Impianro Turnip(2203211) mengerjakan evaluasi Kuis 1 dalam mata kuliah Alpro II untuk keberkahanNya
    maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/
// PENGGUNAAN LIBRARY
#include "header.h"

// MAIN
int main() {
    // DEKLARASI VARIABLE
    Ordo ordoMatriks[2]; // Menyimpan nilai ordo matriks utama pada indeks ke-0 dan matriks bagian pada indeks ke-1
    int putaran; // Menyimpan nilai banyak putaran pada matriks bagian

    // MEMINTA MASUKAN DARI USER
    scanf("%d %d", &ordoMatriks[0].N, &ordoMatriks[0].M); // Nilai ordo matriks utama

    // DEKLARASI VARIABLE
    RGB matriksUtama[ordoMatriks[0].N][ordoMatriks[0].M]; // Menyimpan nilai RGB pada matriks utama

    // MEMINTA MASUKAN DARI USER
    for(int i = 0; i < ordoMatriks[0].N; i++) {
        for(int j = 0; j < ordoMatriks[0].M; j++) {
            // Meminta nilai rgb yang akan disimpan pada matriks dengan indeks i sebagai baris dan j sebagai kolom
            scanf("%d %d %d", &matriksUtama[i][j].r, &matriksUtama[i][j].g, &matriksUtama[i][j].b);
        }
    }

    // MEMINTA MASUKAN DARI USER
    scanf("%d", &ordoMatriks[1].N); // Meminta nilai banyak baris pada matriks bagian
    ordoMatriks[1].M = ordoMatriks[1].N; // Karena ordo sebesar m*m, maka nilai ordo disamakan pada matriks bagian
    
    // DEKLARASI VARIABLE
    RGB matriksBagian[ordoMatriks[1].N][ordoMatriks[1].N]; // Menyimpan nilai rgb pada matriks bagian
    Posisi ref[ordoMatriks[1].N][ordoMatriks[1].N]; // Menyimpan posisi/indeks elemen sebagai rujukan

    // MEMINTA MASUKAN DARI USER
    for(int i = 0; i < ordoMatriks[1].N; i++) {
        for(int j = 0 ; j < ordoMatriks[1].N; j++) {
            // Meminta nilai indeks sebagai rujukan untuk pengisian elemen pada matriks bagian
            scanf("%d %d", &ref[i][j].posB, &ref[i][j].posK);
        }
    }

    scanf("%d", &putaran); // Nilai banyak putaran pada matriks bagian

    // PENGOLAHAN DATA
    for(int i = 0; i < ordoMatriks[1].N; i++) {
        for(int j = 0; j < ordoMatriks[1].M; j++) {
            // Elemen matriks bagian pada baris ke-i kolom ke-j merujuk pada
            // elemen matriks utama yang posisinya merujuk pada elemen di ref
            matriksBagian[i][j] = matriksUtama[ref[i][j].posB][ref[i][j].posK];
        }
    }


    putaran %= 4; // Setiap kelipatan 4, matriks dianggap tidak berputar sehingga tercipta pola putaran mod 4

    // Putar matriks bagian sebanyak putaran
    rotasi(&ordoMatriks[1], ordoMatriks[1].N, matriksBagian, putaran);

    // Tampilkan matriks bagian yang telah diputar
    for(int i = 0; i < ordoMatriks[1].N; i++) {
        for(int j = 0; j < ordoMatriks[1].M; j++) {
            printf("%d %d %d\n", matriksBagian[i][j].r, matriksBagian[i][j].g, matriksBagian[i][j].b);
        }
    }
    return 0;
}