/*
    Saya Franklin Impianro Turnip(2203211) mengerjakan evaluasi UAS dalam mata kuliah Alpro II untuk keberkahanNya
    maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/
// PENGGUNAAN LIBRARY
#include "header.h"

// Deklarasi variable
int idx;
int wlen;
char cw[50];

// Prosedur untuk memulai mesin kata
void start(char str[]) {
    // inisialisasi index dan panjang kata
    idx = 0;
    wlen = 0;

    // jika karakter dalam index adalah spasi, maka index terus maju
    while (str[idx] == ' ') {
        idx++;
    }
    // jika masukan berupa karakter selain spasi dan EOP, kata diatur ke variabel global
    while ((str[idx] != ' ') && (eop(str) == 0)) {
        cw[wlen] = str[idx];
        wlen++;
        idx++;
    }
    // mengatur agar kata saat ini index terakhirnya menjadi NULL
    cw[wlen] = '\0';
}

// Prosedur untuk mengosongkan kata yang dibaca dalam mesin kata
void reset() {
    // inisialisasi panjang kata dan kata saat ini agar NULL
    wlen = 0;
    cw[wlen] = '\0';
}

// Fungsi untuk memeriksa akhir dari proses
int eop(char str[]) {
    // Memeriksa apakah karakter saat ini merupakan simbol akhir pita
    if (str[idx] == '.') {
        return 1;
    } else {
        return 0;
    }
}

// Prosedur untuk memajukan kata
void inc(char str[]) {
    // inisialisasi ulang panjang kata
    wlen = 0;

    // jika karakter dalam pita adalah spasi, maka index terus maju
    while (str[idx] == ' ') {
        idx++;
    }

    // jika masukan berupa karakter selain spasi dan EOP, kata diatur ke variabel global
    while ((str[idx] != ' ') && (eop(str) == 0)) {
        cw[wlen] = str[idx];
        wlen++;
        idx++;
    }
    
    // mengatur agar kata saat ini index terakhirnya menjadi NULL
    cw[wlen] = '\0';
}

// Fungsi untuk mendapatkan panjang kata saat ini
int getlen() {
    return wlen;
}

// Fungsi untuk mendapatkan kata saat ini
char *getcw() {
    return cw;
}

// Fungsi untuk menentukan kevalidan kata
int isValidWord(char *word, char target, int minTargetCount) {
    // deklarasi variable
    int lenWord = strlen(word); // panjang string word
    int itr;                    // iterator
    int validCount;                  // jumlah kevalidan pada kata

    // karena kata yang dianggap valid adalah word yang mengandung target minimal sebanyak minTargetCount,
    // tentukan komparasi terlebih dahulu panjang word dan minTargetCount agar efisien
    if(lenWord < minTargetCount) {  // jika benar, maka kata dipastikan tidak valid
        return 0;
    } else {                        // jika tidak, maka cari target pada Word hingga berjumlah minTargetCount
        itr = 0;
        validCount = 0;

        while(itr < lenWord && validCount < minTargetCount) {
            if(word[itr] == target) {
                validCount++;
            }

            itr++;
        }

        // Jika iterasi selesai, periksa banyaknya persyaratan yang benar
        if(validCount == minTargetCount) {  // jika terpenuhi, maka kata dianggap valid
            return 1;
        } else {                            // jika tidak, maka kata tidak valid
            return 0;
        }
    }
}