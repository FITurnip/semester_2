#include "header.h"
int main() {
    int i, j;
    int n;
    scanf("%d", &n);

    Mahasiswa mhs[n], dicari, temp;

    for(i = 0; i < n; i++) {
        scanf(" %s", mhs[i].nim);
        scanf(" %s", mhs[i].nama);
        scanf(" %s", mhs[i].kelas);

        j = i - 1;
        temp = mhs[i];
        while(j >= 0 && strcmp(temp.nim, mhs[j].nim) < 0) {
            mhs[j + 1] = mhs[j];
            j--;
        }
        mhs[j + 1] = temp;
    }

    scanf(" %s", dicari.nim);

    // for(int i = 0; i < n; i++) {
    //     printf("%s\n", mhs[i].nim);
    // }

    int posisi = binarySearch(n, mhs, dicari.nim);
    if(posisi == -1) {
        printf("Tidak ditemukan\n");
    } else {
        dicari = mhs[posisi];
        printf("%s\n", dicari.nim);
        printf("%s\n", dicari.nama);
        printf("%s\n", dicari.kelas);
    }
    return 0;
}