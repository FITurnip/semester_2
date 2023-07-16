/*
    Saya Franklin Impianro Turnip(2203211) mengerjakan evaluasi TP5 dalam mata kuliah Alpro II untuk keberkahanNya
    maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/
// PENGGUNAAN LIBRARY
#include <stdio.h> // Keperluan IO
#include <string.h> // Keperluan Pengolahan String

// PENGGUNAAN STRUCT
typedef struct { // Menampung data satu murid
    char nama[101], spell[101]; // nama dan spell murid
    int power; // power murid
    char asrama; // asrama murid
} Murid;

// DAFTAR PROCEDURE DAN FUNGSI
int pilihMaks(int a, int b); // mengembalikan nilai yang lebih besar antara a dan b
int cariPanjangMaksimumString(int n, Murid arr[]); // mengembalikan nilai maksimum panjang string nama pada array of struct Murid
void scanElement(int n, Murid *arr, char asrama); // melakukan scanning terhadap n element arr yang dengan kesamaan asrama
void printElement(int n, Murid *arr); // menampilkan seluruh isi n element data arr
int komp(Murid a, Murid b, char asasKomparasi); // mengembalikan nilai flag sebagai pertanda perlu dijalankan atau tidaknya pertukaran pada sorting
void qsTengah(Murid arr[], int kiri, int kanan, char asasPengurutan); // mengurutkan arr dari kiri sampai kanan dengan asas pengurutan tertentu
void merge(Murid arr1[], int n1, Murid arr2[], int n2, Murid arr3[], char asasPengurutan); // menggabungkan n1 element arr1 dan n2 element arr2 ke dalam arr3 secara terurut berdasarkan asas tertentu
int hitungJumlahBerangkat(int n, Murid *arr, int minimalJumlahPower); // mengembalikan nilai jumlah murid yang akan berangkat
int hitungTotalPower(int awal, int akhir, Murid *arr); // mengembalikan nilai total power element arr ke-awal sampai element ke-(akhir - 1)