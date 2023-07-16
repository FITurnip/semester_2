#include "header.h"

/* Deklarasi variabel global */
int indeks; // indeks karakter
char cc;    // karakter saat ini (current character)

// Prosedur untuk memulai mesin karakter
void START(char pita[]) {
    // inisialisasi index dan karakter yang dibaca
    indeks = 0;
    cc = pita[indeks];
}

// Fungsi untuk memeriksa akhir dari proses (End of Process)
int EOP() {
    // memeriksa apakah karakter saat ini merupakan simbol akhir dari pita
    if (cc == ';') {
        return 1;
    } else {
        return 0;
    }
}

// Prosedur untuk memajukan karakter pada pita
void INC(char pita[]) {
    // menambah nilai indeks dan mengatur karakter yang dibaca
    indeks++;
    cc = pita[indeks];
}

// Prosedur untuk memajukan karakter hingga melewati spasi
void ADV(char pita[]) {
    // menambah nilai indeks dan mengatur karakter yang dibaca
    indeks++;
    cc = pita[indeks];

    // Terus mengulang proses jika karakter saat ini masih berupa spasi
    while ((cc == ' ') && (EOP() == 0)) {
        indeks++;
        cc = pita[indeks];
    }
}

// Fungsi untuk mendapatkan karakter pita saat ini
char GETCC() {
    return cc;
}

// Fungsi untuk mendapatkan indeks pita saat ini
int GETINDEX() {
    return indeks;
}

// Fungsi untuk mengakapitalisasi karakter yang dimasukan
char akapitalisasi(char isi) {
    // Diasumsikan bahwa karakter 'a' secara ASCII merupakan huruf kapital
    // Periksa apakah isi merupakan huruf kapital
    if(isi < 'a') {
        // Jika benar, akiptalisasi
        isi += 32;
    }

    // Kembalikan karakter yang telah diolah
    return isi;
}

// Fungsi untuk memeriksa jenis karakter saat ini
int isVocal() {
    // Deklarasi flag kevokalan
    int flag = 0;

    // periksa apakah merupakan karakter saat ini yang telah diakiptalisasi merupakan huruf vocal
    // jika vocal, flag berubah menjadi 1
    switch(akapitalisasi(cc)) {
        case 'a':
        flag = 1;
        break;
        case 'i':
        flag = 1;
        break;
        case 'u':
        flag = 1;
        break;
        case 'e':
        flag = 1;
        break;
        case 'o':
        flag = 1;
        break;
    }

    return flag; // kembalikan nilai flag kevokalan
}