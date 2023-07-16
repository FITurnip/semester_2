/*
    Saya Franklin Impianro Turnip(2203211) mengerjakan evaluasi TP5 dalam mata kuliah Alpro II untuk keberkahanNya
    maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/
// PENGGUNAAN LIBRARY
#include <stdio.h> // Keperluan IO
#include <string.h> // Keperluan pengolahan string
// Keperluan terkait dengan sistem
#include <stdlib.h>
#include <time.h>


// PENGGUNAAN STRUCT
typedef struct { // menyimpan data barang berupa nama dengan id-id terkait
    char nama[102];
    char id_kategori[5], id_merk[5], id_toko[5];
} Barang;

typedef struct { // menyimpan data nama beserta idnya
    char id[5];
    char nama[102];
} SimpleData;

typedef struct { // seperti struct Barang, tetapi idnya sudah diganti dengan nama terkait id tersebut
    char nama[102];
    char merk[102];
    char kategori[102];
    char toko[102];
} BarangFinal;

typedef struct { // menyimpan banyaknya data-data struct yang dipakai agar banyaknya parameter pada function atau procedure lebih efisien
    int barang;
    int kategori;
    int merk;
    int toko;
    int barangFinal;
} BanyakData;

// SUB-PROGRAM
// meminta data dari user yang tujuan akhirnya sdimasukkan file terkait
int scanBarang(int akhirPos, char *nama_file, Barang *arr);
int scanSimpleData(int akhirPos, char *nama_file, SimpleData *arr);

// membaca file untuk disimpan ke struct terkait
int bacaFileBarang(char *nama_file, Barang *dst);
int bacaFileSimpleData(char *nama_file, SimpleData *dst);
int bacaFileBarangFinal(char *nama_file, BarangFinal *dst);

// menulis data pada struct ke file
int tulisFileBarang(int n, char *nama_file, Barang *src);
int tulisSimpleData(int n, char *nama_file, SimpleData *src);
int tulisFileBarangFinal(int n, char *nama_file, BarangFinal *src);

// memasukkan data barang ke barang final dengan pembedanya berupa id sudah diganti dengan nama data terkait
int finalisasiBarang(BanyakData banyakData, Barang *srcLB, SimpleData *srcKategori, SimpleData *srcMerk, SimpleData *srcToko, BarangFinal *dst);

// pencarian data
int binarySearch(int kiri, int kanan, SimpleData arr[], char *target);

// menampilkan konten kepada user
void tampilkanData(int n, BarangFinal *src); // tampilkan tabel record data barang
void tampilkanError(int pos, char a[], char b[], char c[], char d[], int jenisError); // tampilkan peringatan error

// tampilkan batasan tabel
void tampilkanBatasHrzTable(int lebarKolom[4]); // batas horizontal pada tabel
void tampilkanHeadertable(int lebarKolom[4]); // header tabel data barang
void tampilkanKolom(int lebarKolom, char str[], char batas, int batasiUjung); // konten pada kolom tertentu beserta batas dan spasinya

// sub-program tambahan
void tunggu(float x); // membekukan tampilan
void jeda(); // menjeda program

void mencariMaksKolom(int banyakBarangFinal, BarangFinal *src, int maksKolom[4]); // mencari maks lebar kolom pada tabel barang final

