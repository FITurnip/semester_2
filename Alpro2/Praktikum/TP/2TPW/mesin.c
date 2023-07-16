/*
    Saya Franklin Impianro Turnip(2203211) mengerjakan evaluasi TP2 dalam mata kuliah Alpro II untuk keberkahanNya
    maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/
// PENGGUNAAN LIBRARY
#include "header.h" // Lihat pada header.h

// FUNCTION DAN PROCEDURE
// Procedure tukarPosisi dan urutkanDitukar akan menukar 2 data
// dengan cara menempatkan dataA pada tempat sementara(temp)
// lalu menempatkan dataB pada dataA dan menempatkan dataA sebelumnya(temp) pada dataB
void tukarPosisi(Wisudawan *wisudawanA, Wisudawan *wisudawanB) {
    Wisudawan temp = *wisudawanA;
    *wisudawanA = *wisudawanB;
    *wisudawanB = temp;
}

void urutkanDitukar(Ditukar ditukar[2]) {
    if(ditukar[0].posisi[0] > ditukar[1].posisi[0]) { // Hanya menukarkan data apabila wisudawan 0 berada di depan wisudawan 1
        Ditukar temp = ditukar[0];
        ditukar[0] = ditukar[1];
        ditukar[1] = temp;
    }
}

void cariPosisiNama(int baris, int kolom, Wisudawan wisudawan[baris][kolom], Ditukar ditukar[2]) {
    // Deklarasi iterator
    int indeksNama = 0; // Indeks nama wisudawan berdasarkan array ditukar
    int i, j; // Indeks baris(i) dan kolom(j) berdasarkan array wisudawan

    // Pencarian
    while(indeksNama < 2) {
        ditukar[indeksNama].posisi[0] = -1; // -1 digunakan sebagai acuan bahwa nama wisudawan belum ditemukan
        i = 0;
        while(i < baris && ditukar[indeksNama].posisi[0] == -1) { // Looping selagi baris belum berakhir dan belum ditemukan nama wisudawan
            j = 0;
            while(j < kolom && ditukar[indeksNama].posisi[0] == -1) { // Looping selagi kolom belum berakhir dan belum ditemukan nama wisudawan
                if(strcmp(wisudawan[i][j].nama, ditukar[indeksNama].nama) == 0) { // Jika ditemukan isi posisi wisudawan pada array ditukar
                    ditukar[indeksNama].posisi[0] = i;
                    ditukar[indeksNama].posisi[1] = j;
                }

                j++;
            }

            i++;
        }
        
        indeksNama++;
    }

    // Jika ada yang tidak ditemukan, maka anggap saja semua tidak ada yang ditemukan agar tidak terjadi error pada proses menukar posisi
    // dan dianggap berada pada posisi yang sama, sehingga tidak akan ditukar
    if(ditukar[0].posisi[0] == -1 || ditukar[1].posisi[0] == -1) {
        ditukar[0].posisi[0] = -1;
        ditukar[1].posisi[0] = -1;
    }
}

int standarisasiUkuranToga(StandarToga standarToga[7], char kodeDiberikan[]) {
    // Deklarasi
    int ukuranDidapat = 0; // 0 digunakan sebagai acuan bahwa ukuran belum didapat
    int i = 0;

    // Pencarian
    while(i < 7) {
        if(strcmp(standarToga[i].kode, kodeDiberikan) == 0) { // Isi ukuran standar jika ditemukan kode yang tepat
            ukuranDidapat = standarToga[i].ukuran;
        }

        i++;
    }

    return ukuranDidapat; // Kembalikan nilai ukuran standar
}

// Menari Panjang String Terpanjang pada kolom ke-j
int CariPanjangStringTerpanjang(int baris, int kolom, Wisudawan wisudawan[baris][kolom], int j) {
    // Deklrasi
    int maks = 0, temp; // Nilai panjang string terbesar dan string yang dicek

    // Cari Panjang String Terpanjang
    for(int i = 0; i < baris; i++) {
        temp = strlen(wisudawan[i][j].nama); // Hitung ukuran panjang string baris ke-i kolom ke-j
        if(maks < temp) maks = temp; // Perbarui nilai maks jika ditemukan nilai panjang string yang lebih besar
    }
    return maks;
}

void tampilkanWisudawan(int baris, int kolom, Wisudawan wisudawan[baris][kolom]) {
    // Deklrasi
    int panjangStringTerpanjang[kolom]; // Menampung panjang string terpanjang dalam setiap kolom
    int spasi; // Menampung spasi sementara

    // Cari Panjang String Terpanjang pada kolom ke-i
    for(int i = 0; i < kolom; i++) panjangStringTerpanjang[i] = CariPanjangStringTerpanjang(baris, kolom, wisudawan, i);

    // Tampilkan Matriks Nama Wisudawan Berdasarkan Posisi
    for(int i = 0; i < baris; i++) {
        for(int j = 0; j < kolom; j++) {
            printf("%s", wisudawan[i][j].nama); // Menampilkan nama wisudawan baris ke-i kolom ke-j

            // Tampilkan spasi agar tiap string dalam satu kolom dimulai dari posisi kolom yang sama
            if(j != kolom - 1) {
                spasi = 1 + panjangStringTerpanjang[j] - strlen(wisudawan[i][j].nama);
                for(int k = 0; k < spasi; k++) printf(" ");
            }
        }
        printf("\n"); // Tampilkan baris baru sebagai pemisah baris
    }
}