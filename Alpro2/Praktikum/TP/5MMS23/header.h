/*
    Saya Franklin Impianro Turnip(2203211) mengerjakan evaluasi TP5 dalam mata kuliah Alpro II untuk keberkahanNya
    maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/
// PENGGUNAAN LIBRARY
#include <stdio.h> // keperluan IO
#include <string.h> // keperluan mengolah string

// PENGGUNAAN STRUCT
typedef struct { // Untuk menampung satu data sihir
    char namaMantra[102]; // nama mantra
    int mp; // magic power
    int waktu; // waktu yang dibutuhkan agar dapat menguasai sihir tersebut
} Sihir;

// DAFTAR PROCEDURE & FUNGSI YANG DIPAKAI PADA PROGRAM
int pilihMaks(int p, int q); // mengembalikan nilai yang lebih besar antara p dan q
int cariPanjangMaksimumString(int n, Sihir sihir[n]);  // mencari panjang maksimum string dari n data sihir
int hitungBanyakDigit(int n); // mengembalikan nilai banyaknya digit bilangan n
void printElemen(int n, Sihir sihir[n]); // menampilkan data sihir dalam bentuk tabel
int komp(Sihir p, Sihir q, char jenis); // mengembalikan nilai flag yang menjadi acuan apakah p dan q terurut berdasarkan jenis(0) atau tidak(1)
void tukarDataSihir(Sihir *p, Sihir *q); // Tukar data sihir p dan q
void tukarInt(int *p, int *q); // Tukar int sihir p dan q
void bSorting(int n, Sihir arr[n], char jenis); // mengurutkan data arr menggunakan bubble sort
void qsTengah(Sihir arr[], int kiri, int kanan, char jenis); // mengurutkan data arr menggunakan quicksort
void loopingPrint(int n, char c); // menampilkan c sebanyak n secara berurutan
void hitungLebarKolom(int n, Sihir sihir[n], int lebarKolom[4]); // menghitung lebar keempat kolom pada tabel
void borderBaris(int lebarKolom[4]); // menampilkan border baris
int cariMaksSihirYgDptDikuasai(int n, Sihir arr[n], int batasWaktu); // mengembalikan nilai maks sihir yang dapat dikuasai