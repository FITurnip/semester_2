/*
    Saya Franklin Impianro Turnip(2203211) mengerjakan evaluasi TP5 dalam mata kuliah Alpro II untuk keberkahanNya
    maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/
// PENGGUNAAN LIBRARY
#include "header.h"

// KEPERLUAN PENUNJANG
int pilihMaks(int p, int q) { // kembalikan nilai yang lebih besar p atau q
    if(p > q) {
        return p;
    } else {
        return q;
    }
}

int cariPanjangMaksimumString(int n, Sihir sihir[n]) {
    // DEKLARASI VARIABLE
    int maks = 0; // menampung 0 sebagai nilai sementara maksimum panjang string

    for(int i = 0; i < n; i++) { // looping terhadap tiap data sihir
        maks = pilihMaks(maks, strlen(sihir[i].namaMantra)); // perbarui dengan nilai yang lebih besar antara maks atau panjang sihir yang ditunjuk
    }

    return maks; // kembalikan nilai maks yang didapat
}

int hitungBanyakDigit(int n) {
    // DEKLARASI VARIABLE
    int banyakDigit = 0; // menampung 0 sebagai nilai sementara banyaknya digit n

    while(n != 0) { // looping selama banyak digit masih dapat dihitung, kecuali 0
        banyakDigit++; // diasumsikan banyak digit saat ini setidaknya pasti berjumlah pertambahan 1
        n /= 10; // membagi 10 agar bilangan n kehilangan 1 digit
    }

    return banyakDigit; // kembalikan nilai banyaknya digit yang telah didapat
}

void loopingPrint(int n, char c) {
    for(int i = 0; i < n; i++) { // looping terhadap semua karakter c yang akan ditampilkan
        printf("%c", c); // tampilkan karakter c
    }
}

void hitungLebarKolom(int n, Sihir sihir[n], int lebarKolom[4]) { // menghitung lebar kolom yang dibutuhkan
    // DEKLARASI VARIABLE
    int maksBanyakDigitWaktu = 0; // menampung 0 sebagai nilai sementara maksimum banyak digit waktu

    // Hitung lebar kolom tabel
    lebarKolom[0] = 3 + hitungBanyakDigit(n); // lebar kolom nomor

    lebarKolom[1] = pilihMaks(13, 3 + cariPanjangMaksimumString(n, sihir)); // lebar kolom nama mantra

    lebarKolom[2] = 13; // lebar kolom mp

    for(int i = 0; i < n; i++) { // looping terhadap semua data sihir
        // perbarui dengan nilai yang lebih besar antara maks atau banyaknya digit waktu sihir yang ditunjuk
        maksBanyakDigitWaktu = pilihMaks(maksBanyakDigitWaktu, hitungBanyakDigit(sihir[i].waktu));
    }

    lebarKolom[3] = pilihMaks(7, 3 + maksBanyakDigitWaktu); // lebar kolom waktu
}

void tukarDataSihir(Sihir *p, Sihir *q) { // Tukar data sihir p dan q
    Sihir temp = (*p);
    (*p) = (*q);
    (*q) = temp;
}

void tukarInt(int *p, int *q) { // Tukar int sihir p dan q
    int temp = (*p);
    (*p) = (*q);
    (*q) = temp;
}

// KEPERLUAN MENAMPILKAN OUTPUT
void borderBaris(int lebarKolom[4]) {
    for(int i = 0; i < 4; i++) { // looping terhadap semua kolom
        printf("+"); // tampilkan + sebagai pembatas antar kolom
        loopingPrint(lebarKolom[i], '-'); // tampilkan '-' sebagai pembatas antar baris
    }
    printf("+\n"); // tampilkan pembatas kolom dan akhiri kolom dengan baris baru
}

void printElemen(int n, Sihir sihir[n]) {
    // DEKLARASI VARIABLE
    int lebarKolom[4]; // lebar keempat kolom tabel

    hitungLebarKolom(n, sihir, lebarKolom); // hitung lebar kolomnya

    borderBaris(lebarKolom); // tampilkan border baris
    
    // tampilkan table header
    printf("| No");
    loopingPrint(lebarKolom[0] - 3, ' ');
    printf("| Nama Mantra");
    loopingPrint(lebarKolom[1] - 12, ' ');
    printf("| Magic Power | Waktu");
    loopingPrint(lebarKolom[3] - 6, ' ');
    printf("|\n");

    borderBaris(lebarKolom); // tampilkan border baris

    // tampilkan data sihir
    for(int i = 0; i < n; i++) { // looping terhadap semua data sihir
        // tampilkan nomor urut
        printf("| ");
        printf("%d", i + 1);
        loopingPrint(lebarKolom[0] - hitungBanyakDigit(i + 1) - 1, ' ');

        // tampilkan nama mantra sihir ke-i
        printf("| ");
        printf("%s", sihir[i].namaMantra);
        loopingPrint(lebarKolom[1] - strlen(sihir[i].namaMantra) - 1, ' ');

        // tampilkan nama magic power sihir ke-i
        printf("| ");
        printf("%d", sihir[i].mp);
        loopingPrint(lebarKolom[2] - hitungBanyakDigit(sihir[i].mp) - 1, ' ');

        // tampilkan waktu penguaasan sihir ke-i
        printf("| ");
        printf("%d", sihir[i].waktu);
        loopingPrint(lebarKolom[3] - hitungBanyakDigit(sihir[i].waktu) - 1, ' ');
        printf("|\n");
    }

    borderBaris(lebarKolom); // tampilkan border baris
}

// KEPERLUAN SORTING
int komp(Sihir p, Sihir q, char jenis) {
    // DEKLARASI VARIABLE
    int flag = 0; // flag 0 berarti data sudah terurut, 1 berarti belum
    int lenP = strlen(p.namaMantra), lenQ = strlen(q.namaMantra); // menampung panjang string nama mantra sihir p dan q

    // Komparasi di bawah dianggap dari data yang lebih ke keci

    if(jenis == 'K') { // Jika diurutkan dari kecil ke besar, maka tukar sehingga pengolahan di bawah akan berperilaku seolah-olah negasi dari yang seharusnya
        tukarDataSihir(&p, &q);
        tukarInt(&lenP, &lenQ);
    }

    if(lenP < lenQ) {
        flag = 1; // tidak lebih besar daripada p berdasarkan panjang string
    } else if(lenP == lenQ) {
        if(p.mp < q.mp) { // karena sama, perhitungkan berdasarkan magic power
            flag = 1;
        }
    }

    return flag; // kembalikan nilai flag
}

void bSorting(int n, Sihir arr[n], char jenis) {
    // DEKLARASI VARIABLE
    int i, j; // Iterator
    int swap; // flag terjadi pertukaran(1) atau tidak(0)

    do {
        swap = 0; // Dianggap tidak terjadi pertukaran karena belum terjadi
        for (i = 0; i < n - 1; i++) { // looping terhadap n - 1 data sihir karena akan mengecek i + 1 pada tiap sub kasus
            if (komp(arr[i], arr[i + 1], jenis) == 1) { // komparasi sihir i dan i + 1, apakah perlu diurutkan atau tidak
                // jika perlu diurutkan, tukar kedua data yang ditunjuk
                tukarDataSihir(&arr[i], &arr[i + 1]);

                // tanda bahwa ada data yang ditukar
                swap = 1;
            }
        }
    } while (swap  == 1); // looping selama terjadi pertukaran
}

void qsTengah(Sihir arr[], int kiri, int kanan, char jenis) {
    // DEKLARASI VARIABLE
    int i, j; // iterator
    Sihir pivot; // menyimpan data acuan(pivot)

    i = kiri, j = kanan; // iterasi i mengacu pada kiri dan j pada kanan
    pivot = arr[(kanan + kiri) / 2]; // pilih pivot berupa data di tengah

    do {
        /*
            jenis = 'B' berarti diurutkan dari besar ke kecil--lebih lengkapnya ada pada procedure komp
            pindahkan data yang lebih besar ke kanan pivot dan sebaliknya
        */
        while (komp(pivot, arr[i], jenis) == 1 && (i <= j)) { // cari data yang lebih kecil daripada pivot dari kiri array
            i++;
        }

        while (komp(arr[j], pivot, jenis) == 1 && (i <= j)) { // cari data yang lebih besar daripada pivot dari kanan array
            j--;
        }
        
        // setelah ditemukan dan iterator tidak menunjuk pada indeks yang sama, maka data perlu ditukar agar sesuai dengan kondisi yang ingin dipenuhi
        if (i < j) {
            // tukar kedua data yang ditunjuk
            tukarDataSihir(&arr[i], &arr[j]);

            i++; // majukan iterator i karena data indeks ke-i telah benar
            j--; // mundurkan iterator j karena data indeks ke-j telah benar
        }
    } while (i < j); // lakukan terus hingga tidak ditemukan lagi kondisi tersebut atau dengan kata lain semua data telah diperiksa
    
    if (kiri < j && j < kanan) { // jika iterator j masih dalam batasan array yang diiterasikan, maka urutkan lagi dari indeks ke-kiri sampai j
        qsTengah(arr, kiri, j, jenis);
    }
    if (i < kanan && i > kiri) { // jika iterator i masih dalam batasan array yang diiterasikan, maka urutkan lagi dari indeks ke-i sampai ke-kanan
        qsTengah(arr, i, kanan, jenis);
    }
}

// KEPERLUAN PENCARIAN MAKS SIHIR YANG DAPAT DIKUASAI
int cariMaksSihirYgDptDikuasai(int n, Sihir arr[n], int batasWaktu) {
    // DEKLARASI VARIABLE
    int maks = 0; // menampung 0 sebagai nilai sementara maksimum sihir yang dapat dikuasai
    int i = 0; // iterator

    while(i < n && batasWaktu > 0) { // iterasi dari 0 sampai n dan masih dalam kondisi waktu belum dihabis dipakai
        if(arr[i].waktu <= batasWaktu) { // jika masih ada waktu untuk menguasai, pakai waktu
            batasWaktu -= arr[i].waktu;
            maks++;
            i++;
        } else { // jika tidak, hentikan looping dengan menganggap bawah itarator mencapai batas pengecekan
            i = n;
        }
    }

    return maks; // Kembalikan nilai maks
}