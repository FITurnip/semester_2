/*
    Saya Franklin Impianro Turnip(2203211) mengerjakan evaluasi TP5 dalam mata kuliah Alpro II untuk keberkahanNya
    maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/
// PENGGUNAAN LIBRARY
#include "header.h"
int pilihMaks(int a, int b) {
    int maks = a; // awalnya, dianggap bahwa a >= b
    if(b > a) { // jika salah, perbaiki nilai maks
        maks = b;
    }
    return maks; // kembalikan nilai maks
}

int cariPanjangMaksimumString(int n, Murid arr[]) {
    // DEKLARASI VARIABLE
    int maks = 0; // menampung 0 sebagai nilai sementara maksimum panjang string

    for(int i = 0; i < n; i++) { // looping terhadap tiap data arr
        maks = pilihMaks(maks, strlen(arr[i].nama)); // perbarui dengan nilai yang lebih besar antara maks atau panjang arr yang ditunjuk
    }

    return maks; // kembalikan nilai maks yang didapat
}

int komp(Murid a, Murid b, char asasKomparasi) {
    // DEKLARASI VARIABLE
    int flag = 0; // makna flag bergantung dari pada cara pendefinisian kondisi yang memerlukan function flag

    switch(asasKomparasi) { // flag asas komparasi ada
        case 'S': // Jika spell, maka komparasi spellnya
        if(strcmp(a.spell, b.spell) < 0) {
            flag = 1;
        }
        break;
        case 'P': // Jika power, maka komparasi powernya
        if(a.power > b.power) {
            flag = 1;
        }
        break;
    }
    return flag; // kembalikan nilai flag yang didapat
}

void merge(Murid arr1[], int n1, Murid arr2[], int n2, Murid arr3[], char asasPengurutan) {
    // DEKLARASI VARIABLE
    int i1 = 0, i2 = 0, i3 = 0;

    // ulangi hingga arr1 habis atau arr2 habis
    while ((i1 < n1) && (i2 < n2)) {
        // jika elemen teratas arr1 lebih kecil dari arr2
        if (komp(arr1[i1], arr2[i2], asasPengurutan) == 1) {
            // masukkan elemen teratas arr1 ke dalam arr3
            arr3[i3] = arr1[i1];
            i3++;
            i1++;
        }
        // jika elemen teratas arr1 lebih besar dari arr2
        else {
            // masukkan elemen teratas arr2 ke dalam arr3
            arr3[i3] = arr2[i2];
            i3++;
            i2++;
        }
    }

    // masukkan sisa arr1 jika ada
    while(i1 < n1) {
        arr3[i3] = arr1[i1];
        i3++;
        i1++;
    }
    // masukkan sisa arr2 jika ada
    while(i2 < n2) {
        arr3[i3] = arr2[i2];
        i3++;
        i2++;
    }
}

void qsTengah(Murid arr[], int kiri, int kanan, char asasPengurutan) {
    // DEKLARASI VARIABLE
    int i, j; // iterator
    Murid temp, pivot; // menyimpan data acuan(pivot)

    i = kiri, j = kanan; // iterasi i mengacu pada kiri dan j pada kanan
    pivot = arr[(kanan + kiri) / 2]; // pilih pivot berupa data di tengah

    do {
        while (komp(arr[i], pivot, asasPengurutan) == 1 && (i <= j)) { // cari data yang lebih kecil daripada pivot dari kiri array
            i++;
        }

        while (komp(pivot, arr[j], asasPengurutan) == 1 && (i <= j)) { // cari data yang lebih besar daripada pivot dari kanan array
            j--;
        }
        
        // setelah ditemukan dan iterator tidak menunjuk pada indeks yang sama, maka data perlu ditukar agar sesuai dengan kondisi yang ingin dipenuhi
        if (i < j) {
            // tukar kedua data yang ditunjuk
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            
            i++; // majukan iterator i karena data indeks ke-i telah benar
            j--; // mundurkan iterator j karena data indeks ke-j telah benar
        }
    } while (i < j); // lakukan terus hingga tidak ditemukan lagi kondisi tersebut atau dengan kata lain semua data telah diperiksa
    
    if (kiri < j && j < kanan) { // jika iterator j masih dalam batasan array yang diiterasikan, maka urutkan lagi dari indeks ke-kiri sampai j
        qsTengah(arr, kiri, j, asasPengurutan);
    }
    if (i < kanan && i > kiri) { // jika iterator i masih dalam batasan array yang diiterasikan, maka urutkan lagi dari indeks ke-i sampai ke-kanan
        qsTengah(arr, i, kanan, asasPengurutan);
    }
}

void scanElement(int n, Murid *arr, char asrama) {
    // iterasi terhadap semua data arr
    for(int i = 0; i < n; i++) {
        scanf(" %s %d %s", arr[i].nama, &arr[i].power, arr[i].spell);
        arr[i].asrama = asrama;
    }
}

void printElement(int n, Murid *arr) {
    // DEKLARASI VARIABLE
    int maksPanjangString = cariPanjangMaksimumString(n, arr); // cari panjang maksimum string pada arr

    // iterasi terhadap semua data arr
    for(int i = 0; i < n; i++) {
        printf("%s", arr[i].nama);

        // tampilkan spasi agar tampak rapih
        for(int j = strlen(arr[i].nama); j < maksPanjangString; j++) {
            printf(" ");
        }

        printf(" %c", arr[i].asrama);

        printf(" %d", arr[i].power);

        printf(" %s\n", arr[i].spell);
    }
}

int hitungJumlahBerangkat(int n, Murid *arr, int minimalJumlahPower) {
    // DEKLARASI VARIABLE
    int i = n - 1; // Iterator yang akan mengiterasi dari ujung kanan

    while(i >= 0 && minimalJumlahPower > 0) { // Pada dasarnya, berhenti saat minimal jumlah power sudah terpenuhi atau semua data telah diiterasi
        minimalJumlahPower -= arr[i].power; // berkurang karena adanya power yang dapat memenuhi persyaratan minimal jumlah power
        i--;
    }

    return i + 1; // Jumlah yang berangkat adalah i + 1, karena i hanya menunjuk indeksnya bukan jumlahnya
}

int hitungTotalPower(int awal, int akhir, Murid *arr) {
    // DEKLARASI VARIABLE
    int total = 0; // Menampung sementara total powernya

    for(int i = awal; i < akhir; i++) {
        total += arr[i].power; // total power bertambah hingga iterasi berakhir
    }

    return total; // Kembalikan nilai total yang didapat
}