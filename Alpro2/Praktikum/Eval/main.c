/*
    Saya Franklin Impianro Turnip(2203211) mengerjakan evaluasi EVAL dalam mata kuliah Alpro II untuk keberkahanNya
    maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/
// PENGGUNAAN LIBRARY
#include "header.h"
int main() {
    // deklarasi variable
    Ticket ticket[1002];            // menyimpan data ticket
    TicketIndex ticketIndex[1002];  // menyimpan data indexing ticket
    char tape[102];                 // menyimpan string pita tiap masukan

    // meminta masukkan dan menjalankan perintah
    do {
        scanf(" %101[^\n]s", tape);             // meminta masukkan
        readQuery(tape, ticket, ticketIndex);   // jalankan perintah
    } while(isDBMSStop() == 0);                 // perikasa apakah dbms masih diperbolehkan berjalan
    
    return 0;
}