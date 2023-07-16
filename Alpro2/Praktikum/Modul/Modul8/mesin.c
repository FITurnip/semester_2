#include "header.h"
void insertionSort(int kiri, int kanan, SimpleData *sumber) {
    // DEKLARASI VARIABLE
    int i, j; // Iterator
    SimpleData temp; // tempat menampung sementara satu data dari sumber

    for(i = kiri; i <= kanan; i++) { // iterasi dari kiri hingga kanan
        temp = sumber[i]; // tampung data ke-i ke tempat sementara
        
        // mulai iterasi dari i - 1
        j = i - 1;
        while(j >= 0 && strcmp(temp.id, sumber[j].id) < 0) { // itearsi selama index masih dalam batasan atau masih terdapat susunan yang tidak terurut
            // geser data agar seolah-olah terjadi penyisipan
            sumber[j + 1] = sumber[j];
            j--;
        }

        // lakukan penyisipan
        sumber[j + 1] = temp;
    }
}

int bacaFileKeSimpleData(char *nama_file, SimpleData *dst) {
    int i = 0;
    FILE *file = fopen(nama_file, "r");

    while(fscanf(file, "%s %s", dst[i].id, dst[i].nama) != EOF) {
        insertionSort(0, i, dst);
        i++;
    }

    fclose(file);

    return i;
}

int bacaFileKeMahasiswa(char *nama_file, Mahasiswa *dst) {
    int i = 0;
    FILE *file = fopen(nama_file, "r");

    while(fscanf(file, "%s %s %s", dst[i].nama, dst[i].id_jurusan, dst[i].id_fakultas) != EOF) {
        i++;
    }

    fclose(file);

    return i;
}

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
        posisi = tengah; // masukan posisi tempat ditemukannya
    }

    return posisi;
}
