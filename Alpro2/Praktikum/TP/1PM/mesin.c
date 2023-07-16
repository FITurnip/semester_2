/*
    Saya Franklin Impianro Turnip(2203211) mengerjakan evaluasi TP1 dalam mata kuliah Alpro II untuk keberkahanNya
    maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/
// PENGGUNAAN LIBRARY
#include "header.h"

// ISI LIBRARY
void tampilkan(Ordo ordoMatriks, int x, int p[x][x]) {
    for(int i = 0; i < ordoMatriks.N; i++) {
        for(int j = 0; j < ordoMatriks.M; j++) {
            if(j > 0) printf(" "); // Ditampilkan demikian agar tidak muncul pada akhir elemen tiap baris
            printf("%d", p[i][j]); // Tampilkan elemen matriks p pada baris ke-i dan kolom ke-j
        }
        printf("\n"); // Tampilkan baris baru
    }
}

void tukar(int *p, int *q) { // MENUKAR NILAI P DAN Q
    // DEKLARASI VARIABLE
    int temp;

    // TUKAR DENGAN CARA MENGGUNAKAN 3 VARIABLE
    temp = *p;
    *p = *q;
    *q = temp;
}

void salin(Ordo ordoMatriks[], int x, int p[x][x], int q[x][x]) {
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

void rotasi(Ordo *ordoMatriks, int x, int p[x][x], int putaran) {
    if(putaran > 0) { // Eksekusi jika bukan putaran lebih dari 0 karena putaran 0 berarti tidak terjadi rotasi
        // DEKLARASI VARIABLE
        int temp[x][x]; // Array berukuran x*x untuk menampung matriks acuan
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

int banding(Ordo ordoMatriks[], int x, int p[x][x], int q[x][x]) {
    // DEKLARASI VARIABLE
    int sama = 0; // Nilai bolean kesamaan matriks
    if(ordoMatriks[0].N == ordoMatriks[1].N && ordoMatriks[0].M == ordoMatriks[1].M) { // Jika ordo kedua matriks tidak sama, dipastikan kedua matriks tidak sama
        sama = 1; // Ganti nilai karena nilai akan berubah jika ditemukan ketidaksamaan nilai elemen yang berada pada posisi sama

        // DEKLARASI VARIABLE
        // Di dalam percabangan agar tidak menghamburkan memory jika tidak digunakan
        int i = 0, j; // Iterator terhadap baris(i) dan kolom(j)
        while(i < ordoMatriks[0].N && sama == 1) { // Dieksekusi jika belum ditemukan ketidaksamaan nilai elemen yang berada pada posisi sama
            j = 0;
            while(j < ordoMatriks[0].M && sama == 1) { // Dieksekusi jika belum ditemukan ketidaksamaan nilai elemen yang berada pada posisi sama
                if(p[i][j] != q[i][j]) sama = 0; // Jika ditemukan ketidaksamaan, isi dengan nilai false
                j++; // Iterasi
            }
            i++; // Iterasi
        }
    }
    return sama; // Kembalikan nilai bolean
}

void refleksi(Ordo ordoMatriks, int x, int p[x][x]) {
    for(int i = 0; i < ordoMatriks.N; i++) {
        for(int j = ordoMatriks.M / 2; j < ordoMatriks.M; j++) { // Looping dari tengah karena kita akan menukar satu kali antara ujung dan pangkal nilai elemen per baris
            tukar(&p[i][j], &p[i][ordoMatriks.M - j - 1]); // Tukar nilai tersebut
        }
    }
}

void transpose(Ordo *ordoMatriks, int x, int p[x][x]) {
    // Matriks yang belum dan sudah ditranspose jika ditempuk dalam array, menghasilkan array yang besarnya x,
    // sehingga iterator i berkaitan dengan x karena matriks akan seolah-olah ditumpuk
    for(int i = 0; i < x; i++) {
        for(int j = 0; j <= i; j++) { // sampai i + 1 karena hendak membagi dua array secara diagonal
            tukar(&p[i][j], &p[j][i]); // Tukar nilai secara diagonal karena pola transpose juga seolah-olah menukarkan nilai secara transpose
        }
    }

    tukar(&(*ordoMatriks).N, &(*ordoMatriks).M); // Isikan nilai ordo yang baru
}