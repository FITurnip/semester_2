/*
    Saya Franklin Impianro Turnip(2203211) mengerjakan evaluasi TP dalam mata kuliah Alpro II untuk keberkahanNya
    maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/
// PENGGUNAAN LIBRARY
#include "header.h"

int main() {
    /*
     * Deklarasi variable
     */
    // input
    char codename;
    char tape[102];

    // word
    Word word[102];
    int wordCount, encryptedWordCount = 0, keyWordCount = 0, commonWordCount = 0;

    // iterator
    int itr = 0;

    // flag
    int stopMachine = 0;

    /*
     * Input
     */
    // meminta input dari user
    scanf(" %c", &codename);
    scanf(" %101[^\n]s", tape);
    
    /*
     * Pengolahan data
     */
    // mulai mesin kata
    start(tape);

    // pengecekan kata pada pita terenkripsi atau tidak
    while(stopMachine == 0) {
        // simpan data kata yang dicek saat ini
        strcpy(word[itr].string, getcw());
        word[itr].typeOfWord = isEncrypted(word[itr].string,codename);

        // iterasi
        itr++;
        if(eop(tape) == 0) {
            inc(tape);
        } else {
            stopMachine = 1;
        }
    }

    // simpan banyaknya kata pada pita
    wordCount = itr;

    // kelompokkan kata terenkripsi, kunci, dan biasa

    // dipastikan bahwa kata pertama, dapat berupa terenkripsi atau biasa
    // cek terlebih dahulu
    refreshTypeOfWord(&word[0], &encryptedWordCount, &commonWordCount);

    // iterasi dari index 1 sampai wordcount - 1, untuk mengetahui kata yang memiliki 3 kemungkinan: enkripsi, kunci, & biasa
    itr = 1;
    while(itr + 1 < wordCount) {
        // jika bukan kata terenkripsi, maka mungkin kata kunci/biasa
        if(word[itr].typeOfWord == 0) {

            // jika diapit kata terenkripsi, maka berupa kata kunci
            if(word[itr - 1].typeOfWord == 1 && word[itr + 1].typeOfWord) {
                word[itr].typeOfWord = 2;

                keyWordCount++; // iterasi
            } else {
                // jika tidak, sebaliknya
                word[itr].typeOfWord = 3;

                commonWordCount++; // iterasi
            }
        } else {
            encryptedWordCount++; // iterasi
        }

        itr++; // iterasi
    }

    if(wordCount > 1) {
        // dipastikan bahwa kata pertama, dapat berupa terenkripsi atau biasa
        // cek terlebih dahulu
        refreshTypeOfWord(&word[itr], &encryptedWordCount, &commonWordCount);
    }

    qsTengah(word, 0, wordCount - 1);

    /*
     * Tampilkan output
     */
    // Bagian kata terenkripsi
    printf("KATA TERENKRIPSI\n");
    printElement(word, 0, encryptedWordCount);

    // Bagian kata kunci
    printf("\nKATA KUNCI\n");
    printElement(word, encryptedWordCount, encryptedWordCount + keyWordCount);

    // Bagian kata biasa
    printf("\nKATA BIASA\n");
    printElement(word, encryptedWordCount + keyWordCount, encryptedWordCount + keyWordCount + commonWordCount);

    return 0;
}