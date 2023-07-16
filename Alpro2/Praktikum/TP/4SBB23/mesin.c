/*
    Saya Franklin Impianro Turnip(2203211) mengerjakan evaluasi TP4 dalam mata kuliah Alpro II untuk keberkahanNya
    maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/
// PENGGUNAAN LIBRARY
#include "header.h"

// PROCEDURE DAN FUNCTION
// Mencari tahu apakah p dan q sudah terurut dengan acuan tertentu
int apakahTerurut(IdentitasSiswa p, IdentitasSiswa q, char acuanSorting[4]) {
    // Deklarasi Variable
    int berurutan; // Flag 0 berarti tidak terurut, 1 berarti terurut

    // Mencari tahu apakah kondisi terurut secara asceding
    if(acuanSorting[1] == 'N') { // Acuan berupa nama
        if(strcmp(p.nama, q.nama) < 0) {
            berurutan = 0;
        } else {
            berurutan = 1;
        }
    } else { // Acuan berupa umur
        if(p.umur < q.umur) {
            berurutan = 0;
        } else {
            berurutan = 1;
        }
    }

    // Jika acuannya desceding, maka balikkan nilai flag
    if(acuanSorting[0] == 'D') {
        if(berurutan == 0) {
            berurutan = 1;
        } else {
            berurutan = 0;
        }
    }

    return berurutan; // Kembalikan nilai flag
}

// Menukar isi struct identitasSiswa p dan q
void tukar(IdentitasSiswa *p, IdentitasSiswa *q) {
    IdentitasSiswa temp = (*p);
    (*p) = (*q);
    (*q) = temp;
}

// insertionSort dan selectionSort mengurutkan array identitasSiswa dengan aucan tertentu
void insertionSort(int banyakSiswa, IdentitasSiswa identitasSiswa[banyakSiswa], char acuanSorting[4]) {
    // Deklarasi Variable
    int i, j; // Iterator
    IdentitasSiswa temp; // Penampungan sementara IdentitasSiswa

    // Urutkan dengan algoritma insertion sort
    for(i = 1; i < banyakSiswa; i++) {
        j = i - 1;
        temp = identitasSiswa[i];

        while(j >= 0 && apakahTerurut(temp, identitasSiswa[j], acuanSorting) == 0) {
            identitasSiswa[j + 1] = identitasSiswa[j];
            j--;
        }

        identitasSiswa[j + 1] = temp;
    }
}

void selectionSort(int banyakSiswa, IdentitasSiswa identitasSiswa[banyakSiswa], char acuanSorting[4]) {
    // Deklarasi Variable
    int i, j; // Iterator
    int idxMin; // Menampung nilai index minimum

    // Urutkan dengan algoritma insertion sort
    for(i = 0; i < banyakSiswa - 1; i++) {
        idxMin = i;
        for(j = i + 1; j < banyakSiswa; j++) {
            if(apakahTerurut(identitasSiswa[j], identitasSiswa[idxMin], acuanSorting) == 0) {
                idxMin = j;
            }
        }
        tukar(&identitasSiswa[i], &identitasSiswa[idxMin]);
    }
}

// Menghitung jumlah ASCII string
int jumlahkanASCII(char str[]) {
    // Deklarasi Variable
    int panjangStr = strlen(str); // Menampung panjang string str
    int jumlahASCII = 0; // Menyimpan nilai ASCII string str

    // Iterasi sampai semua karakter pada str habis diolah
    for(int i = 0; i < panjangStr; i++) {
        jumlahASCII += str[i]; // Tambahkan dengan nilai ASCII karaket str ke-i
    }

    return jumlahASCII; // Kembaikan nilai jumlahASCII
}

// Menghitung jumlah ASCII dan data umur siswa(acuan)
void hitungJumlahASCIUmur(int *jumlahASCII, int *jumlahDataUMur, IdentitasSiswa acuan) {
    (*jumlahASCII) += jumlahkanASCII(acuan.nama); // Jumlahkan ASCII nama siswa acuan
    (*jumlahDataUMur) += acuan.umur; // Jumlahkan data umur siswa acuan
}

// Mencari nilai maks panjang string dari nama-nama siswa
int cariMaksPjgStr(int banyakSiswa, IdentitasSiswa identitasSiswa[banyakSiswa]) {
    // Deklarasi Variable
    int maks = 0; // Menampung nilai semenatara maks panjang string panjang

    // Iterasi hingga semua panjang nama siswa telah diperiksa
    for(int i = 0; i < banyakSiswa; i++) {
        if(maks < identitasSiswa[i].pjgNama) { // Perbarui nilai maks, jika ditemukan nilai yang lebih besar sejauh ini
            maks = identitasSiswa[i].pjgNama;
        }
    }

    return maks; // Kembalikan nilai maks panjang str
}