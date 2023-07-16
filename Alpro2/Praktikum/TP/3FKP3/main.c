/*
    Saya Franklin Impianro Turnip(2203211) mengerjakan evaluasi TP3 dalam mata kuliah Alpro II untuk keberkahanNya
    maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/
// PENGGUNAAN LIBRARY
#include "header.h"

// MAIN
int main() {
    // Deklarasi Variabel
    // Menyimpan nilai berat bumbu awal dan nilai levelNgeunah pada selisih tertentu
    int beratBumbu[2], levelNgeunah[101];

    // Meminta masukan dari user
    for(int i = 0; i < 2; i++) {
        scanf("%d", &beratBumbu[i]); // Nilai bumbu A dari indeks i = 1, B dari indeks i = 2
    }

    // Isi nilai awal pada array levelNgeunah agar tidak terjadi error
    memsetLevelNgeunah(levelNgeunah);

    // Olah dan Tampilkan Jawaban
    eksperimen(beratBumbu, levelNgeunah);
    
    return 0;
}