/*
    Saya Franklin Impianro Turnip(2203211) mengerjakan evaluasi TP5 dalam mata kuliah Alpro II untuk keberkahanNya
    maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/
// PENGGUNAAN LIBRARY
#include "header.h"
int hitungFaktorialParsial(int n, int batas) {
    // function ini akan menghitung n * (n - 1) * .. * (batas + 1)
    // karena n! / batas! sama saja dengan pola di atas
    if(n == batas) { // sehingga base casenya berada pada batas
        return 1; // kembalikan 1 agar tidak dikalikan dengan batas saat bertemu base case
    } else { // selama belum bertemu base case, n akan berkurang sebanyak satu kali
        return n * hitungFaktorialParsial(n - 1, batas);
    }
}

int hitungKombinasi(int n, int k) {
    // rumus P(n, k) = n! / ((n - k)! * k!)
    // sehingga secara algoritmatis dapat disederhanakan menjadi
    // pembilangnya berupa (n - max(n - k, k))!
    // penyebutnya berupa min(n - k, k)!

    // DEKLARASI VARIABLE
    int a = n - k; // menyimpan nilai awal faktorial (n - k)!
    int terbesar = a, terkecil = k; // mengasumsikan awalnya a lebih besar daripada k
    int pembilang, penyebut; // pembilang dan penyebut untuk asumsi awal
    int kombinasi; // menyimpan hasil P(n, k)
    if(terbesar < k) { // jika asumsi angka terbesar salah, maka tukar nilai terbesar dan terkecil
        terbesar = k;
        terkecil = a;
    }

    pembilang = hitungFaktorialParsial(n, terbesar); // menghitung (n - max(n - k, k))!

    penyebut = hitungFaktorialParsial(terkecil, 0); // menghitung min(n - k, k)!

    kombinasi = pembilang / penyebut; // menghitung kombinasinya
    return kombinasi; // mengembalikan nilai kombinasi
}

void tukarAtom(Atom *p, Atom *q) {
    Atom temp = (*p); // simpan terlebih dahulu data p ke tempat sementara
    (*p) = (*q); // simpan data q ke tempat p
    (*q) = temp; // ambil data p dari tempat sementara ke data q
}

void bangkitkanKombinasi(Atom *src, Kombinasi *kombinasi, Atom temp[3], int kiriN, int n, int kiriK, int k, int *posKombinasi) {
    if(kiriK < k) { // base case berada pada k data yang sudah disusun membentuk 1 hasil kombinasi
        // karena belum mencapai base case, cari terlebih dahulu susunannya
        for(int i = kiriN; i < n; i++) {
            temp[kiriK] = src[i]; // isi data temp ke-kiriK dari data src ke-i untuk memenuhi susunan kombinasi
            bangkitkanKombinasi(src, kombinasi, temp, i + 1, n, kiriK + 1, k, posKombinasi); // cari data berikutnya untuk disusun
        }
    } else { // jika sudah tersusun 1 data, masukkan data susunan yang terbentuk pada temp ke data kombinasi
        for(int i = 0; i < k; i++) {
            kombinasi[(*posKombinasi)].arr[i] = temp[i];
        }
        (*posKombinasi)++; // naikkan indeks kombinasi karena data kombinasi ada yang sudah diisi
    }
}

void hitungDataKombinasi(Kombinasi *src) {
    // untuk menghitung rasio, hitung terlebih dahulu total nomor dan performanya
    (*src).totalNo = 0; // 0 mengartikan asumsi belum terjadi perhitungan
    (*src).totalPerforma = 0; // seperti di atas

    for(int i = 0; i < 3; i++) { // iterasi terhadap data yang disimpan pada src
        // tambahkan data k-i ke dalam total
        (*src).totalNo += (*src).arr[i].no;
        (*src).totalPerforma += (*src).arr[i].performa;
    }

    (*src).rasio = (*src).totalPerforma / (*src).totalNo; // hitung rasio
}

int komparasiDouble(double p, double q) {
    // DEKLARASI VARIABLE
    int flag; // flag komparasi p dan q

    // flaag -1, mengartikan p < q; 0 mengartikan p = q; 1 mengartikan p > q
    if(p < q) {
        flag = -1;
    } else if(p > q) {
        flag = 1;
    } else {
        flag = 0;
    }

    return flag; // kemablikan nilai flag
}

int sequentialSearch(int i, int n, Kombinasi arr[], double target) {
    // DEKLARASI VARIABLE
    int ditemukan = 0; // flag ditemukan(1) atau belumnya(0) posisi dari nilai data yang lebih besar atau sama dengan target

    // iterasi hingga semua data dicek atau ditemukan target
    while(i < n && ditemukan == 0) {
        if(komparasiDouble(arr[i].rasio, target) == -1) { // jika data ke-i masih lebih kecil dari target
            i++; // lanjutkan iterasi
        } else { // jika tidak
            ditemukan = 1; // hentikan iterasi
        }
    }

    return i; // kembalikan posisi akhir pengecekan
    // akan mengambalikan nilai n apabila tidak ditemukan
}

int binarySearch(int kiri, int kanan, Kombinasi arr[], double target) {
    // DEKLARASI VARIABLE
    int tengah; // menyimpan nilai tengah index yang dilakukan pencarian
    int ditemukan = 0;// flag ditemukan(1) atau belumnya(0) posisi dari nilai data  yang sama dengan target
    int posisi = -1; // flag yang menyatakan posisi target pada arr, sehingga -1 diasumsikan sebagai ketidakmasukakalan atau ketidakadaan target pada arr
    int komp; // flag komparasi 2 data

    while(ditemukan == 0 && kiri <= kanan) { // itetasi hingga ditemukan atau index kiri melebihi index kanan
        tengah = (kiri + kanan) / 2; // menghitung nilai tengah
        
        komp = komparasiDouble(arr[tengah].rasio, target); // membandingkan nilai yang di tengah dengan target
        if(komp != 0) { // apabila tidak sama
            if(komp > 0) { // apabila angkanya lebih besar, geser index kanan ke tengah - 1 karena diasumsikan data berada di sebelah kiri index tengah
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

void insertionSort(int kiri, int kanan, Kombinasi *arr) {
    // DEKLARASI VARIABLE
    int i, j; // Iterator
    Kombinasi temp; // tempat menampung sementara satu data dari arr

    for(i = kiri; i <= kanan; i++) { // iterasi dari kiri hingga kanan
        temp = arr[i]; // tampung data ke-i ke tempat sementara
        
        // mulai iterasi dari i - 1
        j = i - 1;
        while(j >= 0 && komparasiDouble(temp.rasio, arr[j].rasio) == -1) { // itearsi selama index masih dalam batasan atau masih terdapat susunan yang tidak terurut
            // geser data agar seolah-olah terjadi penyisipan
            arr[j + 1] = arr[j];
            j--;
        }

        // lakukan penyisipan
        arr[j + 1] = temp;
    }
}

void printElement(Kombinasi src) { // tampilkan data src
    // tampilkan 3 daata nama atom
    printf("{");
    for(int i = 0; i <  3; i++) {
        if(i > 0) {
            printf(", ");
        }

        printf("%s", src.arr[i].nama);
    }

    printf("}\n");

    // tampilkan total nomor atom, performa, dan rasionya
    
    printf("TotalNoAtom: %.0lf\n", src.totalNo);
    printf("TotalPerforma: %.0lf\n", src.totalPerforma);
    printf("Rasio: %.2lf\n", src.rasio);
}