/*
    Saya Franklin Impianro Turnip(2203211) mengerjakan evaluasi TMD dalam mata kuliah Alpro II untuk keberkahanNya
    maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/
// LIBRARY
#include "dbms.h"

// MAIN
int main() {
    // deklarasi variable
    char tape[100];
    Customer customer[1000];
    Owe owe[1000];

    // baca semua data dari file untuk disimpan ke customer dan owe
    // nama file default dari dbms
    startDBMS(customer, owe);

    // jika mesin berhenti, program utama ikut berhenti
    while(didDBMSStop() == 0) {
        // tampilkan penanda bahwa query dapat dimasukkan
        printf("[FRANKLIN] > ");

        // input pita dari user
        scanf(" %99[^\n]s", tape); // hingga enter selanjutnya, hanya akan membaca 99 karater
        
        // kelola string
        readQuery(tape, customer, owe);
    }

    stopDBMS(customer, owe);
    return 0;
}