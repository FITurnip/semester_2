/*
    Saya Franklin Impianro Turnip(2203211) mengerjakan evaluasi Kuis 1 dalam mata kuliah Alpro II untuk keberkahanNya
    maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/
// PENGGUNAAN LIBRARY
#include "header.h"

// MAIN
int main() {
    // Deklarasi Variable
    // Menyimpan nilai tengah, konstanta tambah-kurang, dan banyak kiri-kanan
    int nilai, konstanta, banyak;

    // Meminta Masukan
    scanf("%d %d %d", &nilai, &konstanta, &banyak); // Nilai tengah, konstanta tambah-kurang, dan banyak kiri-kanan

    printElement(nilai, konstanta, banyak, banyak); printf("\n"); // Tampilkan deret

    return 0;
}