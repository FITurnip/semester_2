/*
    Saya Franklin Impianro Turnip(2203211) mengerjakan evaluasi Kuis 1 dalam mata kuliah Alpro II untuk keberkahanNya
    maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/
// PENGGUNAAN LIBRARY
#include "header.h"

// PROCEDURE
void printElement(int nilai, int konstanta, int pos, int banyak) {
    // Menampilkan nilai pada indeks ke-pos dari 0 hingga banyak * 2
    if(pos < banyak && pos >= 0) {
        // Pada kondisi posisi tengah ke belakang hingga 0, nilai berkurang sebanyak konstanta
        printElement(nilai - konstanta, konstanta, pos - 1, banyak);
        printf("%d ", nilai);
    } else if(pos == banyak) {
        // Tampilkan nilai pada index sebelumnya terlebih dahulu
        printElement(nilai - konstanta, konstanta, pos - 1, banyak);
        // Tampilkan nilai tengah
        printf("%d", nilai);
        // Selanjutnya, tampilkan nilai pada index selanjutnya
        printElement(nilai + konstanta, konstanta, pos + 1, banyak);
    } else if(pos > banyak && pos <= banyak * 2) {
        // Pada kondisi posisi tengah ke depan hingga banyak * 2, nilai bertambah sebanyak konstanta
        printf(" %d", nilai);
        printElement(nilai + konstanta, konstanta, pos + 1, banyak);
    }
}