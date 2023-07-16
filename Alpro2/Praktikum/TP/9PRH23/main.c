#include <stdio.h>
#include "header.h"

int main() {
    // deklarasi variabel pita
    char pita[102]; // pita sepanjangan 100 karakter + 1 tanda koma
    int valid = 0, vocal = 0, adaCodename = 0; // flag validasi adanya codename, jenis karakter pertama pada pita, dan ada tidaknya codename
    char codename; // menampung karakter pertama pita

    // meminta masukan pita
    scanf("%101[^\n]s", pita);

    // memulai mesin dan membaca pita
    START(pita);
    
    // memeriksa jenis huruf perta
    vocal = isVocal();

    // memasukkan karakter yang kemungkinan merupakan codename yang telah diakapitalisasi
    codename = akapitalisasi(GETCC());

    // Memeriksa hingga akhir pita atau ditemukan codename dalam pita
    while (EOP() == 0 && adaCodename == 0) {
        // periksa berdasarkan jumlah valid sejauh ini
        switch(valid) {
            case 0:
            // jika belum ada, periksa apakah karakter saat ini sama jenisnya dengan karakter pertama pita
            if(isVocal() == vocal) {
                // jika ya, valid bertambah
                valid++;
            } // jika tidak, valid tidak bertambah
            break;
            case 1:
            // jika 1 karakter sebelumnya berjenis sama dengan karakter pertama, periksa apakah karakter saat ini sama dengan karakter pertama yang telah diakapitalisasi
            if(akapitalisasi(GETCC()) == codename) {
                // jika iya, valid bertambah
                valid++;
            } else {
                //jika tidak, valid kembali ke 0
                valid = 0;
            }
            break;
            case 2:
            // jika 2 karakter sebelumnya valid, perilaku selanjutnya seperti case 1, tetapi akan mengulang valid ke 0 jika tidak sesuai
            if(isVocal() == vocal) {
                adaCodename = 1;
            } else {
                valid = 0;
            }
            break;
        }

        ADV(pita); // lakukan ADV agar karakter spasi diabaikan
    }

    // Tampilkan ke layar, kondisi keberadaan codename
    switch(adaCodename) {
        case 0:
        printf("Bukan pesan rahasia.\n");
        break;
        case 1:
        printf("Pesan rahasia yang dikirim oleh codename %c.\n", codename - 32);
        break;
    }

    return 0;
}