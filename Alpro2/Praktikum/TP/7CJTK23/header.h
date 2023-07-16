/*
    Saya Franklin Impianro Turnip(2203211) mengerjakan evaluasi TP5 dalam mata kuliah Alpro II untuk keberkahanNya
    maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/
// PENGGUNAAN LIBRARY
#include <stdio.h>

// PENGGUNAAN STRUCT
typedef struct { // menyimpan data Atom
    char nama[100]; // nama atom
    double no; // no atom
    double performa; // performa atom
} Atom;

typedef struct { // menyimpan data yang didapatkan dari kombinasi(n, 3) atom
    Atom arr[3]; // 3 susunan/kombinasi atom
    double totalNo; // total nomor ketiga atom
    double totalPerforma; // total performa ketiga atom
    double rasio; // total performa atom : total nomor atom
} Kombinasi;

// PENGGUNAAN PROCEDURE & FUNCTION
int hitungKombinasi(int n, int k); // Mengembalikan nilai kombinasi dari rumus C(n, k)
int hitungFaktorialParsial(int n, int batas); // Mengembalikan nilai n! / batas!
// membangkitkan kombinasi(n, 3) dari src yang tersusun atas 3 susunan
// hasil kombinasi dimasukkan ke perm
void bangkitkanKombinasi(Atom *src, Kombinasi *perm, Atom temp[3], int kiriN, int n, int kiriK, int k, int *posKombinasi);
void hitungDataKombinasi(Kombinasi *src); // menghitung rasio total performa dan total nomor dari data src
int komparasiDouble(double p, double q); // mengkomparasi besar, kecil, sama dengan, antara p dan q
int sequentialSearch(int i, int n, Kombinasi arr[], double target); // mengembalikan posisi data yang sebesar min. target dari [i, n - 1] arr
int binarySearch(int kiri, int kanan, Kombinasi arr[], double target); // mencari posisi data yang sebesar target dari [kiri, kanan] arr
void insertionSort(int kiri, int kanan, Kombinasi *arr); // mengurutkan data dari [kiri, kanan] arr
void printElement(Kombinasi src); // menampilkan data tiga nama atom, total nomor, total performa, dan rasio dari data src