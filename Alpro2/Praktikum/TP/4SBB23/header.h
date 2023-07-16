/*
    Saya Franklin Impianro Turnip(2203211) mengerjakan evaluasi TP4 dalam mata kuliah Alpro II untuk keberkahanNya
    maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/
// PENGGUNAAN LIBRARY
#include <stdio.h> // IO
#include <string.h> // Pengolahan String

// STRUCT
typedef struct { // Menampung data identitas siswa
    char nama[100]; // nama siswa
    int pjgNama; // panjang nama siswa
    int umur; // umumr siswa
} IdentitasSiswa;

// PROCEDURE DAN FUCTION
// Pengurutan
void insertionSort(int banyakSiswa, IdentitasSiswa identitasSiswa[banyakSiswa], char acuanSorting[3]);
void selectionSort(int banyakSiswa, IdentitasSiswa identitasSiswa[banyakSiswa], char acuanSorting[3]);

// Penjumlahan ASCII dan Data Umur Seorang Siswa
int jumlahkanASCII(char str[]);
void hitungJumlahASCIUmur(int *jumlahASCII, int *jumlahDataUMur, IdentitasSiswa acuan);

// Mencari Nilai Maks Panjang Nama
int cariMaksPjgStr(int banyakSiswa, IdentitasSiswa identitasSiswa[banyakSiswa]);