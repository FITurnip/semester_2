/*
    Saya Franklin Impianro Turnip(2203211) mengerjakan evaluasi TP5 dalam mata kuliah Alpro II untuk keberkahanNya
    maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/
// PENGGUNAAN LIBRARY
#include "header.h"

// MEMINTA DATA DARI USER YANG TUJUAN AKHIRNYA SDIMASUKKAN FILE TERKAIT
int scanBarang(int akhirPos, char *nama_file, Barang *arr) {
    // DEKLRASI VARIABLE
    int n; // banyaknya record data baru

    // MEMINTA INPUT DARI USER
    // banyak record data baru
    printf("Banyak data baru: ");
    scanf("%d", &n);

    // karena akan memasukkan data baru mulai dari akhir posisi record data lama, tambahkan n dengan akhirPosisi
    n += akhirPos;

    // data-data record yang diperlukan
    for(int i = akhirPos; i < n; i++) {
        printf("Masukkan data ke-%d:\n", i - n + 1);
        printf("Nama\t\t: ");
        scanf("%s", arr[i].nama);
        printf("ID Kategori\t: ");
        scanf("%s", arr[i].id_kategori);
        printf("ID Merk\t\t: ");
        scanf("%s", arr[i].id_merk);
        printf("ID Toko\t\t: ");
        scanf("%s", arr[i].id_toko);
        
        printf("\n");
    }
    
    // agar tampilannya nyaman, perlihatkan pemberitahuan dan bekukan layar sebentar
    system("clear");
    printf("Harap Tunggu..\n");
    jeda(0.01);

    return tulisFileBarang(n, nama_file, arr); // permanenkan data dengan cara menulis data yang diinput user ke file
}

int scanSimpleData(int akhirPos, char *nama_file, SimpleData *arr) {
    // DEKLRASI VARIABLE
    int n; // banyaknya record data baru

    // MEMINTA INPUT DARI USER
    // banyak record data baru
    printf("Banyak data baru: ");
    scanf("%d", &n);

    // karena akan memasukkan data baru mulai dari akhir posisi record data lama, tambahkan n dengan akhirPosisi
    n += akhirPos;

    // data-data record yang diperlukan
    for(int i = akhirPos; i < n; i++) {
        printf("Masukkan data ke-%d:\n", i - n + 1);

        printf("ID\t: ");
        scanf("%s", arr[i].id);
        printf("Nama\t: ");
        scanf("%s", arr[i].nama);

        printf("\n");
    }
    
    // agar tampilannya nyaman, perlihatkan pemberitahuan dan bekukan layar sebentar
    system("clear");
    printf("Harap Tunggu..\n");
    jeda(0.01);

    return tulisSimpleData(n, nama_file, arr); // permanenkan data dengan cara menulis data yang diinput user ke file
}

// MEMBACA FILE UNTUK DISIMPAN KE STRUCT TERKAIT
int bacaFileBarang(char *nama_file, Barang *dst) {
    // DEKLARASI VARIABLE
    int i = 0; // iterator
    FILE *file = fopen(nama_file, "r"); // penyimpanan file dengan mode baca

    // baca semua data pada file dan masukkan ke destinasi(dst)
    do {
        fscanf(file, "%s %s %s %s", dst[i].nama, dst[i].id_kategori, dst[i].id_merk, dst[i].id_toko);
        i++;
    } while(strcmp(dst[i - 1].nama, "####") != 0); // hentikan saat ditemukan data yang nilainya sama dengan batasan file

    fclose(file); // tutup file

    return i - 1; // kembalikan banyak data
}

int bacaFileSimpleData(char *nama_file, SimpleData *dst) {
    // DEKLARASI VARIABLE
    int i = 0; // iterator
    FILE *file = fopen(nama_file, "r"); // penyimpanan file dengan mode baca

    // baca semua data pada file dan masukkan ke destinasi(dst)
    do {
        fscanf(file, "%s %s", dst[i].id, dst[i].nama);
        i++;
    } while(strcmp(dst[i - 1].nama, "####") != 0); // hentikan saat ditemukan data yang nilainya sama dengan batasan file

    fclose(file); // tutup file

    return i - 1; // kembalikan banyak data
}

int bacaFileBarangFinal(char *nama_file, BarangFinal *dst) {
    // DEKLARASI VARIABLE
    int i = 0; // iterator
    FILE *file = fopen(nama_file, "r"); // penyimpanan file dengan mode baca

    // baca semua data pada file dan masukkan ke destinasi(dst)
    do {
        fscanf(file, "%s %s %s %s", dst[i].nama, dst[i].kategori, dst[i].merk, dst[i].toko);
        i++;
    } while(strcmp(dst[i - 1].nama, "####") != 0); // hentikan saat ditemukan data yang nilainya sama dengan batasan file

    fclose(file); // tutup file

    return i - 1; // kembalikan banyak data
}

// MENULIS DATA PADA STRUCT KE FILE
int tulisFileBarang(int n, char *nama_file, Barang *src) {
    // DEKLARASI VARIABLE
    FILE *file = fopen(nama_file, "w"); // penyimpanan file dengan mode tulis
    int i; // iterator

    for(i = 0; i < n; i++) { // tulis semua data pada source(src) ke file
        fprintf(file, "%s %s %s %s\n", src[i].nama, src[i].id_kategori, src[i].id_merk, src[i].id_toko);
        printf("%d data selesai\n", i + 1);
    }

    fprintf(file, "#### #### #### ####\n"); // tulis batas data ke file

    fclose(file); // tutup file

    return i; // kembalikan banyak data
}

int tulisSimpleData(int n, char *nama_file, SimpleData *src) {
    // DEKLARASI VARIABLE
    FILE *file = fopen(nama_file, "w"); // penyimpanan file dengan mode tulis
    int err = 0; // flag error
    int i = 0; // iterator

    while(i < n && err == 0) { // berhenti saat i mencapai batas atau ditemukan error
        if(binarySearch(0, i - 1, src, src[i].id) == -1) { // jika id adalah baru, maka tidak error dan tulis data
            fprintf(file, "%s %s\n", src[i].id, src[i].nama);
            printf("%d data selesai\n", i + 1);

            i++; // iterasi
        } else { // karena error berupa id duplicate, flag jenis error adalah 2
            tampilkanError(i + 1, src[i].id, src[i].nama, "\b", "\b", 2);
            err = 1; // flag ganti ke error yaitu 1
        }
    }

    fprintf(file, "#### ####\n"); // tulis batas data ke file

    fclose(file); // tutup file

    return i; // kembalikan banyak data
}

int tulisFileBarangFinal(int n, char *nama_file, BarangFinal *src) {
    // DEKLARASI VARIABLE
    FILE *file = fopen(nama_file, "w"); // penyimpanan file dengan mode tulis
    int i; // iterator

    for(i = 0; i < n; i++) { // tulis semua data pada source(src) ke file
        fprintf(file, "%s %s %s %s\n", src[i].nama, src[i].kategori, src[i].merk, src[i].toko);
    }

    fprintf(file, "#### #### #### ####\n"); // tulis batas data ke file

    fclose(file); // tutup file

    return i; // kembalikan banyak data
}

// MEMASUKKAN DATA BARANG KE BARANG FINAL DENGAN PEMBEDANYA BERUPA ID SUDAH DIGANTI DENGAN NAMA DATA TERKAIT
int finalisasiBarang(BanyakData banyakData, Barang *srcLB, SimpleData *srcKategori, SimpleData *srcMerk, SimpleData *srcToko, BarangFinal *dst) {
    // DEKLRASI VARIABLE
    int posKategori, posMerk, posToko; // posisi suatu data pada tabel tertentu
    int i = 0; // iterator
    int err = 0; // flag error

    while(i < banyakData.barang && err == 0) { // berhenti saat i mencapai batas atau ditemukan error
        // cari posisi data terkait id pada tabel terkait
        posKategori = binarySearch(0, banyakData.kategori, srcKategori, srcLB[i].id_kategori);
        posMerk = binarySearch(0, banyakData.merk, srcMerk, srcLB[i].id_merk);
        posToko = binarySearch(0, banyakData.toko, srcToko, srcLB[i].id_toko);

        if(posKategori != -1 && posMerk != -1 && posToko != -1) { // jika data barang memiliki relasi dengan semua id, finalisasi data barang
            strcpy(dst[i].nama, srcLB[i].nama);
            strcpy(dst[i].kategori, srcKategori[posKategori].nama);
            strcpy(dst[i].merk, srcMerk[posMerk].nama);
            strcpy(dst[i].toko, srcToko[posToko].nama);

            i++; // iterasi
        } else {
            // agar tampilannya nyaman, perlihatkan pemberitahuan dan bekukan layar sebentar
            tunggu(0.5);
            system("clear");
            tampilkanError(i, srcLB[i].nama, srcLB[i].id_kategori, srcLB[i].id_merk, srcLB[i].id_toko, 1); // jenis error berupa data tidak berelasi sehingga flagnya 1
            jeda();

            err = 1; // ganti ke flag error
        }
    }

    return i; // kembalikan banyaknya data
}

// PENCARIAN DATA
int binarySearch(int kiri, int kanan, SimpleData arr[], char *target) {
    // DEKLARASI VARIABLE
    int tengah; // menyimpan nilai tengah index yang dilakukan pencarian
    int ditemukan = 0;// flag ditemukan(1) atau belumnya(0) posisi dari nilai data  yang sama dengan target
    int posisi = -1; // flag yang menyatakan posisi target pada arr, sehingga -1 diasumsikan sebagai ketidakmasukakalan atau ketidakadaan target pada arr
    int komp; // flag komparasi 2 data

    while(ditemukan == 0 && kiri <= kanan) { // itetasi hingga ditemukan atau index kiri melebihi index kanan
        tengah = (kiri + kanan) / 2; // menghitung nilai tengah
        
        komp = strcmp(arr[tengah].id, target); // membandingkan nilai yang di tengah dengan target
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
        posisi = tengah; // masukkan posisi tempat ditemukannya
    }

    return posisi;
}

// MENAMPILKAN KONTEN KEPADA USER
void tampilkanData(int n, BarangFinal *src) {
    printf("Table List Barang Final\n"); // judul
    
    if(n == 0) { // jika data tidak ada
        printf("Tidak ada data\n");
    } else { // jika ada data
        int maksKolom[4] = {4, 9, 4, 4}; // masukkan nilai default maks lebar kolom, berdasarkan table header

        mencariMaksKolom(n, src, maksKolom); // hitung ulang nilai maks lebar kolom berdasarkan table header dan data-data pada kolom

        tampilkanHeadertable(maksKolom); // tampilkan header

        for(int i = 0; i < n; i++) { // tampilkan data-data sesuai kolomnya
            tampilkanKolom(maksKolom[0], src[i].nama, '|', 0);
            tampilkanKolom(maksKolom[1], src[i].kategori, '|', 0);
            tampilkanKolom(maksKolom[2], src[i].merk, '|', 0);
            tampilkanKolom(maksKolom[3], src[i].toko, '|', 1);
        }

        tampilkanBatasHrzTable(maksKolom); // tampilkan batas table paling bawah
    }
}

void tampilkanError(int pos, char a[], char b[], char c[], char d[], int jenisError) {
    printf("ERROR\n"); // judul
    printf("DATA ke-%d ", pos); // posisi data error

    // isi data
    printf("%s ", a);
    printf("%s ", b);
    printf("%s ", c);
    printf("%s ", d);

    // tampilkan jenis errornya
    switch(jenisError) {
        case 1:
        printf("TIDAK DAPAT MEMILIKI RELASI\n");
        break;
        case 2:
        printf("SUDAH DIGUNAKAN ID-NYA");
        break;
    }
}

// TAMPILKAN BATASAN TABEL
void tampilkanHeadertable(int lebarKolom[4]) {
    // DEKLARASI VARIABLE
    char headerTable[4][9] = {{"Nama\0"}, {"Kategori\0"}, {"Merk\0"}, {"Toko\0"}}; // nama field atau table header
    
    tampilkanBatasHrzTable(lebarKolom); // batas atas header

    for(int i = 0; i < 4; i++) { // tampilkan nama field dan batasnya
        if(i != 3) {
            tampilkanKolom(lebarKolom[i], headerTable[i], '|', 0);
        } else {
            tampilkanKolom(lebarKolom[i], headerTable[i], '|', 1);
        }
    }

    tampilkanBatasHrzTable(lebarKolom); // batas bawah header
}

void tampilkanKolom(int lebarKolom, char str[], char batas, int batasiUjung) {
    printf("%c %s", batas, str); // tampilkan batas samping kiri dan string yang hendak ditampilkan

    for(int i = strlen(str) - 1; i < lebarKolom; i++) { // tampilkan sisa space kolom agar membentuk table
        printf(" ");
    }

    if(batasiUjung == 1) { // jika flagnya menandakan batas ujung diperlukan atau bernilai 1, tampilkan batas samping kanan
        printf("%c\n", batas);
    }
}

// SUB-PROGRAM TAMBAHAN
void tunggu(float x) {
    // DEKLARASI VARIABLE
    time_t start; // Waktu memulai
    time_t current; // Waktu saat ini

    time(&start); // masukkan data waktu mulai
    do {
        time(&current); // masukkan data waktu saat ini
    } while(difftime(current, start) < x); // hentikan saat selisih data waktu saat ini dan saat mulai adalah x atau lebih dari x
}

void jeda() {
    // DEKLARASI VARIABLE
    char sampah[100]; // menggunakan char untuk menghindari error
    
    // MENAMPILKAN PESAN
    printf("\nTekan keyboard untuk kembali... ");
    scanf("%s", sampah);
}

void mencariMaksKolom(int banyakBarangFinal, BarangFinal *src, int maksKolom[4]) {
    // DEKLARASI VARIABLE
    int tempLen[4]; // menyimpan panjang string yang akan dicari

    for(int i = 0; i < banyakBarangFinal; i++) { // iterasi terbadap semua data sumber(src)
        // hitung panjang string terkait
        tempLen[0] = strlen(src[i].nama);
        tempLen[1] = strlen(src[i].kategori);
        tempLen[2] = strlen(src[i].merk);
        tempLen[3] = strlen(src[i].toko);

        // perbaiki panjang maks terkini
        for(int j = 0; j < 4; j++) {
            if(maksKolom[j] < tempLen[j]) {
                maksKolom[j] = tempLen[j];
            }
        }
    }
}

void tampilkanBatasHrzTable(int lebarKolom[4]) {
    for(int i = 0; i < 4; i++) { // iterasi terhadap semua kolom
        printf("+"); // tampilkan batas samping kiri
        for(int j = -2; j < lebarKolom[i]; j++) { // iterasi terhadap kolom ke-i
            printf("-"); // tampilkan batas menyamping
        }
    }

    printf("+\n"); // tampilkan batas samping kanan
}
