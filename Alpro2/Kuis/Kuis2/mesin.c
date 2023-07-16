/*
    Saya Franklin Impianro Turnip(2203211) mengerjakan evaluasi Kuis 2 dalam mata kuliah Alpro II untuk keberkahanNya
    maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/
// PENGGUNAAN LIBRARY
#include "header.h"

// FUNTION & PROCEDURE
int komparasi(Pegawai p, Pegawai q, char asasPengurutan) {
    // DEKLARASI VARIABLE
    int komp; // flag yang menyatakan lebih kecil, sama dengan, xor leebih besar

    switch(asasPengurutan) { // bandingkan berdasarkan apa
        case 'g':
        if(p.gaji_pokok > q.gaji_pokok) {
            komp = 1;
        } else if(p.gaji_pokok < q.gaji_pokok) {
            komp = -1;
        } else {
            komp = 0;
        }
        break;
        case 'p':
        if(p.pendapatan > q.pendapatan) {
            komp = 1;
        } else if(p.pendapatan < q.pendapatan) {
            komp = -1;
        } else {
            komp = 0;
        }
        break;
    }

    return komp; // kembalikan nilai flag
}

void tukar(Pegawai *p, Pegawai *q) {
    // DEKLARASI VARIABLE
    Pegawai temp = (*p); // menyimpan sementara p pada tempat lain
    (*p) = (*q); // p disi dengan q
    (*q) = temp; // q diisi dengan value p sebelumnya yang telah disimpan pada temp
}

void quicksort(Pegawai arr[], int kiri, int kanan, char asasPengurutan) {
    // DEKLARASI VARIABLE
    int i, j; // iterator
    Pegawai pivot; // menyimpan data acuan(pivot)

    i = kiri, j = kanan; // iterasi i mengacu pada kiri dan j pada kanan
    pivot = arr[(kanan + kiri) / 2]; // pilih pivot berupa data di tengah

    do {
        while (komparasi(arr[i], pivot, asasPengurutan) == -1 && (i <= j)) { // cari data yang lebih kecil daripada pivot dari kiri array
            i++;
        }

        while (komparasi(pivot, arr[j], asasPengurutan) == -1 && (i <= j)) { // cari data yang lebih besar daripada pivot dari kanan array
            j--;
        }
        
        // setelah ditemukan dan iterator tidak menunjuk pada indeks yang sama, maka data perlu ditukar agar sesuai dengan kondisi yang ingin dipenuhi
        if (i < j) {
            // tukar kedua data yang ditunjuk
            tukar(&arr[i], &arr[j]);
            
            i++; // majukan iterator i karena data indeks ke-i telah benar
            j--; // mundurkan iterator j karena data indeks ke-j telah benar
        }
    } while (i < j); // lakukan terus hingga tidak ditemukan lagi kondisi tersebut atau dengan kata lain semua data telah diperiksa
    
    if (kiri < j && j < kanan) { // jika iterator j masih dalam batasan array yang diiterasikan, maka urutkan lagi dari indeks ke-kiri sampai j
        quicksort(arr, kiri, j, asasPengurutan);
    }
    if (i < kanan && i > kiri) { // jika iterator i masih dalam batasan array yang diiterasikan, maka urutkan lagi dari indeks ke-i sampai ke-kanan
        quicksort(arr, i, kanan,asasPengurutan);
    }
}

int binarySearch(int kiri, int kanan, Pegawai arr[], long long target, char acuan) {
    // DEKLARASI VARIABLE
    int tengah; // menyimpan nilai tengah index yang dilakukan pencarian
    int ditemukan = 0;// flag ditemukan(1) atau belumnya(0) posisi dari nilai data  yang sama dengan target
    int posisi = -1; // flag yang menyatakan posisi target pada arr, sehingga -1 diasumsikan sebagai ketidakmasukakalan atau ketidakadaan target pada arr
    int komp; // flag komparasi 2 data

    // untuk menyederhanakan algoritma, target yang dicari dimasukkan kedalam temp sesuai dengan acuannya, sehingga hanya diperlukan pemanggilan function komparasi pada function ini
    Pegawai temp;
    switch(acuan) {
        case 'g':
        temp.gaji_pokok = target;
        break;
        case 'p':
        temp.pendapatan = target;
        break;
    }

    while(ditemukan == 0 && kiri <= kanan) { // itetasi hingga ditemukan atau index kiri melebihi index kanan
        tengah = (kiri + kanan) / 2; // menghitung nilai tengah
        
        komp = komparasi(arr[tengah], temp, acuan); // membandingkan nilai yang di tengah dengan target
        
        if(komp != 0) { // apabila tidak sama
            if(komp == 1) { // apabila angkanya lebih besar, geser index kanan ke tengah - 1 karena diasumsikan data berada di sebelah kiri index tengah
                kanan = tengah - 1;
            } else { // apabila angkanya lebih kecil, geser index kiri ke tengah + 1 karena diasumsikan data berada di sebelah kanan index tengah
                kiri = tengah + 1;
            }
        } else { // apabila sama
            ditemukan = 1; // hentikan iterasi
        }
    }

    if(ditemukan != 0) { // apabila ditemukan
        posisi = tengah; // masukan posisi tempat ditemukannya
    }

    return posisi;
}

void printElement(Pegawai src) {
    printf("%s %s %s %lld %lld\n", src.no, src.nama, src.jabatan, src.gaji_pokok, src.tunjangan);
}