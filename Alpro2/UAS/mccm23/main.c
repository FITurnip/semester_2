/*
    Saya Franklin Impianro Turnip(2203211) mengerjakan evaluasi UAS dalam mata kuliah Alpro II untuk keberkahanNya
    maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/
// Penggunaan Libary
#include "header.h"
int main() {
    /* Deklarasi Variable */
    // input
    char tape[501];     // pita
    char letterClamp;   // huruf pengapit

    // penyimpan banyak kevalidan
    int validLetterCount, validSyllableCount; // huruf valid, suku kata valid

    // flag
    int isStop;  // keadaan iterasi, stop(1), berjalan(0)

    /* Meminta Input Dari User */
    scanf(" %501[^\n]s", tape); // pita
    scanf(" %c", &letterClamp); // huruf pengapit

    /* Pengolahan Data */
    // mulai machine
    START(tape);
    
    // nilai awal
    validLetterCount = 0;   // belum ditemukan huruf valid
    validSyllableCount = 0; // belum ditemukan suku kata valid
    isStop = 0;             // mesin sedang berjalan

    // iterasi hingga semua kata telah diperiksa
    while(isStop == 0) {
        // tentukan terlebih dahulu banyak huruf yang valid saat ini
        switch(validLetterCount) {
            case 0:
            // jika 0 dan huruf yang ditunjuk berupa letterClamp, inc huruf valid
            if(GETCC() == letterClamp) {
                validLetterCount++;
            }
            break;

            case 1:
            // jika 1 dan huruf yang ditunjuk bukan berupa letterClamp, inc huruf valid
            if(GETCC() != letterClamp) {
                validLetterCount++;
            }

            // jika 1 dan huruf yang ditunjuk berupa letterClamp, banyak huruf valid dianggap kembali ke 1
            break;

            case 2:
            // jika 2 dan huruf yang ditunjuk berupa letterClamp, inc suku kata valid dan ulang huruf valid
            // jika 2 dan bukan berupa lettercamp, huruf masih dalam keadaan titik kritis kevalidan
            if(GETCC() == letterClamp) {
                validSyllableCount++;

                validLetterCount = 0;
            } else {
                validLetterCount++;
            }
            break;

            case 3:
            // jika sudah 3 dan huruf yang ditunjuk valid, inc suku kata valid
            if(GETCC() == letterClamp) {
                validSyllableCount++;
            }

            // terlepas dari kevalidan, pemeriksaan kevalidan huruf perlu diulang dari 0
            validLetterCount = 0;
            break;
        }

        // periksa apakah mesin menemui ujung pita atau tidak
        if(EOP(tape) == 0) {
            // jika tidak, inc karakter hingga ditemukan huruf
            INC(tape);

            if(GETCC() == ' ') {
                validLetterCount = 0;
                ADV(tape);
            }
        } else {
            // jika iya, maka semua kata telah diperiksa dan iterasi perlu dihentikan
            isStop = 1;
        }
    }

    /* Menampilkan Output ke User */
    // tampilkan jumlah suku kata yang valid
    printf("%d\n", validSyllableCount);
    return 0;
}