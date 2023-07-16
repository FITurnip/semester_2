/*
    Saya Franklin Impianro Turnip(2203211) mengerjakan evaluasi TP dalam mata kuliah Alpro II untuk keberkahanNya
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
    if (str[idx] == ';') {
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

// Funsi untuk apakah kata terenkripsi
int isEncrypted(char *word, char codename) {
    // deklarasi
    int itr = 0;                                // iterator
    int len = strlen(word);                     // panjang kata
    int lastDigitOfCodename = codename % 10;    // digit terakhir nilai ascii dari codename
    int wordContainsCn = 0;                     // flag, 0 = kata tidak mengandung codename, 1 = sebaliknya

    // kata terenkripsi merupakan kata yang mengandung cn
    // dan panjang kata lebih panjang dari pada digit terakhir nilai ascii dari codename

    // dapat dipastikan bahwa jika panjang kata <= digit terakhir nilai ascii dari codename, kata tidak terenkripsi
    if(len > lastDigitOfCodename) {

        // cari huruf codename pada word
        while(itr < len && wordContainsCn == 0) {
            if(word[itr] == codename) {
                wordContainsCn = 1;
            } else {
                itr++;
            }
        }

        // jika ditemukan, maka kata terenkripsi
        if(wordContainsCn == 1) {
            return 1;
        }

        // jika tidak, sebaliknya
    }

    return 0;
}


// Procedure untuk mengetahui apakah kata terenkripsi atau kata biasa
void refreshTypeOfWord(Word *src, int *encryptedWordCount, int *commonWordCount) {
    if((*src).typeOfWord == 0) {
        // jika tidak terenkripsi, dipastikan kata biasa
        (*src).typeOfWord = 3;

        (*commonWordCount)++;
    } else {
        // jika tidak, sebaliknya
        (*encryptedWordCount)++;
    }
}

// Fungsi untuk mengkomparasi apakah a lebih dahulu daripada b
int comp(Word a, Word b) {
    // komparasi jenis katanya
    if(a.typeOfWord < b.typeOfWord) {
        return 1;
    } else if(a.typeOfWord == b.typeOfWord) {

        // jika jenisnya sama, komparasi katanya
        if(strcmp(a.string, b.string) < 0) {
            return 1;
        }
    }

    return 0;
}

// Prosedur untuk mengurutkan kata dari indeks kiri sampai kanan
void qsTengah(Word arr[], int left, int right) {
    // deklarasi
    int i, j;           // iterator
    Word temp, pivot;   // penyimpanan sementara dan acuan

    // mulai iterasi
    i = left, j = right;
    pivot = arr[(right + left) / 2]; // menyimpan data yang ada di tengah arr
    do {
        while (comp(arr[i], pivot) == 1 && (i <= j)) { // data sebelah kiri lebih kecil daripada pivot
            i++;
        }

        while (comp(pivot, arr[j]) == 1 && (i <= j)) { // data sebelah kanan lebih besar daripada pivot
            j--;
        }
        
        // jika masih iterator kiri dan kanan belum bertemu,
        // tukar, iterasi, dan lanjutkan looping
        if (i < j) {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    } while (i < j);
    
    // jika selebah kanan pivot sudah diurutkan, urutkan sebelah kiri pivot
    if (left < j && j < right) {
        qsTengah(arr, left, j);
    }

    // jika selebah kiri pivot sudah diurutkan, urutkan sebelah kanan pivot
    if (i < right && i > left) {
        qsTengah(arr, i, right);
    }
}

// Prosedur untuk menampilkan daftar kata
void printElement(Word word[], int idxStart, int endOfArray) {
    if(idxStart == endOfArray) {    // jika tidak ada kata, tampilkan kosong
        printf("Kosong.\n");
    } else {                        // jika ada, tampilkan dari idxStart sampai endOfArray - 1
        for(int itr = idxStart; itr < endOfArray; itr++) {
            printf("- %s\n", word[itr].string);
        }
    }
}