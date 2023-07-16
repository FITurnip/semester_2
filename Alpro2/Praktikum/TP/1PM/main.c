/*
    Saya Franklin Impianro Turnip(2203211) mengerjakan evaluasi TP1 dalam mata kuliah Alpro II untuk keberkahanNya
    maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/
// PENGGUNAAN LIBRARY
#include "header.h"

// MAIN
int main() {
    // DEKLARASI VARIABEL
    Ordo ordoMatriks[2]; // Ordo dua matriks(N & M)
    int maks; // Ukuran maksimum (M) array yang menampung matriks
    int sama; // Nilai bolean sama atau tidaknya 2 buah matriks
    int sum = 0; // Nilai jumlah elemen baris 1 dan kolom 1
    char akhir[2][10] = {"refleksi", "transpose"}; // Pernyataan eksekusi terakhir terhadap matriks yang diolah
    /* 
        KESERAGAMAN
        Matriks bersifat berkaitan dengan array p dan indeks 0 pada ordo,
        sedangkan matriks yang diolah berkaitan dengan array q dan indeks 1 pada ordo
    */
    
    // MEMINTA INPUT DARI USER DAN MENDEKLARASI VARIABEL
    scanf("%d %d", &ordoMatriks[0].N, &ordoMatriks[0].M); // Nilai ordo untuk matriks p

    // Menentukan nilai maks besar array dengan memasukkan nilai terbesar antara baris dan kolom matriks p
    if(ordoMatriks[0].N > ordoMatriks[0].M) maks = ordoMatriks[0].N;
    else maks = ordoMatriks[0].M;

    // Matriks diinisasi dalam bentuk array yang berukurang maks*maks
    // karena perubahan matriks mengakibatkan diperlukannya keseragaman agar tercipta konsistensi
    int p[maks][maks], q[maks][maks];

    for(int i = 0; i < ordoMatriks[0].N; i++) {
        for(int j = 0; j < ordoMatriks[0].M; j++) {
            scanf("%d", &p[i][j]); // Nilai elemen matriks p pada baris ke-i dan kolom ke-j
        }
    }

    // MENGOLAH DATA
    // Menjumlahkan semua elemen baris pertama dan kolom pertama
    for(int i = 0; i < ordoMatriks[0].N; i++) sum += p[i][0]; // Baris pertama
    for(int i = 0; i < ordoMatriks[0].M; i++) sum += p[0][i]; // Kolom Pertama

    sum %= 4; // Sum dimudolo 4 karena matriks akan dirotasi dan rotasi tersebut berulang tiap 4 kali

    // Rotasi matriks
    salin(ordoMatriks, maks, p, q); // Salin p ke q karena nilai-nilai elemen p akan dirotasikan, tetapi posisi asli masih diperlukan
    rotasi(&ordoMatriks[1], maks, q, sum); // Rotasikan matriks q sebanyak sum kali

    sama = banding(ordoMatriks, maks, p, q); // Tampung nilai bolean kesamaan matriks p dan q
    if(sama == 0) refleksi(ordoMatriks[1], maks, q); // Jika tidak sama, refleksikan matriks q
    else transpose(&ordoMatriks[1], maks, q); // Jika sama, transpose matriks q

    // TAMPILKAN OUTPUT
    // Tampilkan matriks yang belum diolah beserta keterangannya
    printf("Matriks awal :\n");
    tampilkan(ordoMatriks[0], maks, p);
    
    // Tampilkan matriks yang telah diolah beserta keterangannya
    printf("\nMatriks akhir hasil %s :\n", akhir[sama]); // Tampilkan pernyataan terkait apa yang dilakukan terakhir kali terhadap matriks q
    tampilkan(ordoMatriks[1], maks, q);

    if(sama == 0) printf("Oops You Lose the game!\n"); // Jika tidak sama, kalah
    else printf("You are the Winner!\n"); // Jika sama, menang
    return 0;
}