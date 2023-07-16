/*
    Saya Franklin Impianro Turnip(2203211) mengerjakan evaluasi TP5 dalam mata kuliah Alpro II untuk keberkahanNya
    maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/
// PENGGUNAAN LIBRARY
#include "header.h"

int main() {
    // DEKLARASI VARIABLE
    BanyakData banyakData; // menyimpan banyak data struct list barang, kategori, merk, toko, dan list barang final

    // menyimpan data-data struct maksimum 1000 data, termasuk batas data berupa tagar
    Barang barang[1000];
    SimpleData kategori[1000];
    SimpleData merk[1000];
    SimpleData toko[1000];
    BarangFinal barangFinal[1000];

    // flag
    int stop = 0; // 1 untuk keluar dari program, 0 untuk mengulang

    int opsiMenuUtama;
    // 1 untuk memasukkan data baru dari user
    // 2 untuk menampilkan list barang final
    // 3 untuk mencari data pada tabel
    // 4 untuk keluar dari program

    int opsiSubMenu;
    // untuk menu utama 1
    //  1 untuk mengaitkan dengan tabel list barang
    //  2 untuk mengaitkan dengan tabel kategori
    //  3 untuk mengaitkan dengan tabel merk
    //  4 untuk mengaitkan dengan tabel toko
    // untuk menu utama 3
    //  seperti menu utama 1, tetapi tidak ada tabel list barang

    char targetDicari[5];  // untuk menyimpan id yang akan dicari pada menu 3
    int posDicari; // untuk menyimpan posisi id yang telah ditemukan pada menu 3

    //  PENGOLAHAN DATA
    // menyimpan data yang ada pada file ke struct terkait
    // fungsi akan mengambilkan banyaknya record data yang tidak error
    banyakData.barang = bacaFileBarang("listBarang.dat", barang);
    banyakData.kategori = bacaFileSimpleData("Kategori.dat", kategori);
    banyakData.merk = bacaFileSimpleData("Merk.dat", merk);
    banyakData.toko = bacaFileSimpleData("Toko.dat", toko);
    banyakData.barangFinal = bacaFileBarangFinal("listBarangFinal.dat", barangFinal);

    // INTERAKSI DENGAN USER
    while(stop == 0) {
        system("clear"); // hapus konten pada layar agar tidak kotor

        // Tampilkan opsi menu utama
        printf("Menu :\n");
        printf("\t1. Masukkan data\n");
        printf("\t2. Tampilkan data\n");
        printf("\t3. Cari data\n");
        printf("\t4. Quit");

        // Pilih opsi untuk menu utama
        printf("\nOpsi : ");
        scanf("%d", &opsiMenuUtama);

        // Jalankan program berdasarkan menu yang dipilih
        switch(opsiMenuUtama) {
            case 1:
            system("clear"); // hapus konten pada layar agar tidak kotor

            // Taampilkan opsi submenu berupa tabel yang akan dikaitkan untuk dimasukkan record data baru
            printf("Tabel :\n");
            printf("\t1. List Barang\n");
            printf("\t2. Kategori\n");
            printf("\t3. Merk\n");
            printf("\t4. Toko\n");

            // Pilih tabel
            printf("\nOpsi: ");
            scanf("%d", &opsiSubMenu);

            // Masukkan record data baru berdasarkan tabel yang dipilih
            switch(opsiSubMenu) {
                case 1:
                system("clear");
                printf("TABEL LIST BARANG\n");
                banyakData.barang = scanBarang(banyakData.barang, "listBarang.dat", barang);
                break;
                case 2:
                system("clear");
                printf("TABEL KATEGORI\n");
                banyakData.kategori = scanSimpleData(banyakData.kategori, "Kategori.dat", kategori);
                break;
                case 3:
                system("clear");
                printf("TABEL MERK\n");
                banyakData.merk = scanSimpleData(banyakData.merk, "Merk.dat", merk);
                break;
                case 4:
                system("clear");
                printf("TABEL TOKO\n");
                banyakData.toko = scanSimpleData(banyakData.toko, "Toko.dat", toko);
                break;
            }

            jeda(); // tampilkan jeda program, dan untuk melanjutkan ketik karakter bebas
            break;
            case 2:
            system("clear"); // hapus konten pada layar agar tidak kotor

            // Periksa terlebih dahulu, apakah data pada list barang dengan finalnya sudah sinkron atau belum
            // Asumsinya data dianggap sinkron bila jumlahnya sama, tanpa memerhatikan kesamaan data
            // karena diasumsikan user hanya mengedit data melalui program ini
            if(banyakData.barang != banyakData.barangFinal) {
                // Tampilkan pemberitahuan terlebih dahulu untuk kenyamanan user
                printf("Harap Tunggu..\nSedang melakukan sinkronisasi data..\n");
                tunggu(0.2);

                // masukkan barang ke barangFinal dengan IDnya sudah diubah ke nama data terkait
                banyakData.barangFinal = finalisasiBarang(banyakData, barang, kategori, merk, toko, barangFinal);
                banyakData.barang = banyakData.barangFinal; // samakan jumlah list terbaru karena ada kemungkinan record data yang tidak masukkan

                // masukkan barangFinal yang tidak mengalami error ke filenya
                tulisFileBarangFinal(banyakData.barangFinal, "listBarangFinal.dat", barangFinal);

                system("clear"); // hapus konten pada layar agar tidak kotor
            }

            tampilkanData(banyakData.barangFinal, barangFinal); // tampilkan record list barang final menggunakan tabel

            jeda(); // tampilkan jeda program, dan untuk melanjutkan ketik karakter bebas
            break;
            case 3:
            system("clear"); // hapus konten pada layar agar tidak kotor

            // Tampilkan opsi tabel yang akan dikaitkan untuk dicari datanya
            printf("Tabel :\n");
            printf("\t1. Kategori\n");
            printf("\t2. Merk\n");
            printf("\t3. Toko\n");

            // Pilih tabel
            printf("\nOpsi: ");
            scanf("%d", &opsiSubMenu);

            // Masukkan id yang akan dicari pada tabel terkait
            printf("Cari ID(Batasan 4 karakter): ");
            scanf("%s", targetDicari);

            system("clear"); // hapus konten pada layar agar tidak kotor

            printf("%s ", targetDicari); // tampilkan id yang ingin dicari

            // tampilkan keterangan data tersebut
            switch(opsiSubMenu) {
                // cari terlebih dahulu posisi data tersebut
                // jika flagnya -1, artinya tidak ditemukan

                case 1:
                posDicari = binarySearch(0, banyakData.kategori, kategori, targetDicari);

                if(posDicari >= 0) {
                    printf("merupakan %s\n", kategori[posDicari].nama);
                } else {
                    printf("tidak ditemukan\n");
                }
                break;
                case 2:
                posDicari = binarySearch(0, banyakData.kategori, merk, targetDicari);

                if(posDicari >= 0) {
                    printf("merupakan %s\n", merk[posDicari].nama);
                } else {
                    printf("tidak ditemukan\n");
                }
                break;
                case 3:
                posDicari = binarySearch(0, banyakData.kategori, toko, targetDicari);

                if(posDicari >= 0) {
                    printf("merupakan %s\n", toko[posDicari].nama);
                } else {
                    printf("tidak ditemukan\n");
                }
                break;
            }

            jeda(); // tampilkan jeda program, dan untuk melanjutkan ketik karakter bebas
            break;
            case 4:
            stop = 1; // ganti flag dengan 1 agar keluar dari program dengan cara menghentikan looping
            system("clear"); // hapus konten pada layar agar tidak kotor
            break;
        }
    }

    return 0;
}