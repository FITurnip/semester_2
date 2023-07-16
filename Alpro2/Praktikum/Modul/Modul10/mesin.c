#include "header.h"
#include <string.h>

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

void temptasiData(char str[], student *temp) {
    inc(str);
    strcpy(temp->nim, getcw());
    inc(str);
    strcpy(temp->nama, getcw());
    inc(str);
    strcpy(temp->nilai, getcw());
}

void insertionSort(int n, student *arr) {
    int i, j;
    student temp;
    for(i = 1; i < n; i++) {
        temp = arr[i];
        j = i - 1;
        while(j >= 0 && strcmp(temp.nim, arr[j].nim) < 0) {
            // strcpy(nama[j + 1], nama[j]);
            arr[j + 1] = arr[j];
            j--;
        }
        // strcpy(nama[j + 1], temp);
        arr[j + 1] = temp;
    }
}

int binarySearch(int n, student arr[], char target[]) {
    int kiri = 0, kanan = n - 1, tengah;
    int ditemukan = 0;
    int komp;
    int posisi = -1;

    while(ditemukan == 0 && kiri <= kanan) {
        tengah = (kiri + kanan) / 2;
        
        komp = strcmp(arr[tengah].nim, target);
        if(komp != 0) {
            if(komp > 0) {
                kanan = tengah - 1;
            } else {
                kiri = tengah + 1;
            }
        } else {
            ditemukan = 1;
        }
    }

    if(ditemukan != 0) {
        posisi = tengah;
    }

    return posisi;
}

void errorHandling(char str[], int jenis_error, int baris, int kolom) {
    printf("    %d:%d: error : ", baris, kolom);
    
    switch(jenis_error) {
        case 0:
        printf("query salah\n");
        break;
        case 1:
        printf("tabel tidak ditemukan\n");
        break;
        case 2:
        printf("nim sudah pernah dipakai\n");
        break;
        case 3:
        printf("nim tidak ditemukan\n");
        break;
        case 4:
        printf("nim ditemukan, tetapi nama tidak sesuai\n");
        break;
    }

    printf("      | %s\n", str);
    printf("      |");

    f(i, 0, kolom) {
        printf(" ");
    }
    printf("^\n\n");
}

void modify_data(int urutanPerintah, char str[], int *banyakData, student *data) {
    student temp;
    int posDicari;
    // memulai mesin kata
    start(str);

    if (strcmp(getcw(), "INSERT") == 0) {
        inc(str);
        if (strcmp(getcw(), "mahasiswa") == 0) {
            temptasiData(str, &temp);

            posDicari = binarySearch((*banyakData), data, temp.nim);

            if(posDicari == -1) {
                strcpy(data[(*banyakData)].nim, temp.nim);
                strcpy(data[(*banyakData)].nama, temp.nama);
                strcpy(data[(*banyakData)].nilai, temp.nilai);
                (*banyakData)++;
                insertionSort((*banyakData), data);
            } else {
                errorHandling(str, 2, urutanPerintah, 17);
            }
        } else {
            errorHandling(str, 1, urutanPerintah, 7);
        }
    } else if (strcmp(getcw(), "UPDATE") == 0) {
        inc(str);
        if (strcmp(getcw(), "mahasiswa") == 0) {
            temptasiData(str, &temp);

            posDicari = binarySearch((*banyakData), data, temp.nim);

            if(posDicari != -1) {
                if(strcmp(data[posDicari].nama, temp.nama) == 0) {
                    strcpy(data[posDicari].nilai, temp.nilai);
                } else {
                    errorHandling(str, 4, urutanPerintah, 17 + strlen(temp.nama));
                }
            } else {
               errorHandling(str, 3, urutanPerintah, 17);
            }
        } else {
            errorHandling(str, 1, urutanPerintah, 7);
        }
    } else if (strcmp(getcw(), "DELETE") == 0) {
        inc(str);
        if (strcmp(getcw(), "mahasiswa") == 0) {
            inc(str);
            strcpy(temp.nim, getcw());

            posDicari = binarySearch((*banyakData), data, temp.nim);

            if(posDicari != -1) {
                int i = posDicari;
                while(i + 1 < (*banyakData)) {
                    data[i] = data[i + 1];
                    i++;
                }

                (*banyakData)--;
            } else {
               errorHandling(str, 3, urutanPerintah, 17);
            }
        } else {
            errorHandling(str, 1, urutanPerintah, 7);
        }
    } else {
        errorHandling(str, 0, urutanPerintah, 0);
    }
}
