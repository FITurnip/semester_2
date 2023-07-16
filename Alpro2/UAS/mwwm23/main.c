/*
    Saya Franklin Impianro Turnip(2203211) mengerjakan evaluasi UAS dalam mata kuliah Alpro II untuk keberkahanNya
    maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/
// PENGGUNAAN LIBRARY
#include "header.h"
int main() {
    /* DEKLARASI VARIABLE */
    // input
    char tape[502];         // pita
    char target;            // target yang akan dicari pada kata yang ada di pita
    int minTargetCount;     // banyaknya minimal ditemukannya target yang diperlukan agar kata disebut valid

    // machine
    int validTargetCount;   // banyaknya kata yang valid
    int isStop;             // flag keadaan iterasi, stop(1), berjalan(0)

    /* MEMMINTA INPUT DARI USER */
    scanf(" %501[^\n]s", tape);     // pita
    scanf(" %c", &target);          // target
    scanf(" %d", &minTargetCount);  // banyaknya minimal target pada satu kata

    /* PENGOLAHAN DATA */
    // mulai machine
    start(tape);

    // nilai awal
    validTargetCount = 0;   // belum ditemukan kata valid
    isStop = 0;      // tandakan bahwa machine belum berhenti

    // iterasi semua kata pada pita
    while(isStop == 0) {
        if(isValidWord(getcw(), target, minTargetCount) == 1) { // tentukan kevalidan kata
            validTargetCount++; // tambahkan banyak kata valid, jika benar
        }

        if(eop(tape) == 0) {    // tentukan apakah machine telah berhenti-telah mencapai ujung pita-
            inc(tape);          // jika belum, tunjuk kata berikutnya
        } else {
            isStop = 1;  // hentikan iterasi
        }
    }

    /* MENAMPILKAN OUTPUT */
    // tampilkan jumlah kata valid
    printf("%d\n", validTargetCount);

    return 0;
}