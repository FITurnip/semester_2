/*
    Saya Franklin Impianro Turnip(2203211) mengerjakan evaluasi Kuis 2 dalam mata kuliah Alpro II untuk keberkahanNya
    maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/
// PENGGUNAAN LIBRARY
#include "header.h"

// MAIN
int main() {
    // DEKLARASI VARIABLE
    int n; // banyaknya data
    char asasPengurutan[11]; // asas pengurutan
    long long dicari; // nilai yang dicari pada deretan data
    int posDicari; // flag posisi nilai yang telah dicari

    // MEMINTA INPUT DARI USER
    scanf("%d", &n); // banyaknya data

    Pegawai pegawai[n]; // deklarasikan n data pegawai
    for(int i = 0; i < n; i++) { // masukkan n data pegawai
        scanf(" %s %s %s %lld %lld", pegawai[i].no, pegawai[i].nama, pegawai[i].jabatan, &pegawai[i].gaji_pokok, &pegawai[i].tunjangan);
    }

    scanf(" %s", asasPengurutan); // asas pengurutan
    scanf(" %lld", &dicari); // nilai yang dicari

    // PENGOLAHAN DATA
    switch(asasPengurutan[0]) { // sebelum melakukan pengurutan, periksa apakah asas pengurutannya berupa pendapatan
        case 'p':
        // jika iya, isi nilai pendapatannya terlebih dahulu agar program tidak menghitung pendapatan pada data yang sama pada langkah-langkah selanjutnya
        for(int i = 0; i < n; i++) {
            pegawai[i].pendapatan = pegawai[i].gaji_pokok + pegawai[i].tunjangan;
        }
        // jangan berikan break, karena apapun asasnya, akan dilaksanakan pengurutan menggunakan quicksort
        default:
        quicksort(pegawai, 0, n - 1, asasPengurutan[0]); // urutkan data ke-0 hingga ke-(n - 1) berdasarkan asas yang telah diinput user
        break;
    }

    // cari posisi nilai target dari data ke-0 hingga ke-(n - 1) berdasarkan asas pengurutannya
    posDicari = binarySearch(0, n - 1, pegawai, dicari, asasPengurutan[0]);

    if(posDicari == -1) { // jika flagnya -1, berarti tidak ditemukan
        printf("tidak ditemukan\n");
    } else { // jika flagnya >= 0, berarti ditemukan pada index posDicari
        printElement(pegawai[posDicari]); // tampilkan datanya
    }

    printf("\ntertinggi:\n"); // tampilkan data dengan nilai tertinggi berdasarkan asas pengurutannya
    printElement(pegawai[n - 1]); // tampilkan datanya

    printf("\nterendah:\n"); // tampilkan data dengan nilai terendah berdasarkan asas pengurutannya
    printElement(pegawai[0]); // tampilkan datanya

    return 0;
}