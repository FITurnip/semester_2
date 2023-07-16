/*
    Saya Franklin Impianro Turnip(2203211) mengerjakan evaluasi TP5 dalam mata kuliah Alpro II untuk keberkahanNya
    maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/
// PENGGUNAAN LIBRARY
#include "header.h"
int main () {
    // DEKLARASI VARIABLE
    int banyakDataSihir; // banyak data sihir yang diinput
    char metodeSorting; // flag metode sorting yang dipakai
    char jenisUrutan[10]; // flag jenis urutan asc atau dsc
    int batasWaktu; // batas waktu untuk dapat menguasai mantra

    // MEMINTA INPUT DARI USER
    scanf(" %d", &banyakDataSihir); // banyak data sihir yang akan diinput

    Sihir sihir[banyakDataSihir]; // deklarasi data sihir sebanyak banyakDataSihir
    for(int i = 0; i < banyakDataSihir; i++) { // Looping terhadap semua sihir
        scanf(" %s", sihir[i].namaMantra); // nama mantra sihir ke-i
        scanf(" %d", &sihir[i].mp); // magic power sihir ke-i
        scanf(" %d", &sihir[i].waktu); // waktu yang diperlukan untuk menguasai sihir ke-i
    }

    scanf(" %c", &metodeSorting); // metode sorting yang dipakai
    scanf(" %s", jenisUrutan); // jenis urutan yang diterapkan
    scanf(" %d", &batasWaktu); // batas waktu untuk dapat menguasai mantra

    // OLAH DATA
    switch(metodeSorting) { // Metode sorting berdasarkan flag
        case 'b': // b untuk bubble sort
        bSorting(banyakDataSihir, sihir, jenisUrutan[0]);
        break;
        case 'q': // q untuk quicksort
        qsTengah(sihir, 0, banyakDataSihir - 1, jenisUrutan[0]);
        break;
    }

    // cari maks sihir yang dapat dikuasai secara terurut dari indeks-0 dan tidak lebih dari batas waktu
    int maksSihirYgDptDikuasai = cariMaksSihirYgDptDikuasai(banyakDataSihir, sihir, batasWaktu);

    // TAMPILKAN DATA OUTPUT
    printElemen(banyakDataSihir, sihir); // tampilkan tabel sihir yang telah diurutkan

    // Tampilkan maksimum banyaknya sihir yang dapat dikuasai
    if(maksSihirYgDptDikuasai > 0) {
        printf("Anda bisa menguasai %d sihir dengan waktu yang diberikan\n", maksSihirYgDptDikuasai);
    } else {
        printf("Anda tidak bisa menguasai apa apa, karena waktunya tidak cukup!\n");
    }

    return 0;
}