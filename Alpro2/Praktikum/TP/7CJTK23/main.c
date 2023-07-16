/*
    Saya Franklin Impianro Turnip(2203211) mengerjakan evaluasi TP5 dalam mata kuliah Alpro II untuk keberkahanNya
    maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/
// PENGGUNAAN LIBRARY
#include "header.h"
int main() {
    // DEKLARASI
    int n; // banyaknya data atom
    int banyakKombinasi; // menyimpan P(n, k)
    int posKombinasi = 0; // menyimpan index awal kombinasi sesuai keperluan ke depannya
    Atom temp[3]; // menyimpan data sementara 3 atom USS Enterprise untuk keperluan kombinasi
    int urutan = 1; // menyimpan data urutan kombinasi yang muncul pada layar

    // MEMINTA INPUT DARI USER
    scanf("%d", &n); // banyaknya data atom

    Atom atomUE[n]; // deklarasi n data atom USS Enterprise
    for(int i = 0; i < n; i++) { // Iterasi terhadap n data atom USS Enterprise
        scanf(" %s %lf %lf", atomUE[i].nama, &atomUE[i].no, &atomUE[i].performa); // meminta masukkan nama, nomor atom, dan performa dari data atom USS Enterprise ke-i
    }

    banyakKombinasi = hitungKombinasi(n, 3); // menghitung P(n, k)
    Kombinasi kombinasiAtomUE[banyakKombinasi]; // Deklarasi data kombinasi atom USS Enterprise sebanyak P(n, k)

    bangkitkanKombinasi(atomUE, kombinasiAtomUE, temp, 0, n, 0, 3, &posKombinasi); // bangkitan kombinasi dari atom USS Enterprise sebanyak P(n, 3) ke dalam kombinasiAtomUE dari data atom ke-0 sampai ke-(n - 1)

    for(int i = 0; i < banyakKombinasi; i++) { // Iterasi terhadap semua data kombinasi
        hitungDataKombinasi(&kombinasiAtomUE[i]); // Hitung rasio kombinasi ke-i
        insertionSort(0, i, kombinasiAtomUE); // urutkan data kombinasi dari 0 hingga i agar lebih efisien
    }

    posKombinasi = sequentialSearch(0, banyakKombinasi, kombinasiAtomUE, 1.5); // mencari posisi awal data rasio yang memiliki nilai lebih besar atau sama dengan 1.5
    int posisiRasioTepat3 = binarySearch(posKombinasi, banyakKombinasi - 1, kombinasiAtomUE, 3.0); // mencari posisi data yang memiliki data rosio = 3 dari data kombinasi ke-posKombinasi sampai ujung data

    // TAMPILKAN OUTPUT
    printf("Hasil Seleksi:\n");
    for(int i = posKombinasi; i < banyakKombinasi; i++) { // Iterasi dari data yang setidaknya rasionya 1.5 sampai ujung data kombinasi
        printf("No: %d\n", urutan); // tampilkan urutan data berdasarkan kemunculan
        printElement(kombinasiAtomUE[i]); // tampilkan isi data kombinasi ke-i
        urutan++; // iterasi karena data telah muncul
    }

    // tampilkan statement ada atau tidaknya data yang memiliki rasio = 3
    // identifikasinya dari posisinya yang berada pada batasan data kombinasi
    if(posisiRasioTepat3 == -1) {
        printf("Tidak ");
    }
    printf("ada kombinasi ");
    if(posisiRasioTepat3 == -1) {
        printf("atom");
    } else {
        printf("barang");
    }
    printf(" dengan rasio tepat 3 kali lipat\n");

    printf("James T. Kirk ");
    if(posisiRasioTepat3 == -1) {
        printf("gagal");
    } else {
        printf("berhasil");
    }
    printf(" menghancurkan starship Narada\n");
    return 0;
}