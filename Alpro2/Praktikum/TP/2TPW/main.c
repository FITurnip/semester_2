/*
    Saya Franklin Impianro Turnip(2203211) mengerjakan evaluasi TP2 dalam mata kuliah Alpro II untuk keberkahanNya
    maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/
// PENGGUNAAN LIBRARY
#include "header.h" // Lihat pada header.h
// MAIN
int main() {
    // Deklarasi
    int baris, kolom; // Banyak baris dan kolom array wisudawan
    int stopLooping = 0; // Nilai boolean sebagai penanda berhenti atau tidaknya looping
    char tempUkuranToga[4], tempNamaDitukar[102]; // Menyimpan data sementara ukuran toga dan nama yang hendak ditukar
    StandarToga standarToga[7] = {{"XS", 32}, {"S", 36}, {"M", 37}, {"L", 38}, {"XL", 40}, {"XXL", 42}, {"XXXL", 45}}; // Data standar toga
    Ditukar ditukar[2]; // Menyimpan sementara data 2 wisudawan yang hendak ditukar

    // Meminta Input dari User, Mendeklarasi, Mengolahan Data, dan Menampilkan Data
    scanf("%d %d", &baris, &kolom); // Meminta input banyak baris dan kolom array wisudawan

    Wisudawan wisudawan[baris][kolom]; // Mendeklarasi array wisudawan sebesar baris * kolom

    for(int i = 0; i < baris; i++) {
        for(int j = 0; j < kolom; j++) {
            scanf(" %s %s", wisudawan[i][j].nama, tempUkuranToga); // Meminta input nama wisudawan bairs ke-i kolom ke-j dan ukuran toganya
            wisudawan[i][j].ukuranToga = standarisasiUkuranToga(standarToga, tempUkuranToga); // Mengisi ukuran standar berdasarkan kode
        }
    }

    // Menampilkan data yang belum diolah
    printf("Posisi awal :\n");
    tampilkanWisudawan(baris, kolom, wisudawan);

    // Mengolah pertukaran posisi wisudawan
    while(stopLooping == 0) { // Looping jika stopLooping bernilai false
        scanf(" %s", tempNamaDitukar); // Meminta input nama pertama yang hendak ditukar

        // Jika belum mendapat string selesai, olah data. Jika tidak, hentikan
        if(strcmp(tempNamaDitukar, "Selesai") != 0) {
            strcpy(ditukar[0].nama, tempNamaDitukar); // Mengisi nama yang didapat pada array ditukar
            scanf("%s", ditukar[1].nama); // Meminta input nama kedua yang hendak ditukar

            cariPosisiNama(baris, kolom, wisudawan, ditukar); // Isi posisi dari kedua wisudawan
            urutkanDitukar(ditukar); // Wisudawan yang berada di depan diposisikan di indeks 0 pada array ditukar
            if(ditukar[0].posisi[0] != ditukar[1].posisi[0]) { // Ditukar apabila tidak berada pada baris yang sama
                // Ditukar bila ukuran wisudawan yang berada di depan lebih besar daripada yang berada di belakang
                if(wisudawan[ditukar[0].posisi[0]][ditukar[0].posisi[1]].ukuranToga > wisudawan[ditukar[1].posisi[0]][ditukar[1].posisi[1]].ukuranToga) {
                    tukarPosisi(&wisudawan[ditukar[0].posisi[0]][ditukar[0].posisi[1]], &wisudawan[ditukar[1].posisi[0]][ditukar[1].posisi[1]]);
                }
            }
        } else {
            stopLooping = 1; // Hentikan looping dengan mengisi nilai true
        }
    }

    // Menampilkan data yang sudah diubah
    printf("\nPosisi akhir :\n");
    tampilkanWisudawan(baris, kolom, wisudawan);
    
    return 0;
}