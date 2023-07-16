/*
    Saya Franklin Impianro Turnip(2203211) mengerjakan evaluasi TP4 dalam mata kuliah Alpro II untuk keberkahanNya
    maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/
// PENGGUNAAN LIBRARY
#include "header.h"

// MAIN
int main() {
    // DEKLARASI VARIABLE
    int banyakSiswa; // Banyak Siswa Beauxbatons
    char acuanSorting[4]; // Kode Acuan Sorting
    /*
     * Index | Value
     * 0       A(Ascending)/D(Descending)
     * 1       N(Nama)/U(Umur)
     * 2       I(Insertion)/S(Selection)
    */

    int jumlahASCII = 0, jumlahDataUMur = 0; // Jumlah ASCII nama dan data umur siswa indeks ke-0
    char asrama[4][50] = {"Adora Rourie\0", "Jocelin Cosu\0", "Boden Sournois\0", "Pyneres Cannes\0"}; // Semua nama asrama
    int idxAsrama; // indeks asrama yang ditempati anda

    int maksPanjangStr; // Nilai maks panjang nama siswa

    // INPUT DATA
    scanf("%d", &banyakSiswa); // Meminta masukkan dari user berupa banyak siswa di Beauxbatons

    IdentitasSiswa identitasSiswa[banyakSiswa]; // Mendeklarasi array identitasSiswa untuk menampung indetitas siswa
    for(int i = 0; i < banyakSiswa; i++) {
        scanf(" %s %d", identitasSiswa[i].nama, &identitasSiswa[i].umur); // Meminta masukkan dari user berupa nama dan umur seorang siswa
        identitasSiswa[i].pjgNama = strlen(identitasSiswa[i].nama); // Menghitung dan menyimpan panjang nama siswa tersebut
    }

    scanf("%s", acuanSorting); // Meminta masukan dari user berupa tiga acuan sorting dalam bentuk kode

    // PENGOLAHAN DATA
    hitungJumlahASCIUmur(&jumlahASCII, &jumlahDataUMur, identitasSiswa[0]); // Hitung jumlah ascii nama dan data umur siswa indeks ke-0 sebelum diubah

    if(acuanSorting[2] == 'I') { // Jika value indeks ke-2 berupa 'I', urutkan dengan algoritma insertion sort
        insertionSort(banyakSiswa, identitasSiswa, acuanSorting);
    } else { // Jika tidak, urutkan dengan selection sort
        selectionSort(banyakSiswa, identitasSiswa, acuanSorting);
    }

    hitungJumlahASCIUmur(&jumlahASCII, &jumlahDataUMur, identitasSiswa[0]); // Hitung jumlah ascii nama dan data umur siswa indeks ke-0 setelah diubah
    // Modulo 2 kedua jumlah tersebut untuk mengetahui genap atau ganjil kedua nilai
    jumlahASCII %= 2;
    jumlahDataUMur %= 2;

    // Jenis asrama berdasarkan kondisi-kondisi berikut
    // Kemudian simpan nilai indexnya di idxAsrama
    if(jumlahASCII == 0) {
        if(jumlahDataUMur == 0) {
            idxAsrama = 0;
        } else {
            idxAsrama = 1;
        }
    } else {
        if(jumlahDataUMur == 1) {
            idxAsrama = 2;
        } else {
            idxAsrama = 3;
        }
    }

    maksPanjangStr = cariMaksPjgStr(banyakSiswa, identitasSiswa); // Cari maks panjang nama

    // TAMPILKAN OUTPUT
    printf("Hasil setelah diurutkan :\n=========================\n");
    for(int i = 0; i < banyakSiswa; i++) { // Tampilkan nama dan umur selayaknya tabel, dengan jarak minimal 2 spasi
        printf("%s  ", identitasSiswa[i].nama);

        for(int j = identitasSiswa[i].pjgNama; j < maksPanjangStr; j++) {
            printf(" ");
        }

        printf("%d\n", identitasSiswa[i].umur);
    }
    printf("=========================\nSelamat, Anda masuk ke asrama %s!\n", asrama[idxAsrama]); // Tampilkan jenis asrama yang ditempati
    return 0;
}