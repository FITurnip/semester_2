/*
    Saya Franklin Impianro Turnip(2203211) mengerjakan evaluasi UTS dalam mata kuliah Alpro II untuk keberkahanNya
    maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/
// PENGGUNAAN LIBRARY
#include "header.h"
int main() {
    // Deklarasi Variable
    char metodeSorting[10]; // menyimpan nama metode yang dipakai
    int n1, n2, n3, nFinal; // menyimpan jumlah tiap-tiap array

    // MEMINTA INPUT DARI USER
    scanf(" %s", metodeSorting); // scan metode sorting yang akan dipakai

    scanf(" %d", &n1); // scan jumlah kumpulan emas ke-1
    Emas emas1[n1]; // deklarasi array emas ke-1
    scanElement(n1, emas1); // scan semua emas ke-1
    
    scanf("%d", &n2); // scan jumlah kumpulan emas ke-1
    Emas emas2[n2]; // deklarasi array emas ke-1
    scanElement(n2, emas2); // scan semua emas ke-1
    
    scanf("%d", &n3); // scan jumlah kumpulan emas ke-1
    Emas emas3[n3]; // deklarasi array emas ke-1
    scanElement(n3, emas3); // scan semua emas ke-1

    // MENGOLAH DATA

        // for(int i = 0; i < n1; i++) {
        //     printf("%d\n", emas1[i].berat.emas);
        // }
    switch(metodeSorting[0]) { // pilih metode sorting yang digunakan
        case 'q': // gunakan quicksort terhadap semua array emas
        quicksort(emas1, 0, n1 - 1);
        quicksort(emas2, 0, n2 - 1);
        quicksort(emas3, 0, n3 - 1);
        break;
        case 'i': // gunakan insertion sort terhadap semua array emas
        insertionSort(n1, emas1);
        insertionSort(n2, emas3);
        insertionSort(n3, emas3);
        break;
        case 's': // gunakan selecetion sort terhadap semua array emas
        selectionSort(n1, emas1);
        selectionSort(n2, emas3);
        selectionSort(n3, emas3);
        break;
        case 'b': // gunakan bubble sort terhadap semua array emas
        bubbleSort(n1, emas1);
        bubbleSort(n2, emas3);
        bubbleSort(n3, emas3);
        break;
    }

        // for(int i = 0; i < n1; i++) {
        //     printf("%d\n", emas1[i].berat.emas);
        // }

    nFinal = n1 + n2 + n3; // jumlah semua data array yang diinput
    Emas temp[n1 + n2], final[nFinal]; // deklarasi temp untuk menampung emas1 & emas 2 dan final untuk keseluruhan

    // gabung terurut
    merge(emas1, n1, emas2, n2, temp); // gabungkan emas1 & emas2
    merge(temp, n1 + n2, emas3, n3, final); // gabungan semua

    Berat totalBerat = {0, 0, 0, 0}; // Deklarasi total berat yang awalnya semua bernilai 0

    for(int i = 0; i < nFinal; i++) { // iterasi semua data emas dan jumlah beratnya ke totalBerat
        totalBerat.emas += final[i].berat.emas;
        totalBerat.campuran += final[i].berat.campuran;
        totalBerat.katalis += final[i].berat.katalis;
        totalBerat.lainnya += final[i].berat.lainnya;
    }

    // TAMPILKAN DATA YANG TELAH DIOLAH
    printf("emas batangan:\n"); // tampilkan headernya
    for(int i = 0; i < nFinal; i++) { // iterasi semua data emas
        printf("%s ", final[i].kodeNama); // tampilkan kode nama emas ke-i

        // tampilkan berat campuran, katalis, dan lainnya dengan urutan besar, kecil, tengah
        if(final[i].berat.campuran > final[i].berat.katalis && final[i].berat.campuran > final[i].berat.lainnya) {
            printf("campuran-%d ", final[i].berat.campuran);
            if(final[i].berat.katalis < final[i].berat.lainnya) {
                printf("katalis-%d ", final[i].berat.katalis);
                printf("lainnya-%d ", final[i].berat.lainnya);
            } else {
                printf("lainnya-%d ", final[i].berat.lainnya);
                printf("katalis-%d ", final[i].berat.katalis);
            }
        } else if(final[i].berat.katalis > final[i].berat.campuran && final[i].berat.katalis > final[i].berat.lainnya) {
            printf("katalis-%d ", final[i].berat.katalis);
            if(final[i].berat.campuran < final[i].berat.lainnya) {
                printf("campuran-%d ", final[i].berat.campuran);
                printf("lainnya-%d ", final[i].berat.lainnya);
            } else {
                printf("lainnya-%d ", final[i].berat.lainnya);
                printf("campuran-%d ", final[i].berat.campuran);
            }
        } else {
            printf("lainnya-%d ", final[i].berat.lainnya);
            if(final[i].berat.campuran < final[i].berat.katalis) {
                printf("campuran-%d ", final[i].berat.campuran);
                printf("katalis-%d ", final[i].berat.katalis);
            } else {
                printf("campuran-%d ", final[i].berat.campuran);
                printf("katalis-%d ", final[i].berat.katalis);
            }
        }
        printf("emas=%d", final[i].berat.emas); // tampilkan berat emas murni

        if(final[i].berat.emas < 0) { // jika negaitif maka blacklist
            printf(" -blacklist");
        }
        printf("\n"); // tampilkan baris baru
    }

    // tampilkan berat total yang telah diolah tadi
    printf("jumlah berat total emas: %d\n", totalBerat.emas);
    printf("jumlah berat total campuran: %d\n", totalBerat.campuran);
    printf("jumlah berat total katalis: %d\n", totalBerat.katalis);
    printf("jumlah berat total lainnya: %d\n", totalBerat.lainnya);

    return 0;
}