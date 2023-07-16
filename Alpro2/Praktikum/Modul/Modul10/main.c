#include "header.h"

int main() {
    // deklarasi variabel jumlah perintah dan pita
    int i, n, banyakDataValid = 0;
    char tape[128];
    student data[50];

    // meminta masukan
    printf("Masukkan jumlah perintah : ");
    scanf("%d", &n);

    // memulai perulangan untuk menjalankan setiap perintah
    for (i = 0; i < n; i++) {
        printf("[query] > ");
        scanf(" %127[^\n]s", tape); // ada spasi sebelum simbol %
      	modify_data(i + 1, tape, &banyakDataValid, data); // lengkapi mesinnya
        printf("\n");
    }


    printf("ISI DATA\n");
    for (i = 0; i < banyakDataValid; i++) {
        printf("%d. %s %s %s\n", (i + 1), data[i].nim, data[i].nama, data[i].nilai);
    }

    return 0;
}