/*
    Saya Franklin Impianro Turnip(2203211) mengerjakan evaluasi Kuis 2 dalam mata kuliah Alpro II untuk keberkahanNya
    maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/
// PENGGUNAAN LIBRARY
#include <stdio.h> // Keperluan IO

// LIST STRUCT
typedef struct { // Menyimpan data pegawai
    char no[51]; // nomor pegawai
    char nama[51]; // nama pegawai
    char jabatan[51]; // jabatan pegawai
    long long gaji_pokok; // gaji pokok yang diterima pegawai
    long long tunjangan; // tunjangan yang diterima pegawai
    long long pendapatan; // pendapatan yang diterima pegawai
} Pegawai;

// LIST FUNCTION & PROCEDURE
int komparasi(Pegawai p, Pegawai q, char asasPengurutan); // membandingkan nilai yang ada pada p dan q berdasarkan asas tertentu
void tukar(Pegawai *p, Pegawai *q); // menukar value pada p dan q
void quicksort(Pegawai arr[], int kiri, int kanan, char asasPengurutan); // mengurutkan secara asc berdasarkan asas tertentu
int binarySearch(int kiri, int kanan, Pegawai arr[], long long target, char acuan); // mencari nilai target sesuai dengan acuannya dari index yang ke-kiri hingga ke index yang ke-kanan
void printElement(Pegawai src); // menampilkan satu elemen