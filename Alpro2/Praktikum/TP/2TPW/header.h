/*
    Saya Franklin Impianro Turnip(2203211) mengerjakan evaluasi TP2 dalam mata kuliah Alpro II untuk keberkahanNya
    maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/
// PENGGUNAAN LIBRARY
#include <stdio.h> // IO
#include <string.h> // String

// STRUCT
typedef struct { // Data Wisudawan
    char nama[102]; // Nama Wisudawan
    int ukuranToga; // Ukuran Toga Wisudawan
} Wisudawan;

typedef struct { // Data Wisudawan yang hendak ditukar
    char nama[102]; // Nama Wisudawan
    int posisi[2]; // Posisi Wisudawan
} Ditukar;

typedef struct { // Data Ukuran Standar Toga
    char kode[6]; // Kode ukuran
    int ukuran; // Ukuran standar
} StandarToga;

// DAFTAR FUNGSI DAN PROCEDURE
// Menukar posisi wisudawanA dan wisudawanB
void tukarPosisi(Wisudawan *wisudawanA, Wisudawan *wisudawanB);

// Wisudawan yang berada di depan diposisikan di indeks 0 pada array ditukar
void urutkanDitukar(Ditukar ditukar[2]);

// Mencari posisi wisudawan yang kemudian posisi diisi pada struct ditukar
void cariPosisiNama(int baris, int kolom, Wisudawan wisudawan[baris][kolom], Ditukar ditukar[2]);

// Mengembalikan nilai ukuran standar berdasarkan kodeDiberikan
int standarisasiUkuranToga(StandarToga standarToga[7], char kodeDiberikan[]);

// Menampilkan nama-nama wisudawan berdasarkan posisi
void tampilkanWisudawan(int baris, int kolom, Wisudawan wisudawan[baris][kolom]);