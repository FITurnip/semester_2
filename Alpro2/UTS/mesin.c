/*
    Saya Franklin Impianro Turnip(2203211) mengerjakan evaluasi UTS dalam mata kuliah Alpro II untuk keberkahanNya
    maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/
// PENGGUNAAN LIBRARY
#include "header.h"
void hitungKemurniaanEmas(Emas *src) {
    // kandungan emas murni dihitung dari pengurangan berat emas dengan seluruh berat lainnya
    (*src).berat.emas -= (*src).berat.campuran;
    (*src).berat.emas -= (*src).berat.katalis;
    (*src).berat.emas -= (*src).berat.lainnya;
}

void scanElement(int n, Emas *emas) {
    for(int i = 0; i < n; i++) {
        scanf(" %s", emas[i].kodeNama); // input kode nama ke-i
        scanf(" %d", &emas[i].berat.emas); // input berat emas nama ke-i
        scanf(" %d", &emas[i].berat.campuran); // input berat campuran nama ke-i
        scanf(" %d", &emas[i].berat.katalis); // input berat katalis nama ke-i
        scanf(" %d", &emas[i].berat.lainnya); // input berat lainnya ke-i

        hitungKemurniaanEmas(&emas[i]);
    }
}

int komparasi(int p, int q) {
    int flag; // flag 0 berarti q lebih besar dan sebaliknya
    if(p > q) { // cek kondisi mana yg lebih besar dan isi nilai flag
        flag = 1;
    } else {
        flag = 0;
    }
    return flag; // kembalikan nilai flag
}

void merge(Emas arr1[], int n1, Emas arr2[], int n2, Emas arr3[]) {
    // DEKLARASI VARIABLE
    int i1 = 0, i2 = 0, i3 = 0;

    // ulangi hingga arr1 habis atau arr2 habis
    while ((i1 < n1) && (i2 < n2)) {
        // jika elemen teratas arr1 lebih kecil dari arr2
        if (komparasi(arr1[i1].berat.emas, arr2[i2].berat.emas) == 1) {
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

void tukar(Emas *p, Emas *q) {
    Emas temp = (*p);
    (*p) = (*q);
    (*q) = temp;
}

void quicksort(Emas arr[], int kiri, int kanan) {
    // DEKLARASI VARIABLE
    int i, j; // iterator
    Emas pivot; // menyimpan data acuan(pivot)

    i = kiri, j = kanan; // iterasi i mengacu pada kiri dan j pada kanan
    pivot = arr[(kanan + kiri) / 2]; // pilih pivot berupa data di tengah

    do {
        while (komparasi(arr[i].berat.emas, pivot.berat.emas) == 1 && (i <= j)) { // cari data yang lebih kecil daripada pivot dari kiri array
            i++;
        }

        while (komparasi(pivot.berat.emas, arr[j].berat.emas) == 1 && (i <= j)) { // cari data yang lebih besar daripada pivot dari kanan array
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
        quicksort(arr, kiri, j);
    }
    if (i < kanan && i > kiri) { // jika iterator i masih dalam batasan array yang diiterasikan, maka urutkan lagi dari indeks ke-i sampai ke-kanan
        quicksort(arr, i, kanan);
    }
}

void insertionSort(int n, Emas *arr) {
    // Deklarasi Variable
    int i, j; // Iterator
    Emas temp; // Penampungan sementara Emas

    // Urutkan dengan algoritma insertion sort
    for (i = 1; i < n; i++) {
        j = i - 1;
        temp = arr[i];
        while (j > 0 && komparasi(temp.berat.emas, arr[j].berat.emas) == 1) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

void selectionSort(int n, Emas arr[n]) {
    // Deklarasi Variable
    int i, j; // Iterator
    int idxMin; // Menampung nilai index minimum

    // Urutkan dengan algoritma insertion sort
    for(i = 0; i < n - 1; i++) {
        idxMin = i;
        for(j = i + 1; j < n; j++) {
            if(komparasi(arr[j].berat.emas, arr[idxMin].berat.emas) == 0) {
                idxMin = j;
            }
        }
        
        tukar(&arr[i], &arr[idxMin]);
    }
}

void bubbleSort(int n, Emas arr[n]) {
    // DEKLARASI VARIABLE
    int i, j; // Iterator
    int swap; // flag terjadi pertukaran(1) atau tidak(0)

    do {
        swap = 0; // Dianggap tidak terjadi pertukaran karena belum terjadi
        for (i = 0; i < n - 1; i++) { // looping terhadap n - 1 data sihir karena akan mengecek i + 1 pada tiap sub kasus
            if (komparasi(arr[i].berat.emas, arr[i + 1].berat.emas) == 1) { // komparasi sihir i dan i + 1, apakah perlu diurutkan atau tidak
                // jika perlu diurutkan, tukar kedua data yang ditunjuk
                tukar(&arr[i], &arr[i + 1]);

                // tanda bahwa ada data yang ditukar
                swap = 1;
            }
        }
    } while (swap  == 1); // looping selama terjadi pertukaran
}