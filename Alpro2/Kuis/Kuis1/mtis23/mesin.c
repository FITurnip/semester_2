/*
    Saya Franklin Impianro Turnip(2203211) mengerjakan evaluasi Kuis 1 dalam mata kuliah Alpro II untuk keberkahanNya
    maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/
// PENGGUNAAN LIBRARY
#include "header.h"
void tukar(int *p, int *q) { // MENUKAR NILAI P DAN Q
    // DEKLARASI VARIABLE
    int temp;

    // TUKAR DENGAN CARA MENGGUNAKAN 3 VARIABLE
    temp = *p;
    *p = *q;
    *q = temp;
}

void salin(Ordo ordoMatriks[], int x, RGB p[x][x], RGB q[x][x]) { // MENYALIN MATRIKS P KE Q
    // Salin ordo p ke q
    ordoMatriks[1].N = ordoMatriks[0].N;
    ordoMatriks[1].M = ordoMatriks[0].M;

    // Salin matriks p ke q
    for(int i = 0; i < ordoMatriks[1].N; i++) {
        for(int j = 0; j < ordoMatriks[1].M; j++) {
            q[i][j] = p[i][j];
        }
    }
}

void rotasi(Ordo *ordoMatriks, int x, RGB p[x][x], int putaran) { // Pada mesin, parameter putaran merujuk pada banyak lagi putaran yang mesti dilakukan
    if(putaran > 0) { // Eksekusi jika bukan putaran lebih dari 0 karena putaran 0 berarti tidak terjadi rotasi
        // DEKLARASI VARIABLE
        RGB temp[x][x]; // Array berukuran x*x untuk menampung matriks acuan
        Ordo ordoBaru[2] = {{(*ordoMatriks).N, (*ordoMatriks).M}, {-1, -1}}; // Array untuk memenuhi keseragaman parameter procedure salin
        int n = (*ordoMatriks).N - 1, m = 0; // Iterator terhadap matriks acuan
        salin(ordoBaru, x, p, temp); // Salin p ke temp karena algoritma yang diambil adalah memasukkan nilai elemen posisi awal ke posisi baru

        tukar(&(*ordoMatriks).N, &(*ordoMatriks).M); // Tukar ordo matriks yang diolah karena rotasi mengakibatkan nilai ordo bertukar
        for(int i = 0; i < (*ordoMatriks).N; i++) { // Looping sesuai ordo terbaru sebagai acuan matriks baru
            for(int j = 0; j < (*ordoMatriks).M; j++) {
                p[i][j] = temp[n][m];

                // Iterasi m bergantung pada iterasi n
                n--;
                if(n < 0) {
                    n = ordoBaru[1].N - 1;
                    m++;
                }
            }
        }

        rotasi(&(*ordoMatriks), x, p, putaran - 1); // Panggil lagi fungsi rotasi agar dapat berotasi sebanyak putaran kali
    }
}