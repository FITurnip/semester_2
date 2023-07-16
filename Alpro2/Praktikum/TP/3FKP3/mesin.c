/*
    Saya Franklin Impianro Turnip(2203211) mengerjakan evaluasi TP3 dalam mata kuliah Alpro II untuk keberkahanNya
    maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/
// PENGGUNAAN LIBRARY
#include "header.h"

// PROCEDURE DAN FUNGSI
// Untuk mencari nilai f(x) atau levelNgeunah pada selisih bernilai x
int pelevelanNgeunah(int x, int levelNgeunah[]) {
    if(levelNgeunah[x] > 0) { // Jika levelNgeunah pernah diisi, kembalikan langsung nilai tersebut
        return levelNgeunah[x];
    } else { // Jika belum, isi nilai tersebut dan kembalikan nilai tersebut
        levelNgeunah[x] = (pelevelanNgeunah(x - 1, levelNgeunah) * 2) - 3; // Isi secara rekursif
        return levelNgeunah[x];
    }
}

// Kurangi beratBumbu A dan B
void kurangiBeratBumbu(int beratBumbu[2]) {
    // Kurangi menjadi 1/3 berat sebelumnya
    if(beratBumbu[1] > beratBumbu[0]) { // Kurangi B jika B lebih berat dari A
        beratBumbu[1] /= 3;
    } else { // Atau sebaliknya
        beratBumbu[0] /= 3;
    }
}

// Tampilkan Data Berat Bumbu dan Level Ngeunah Saat Ini
void tampilkan(int beratBumbu[2], int levelNgeunah[]) {
    // Deklarasi Variabel
    int i = 0, j; // Iterator
    int dispasikan; // Nilai Boolean untuk menghentikan atau melanjutkan spasi

    // Tampilkan Data
    while(i < 2) { // Iterator dua kali untuk memunculkan data bumbu A dan B
        printf("%d", beratBumbu[i]); // Tampilkan berat bumbu

        // Tampilkan spasi
        j = 100; // Iterais dari 100 sebagai patokan
        dispasikan = 1; // Nilai awal true agar dianggap spasi mungkin terjadi

        // Tampilkan spasi untuk memenuhi 3 karakter yang sudah termasuk digit angka dan spasi
        while(dispasikan == 1 && j > 1) { // Berhenti jika tidak butuhkan spasi lagi atau j sama dengan 1
            if(beratBumbu[i] < j) {
                printf(" ");
            } else {
                dispasikan = 0;
            }

            j /= 10;
        }

        // Tampilkan pembatas
        if(i == 0) { // Untuk antara bumbu A dan B
            printf("| ");
        } else { // Untuk antara bumbu B dan levelNgeunah
            printf("<< ");
        }

        // Iterasi
        i++;
    }

    // Tampilkan nilai levelNgeunah
    printf("%d\n", pelevelanNgeunah(abs(beratBumbu[0] - beratBumbu[1]), levelNgeunah));
}

void eksperimen(int beratBumbu[2], int levelNgeunah[]) {
    // Tampilkan terlebih dahulu data berat bumbu dan level ngeunah
    tampilkan(beratBumbu, levelNgeunah);

    // Eksekusi lebih lanjut dilakukan apabila belum ditemukan berat bumbu bernilai 1 gram
    if(!(beratBumbu[0] == 1 || beratBumbu[1] == 1)) {
        kurangiBeratBumbu(beratBumbu); // Kurangi terlebih dahulu berat bumbu yang berat bumbunya lebih besar
        eksperimen(beratBumbu, levelNgeunah); // Lakukan eksperiman hingga bumbu A atau B bernilai 1 gram
    }
}

void memsetLevelNgeunah(int levelNgeunah[]) {
    levelNgeunah[0] = 6; // Untuk indeks 0, bernilai 6 sesuai kesepakatan pada soal

    for(int i = 1; i <= 100; i++) { // Selain indeks 0, berniali 0 agar dianggap belum diisi apa-apa
        levelNgeunah[i] = 0;
    }
}