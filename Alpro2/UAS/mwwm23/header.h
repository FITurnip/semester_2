/*
    Saya Franklin Impianro Turnip(2203211) mengerjakan evaluasi UAS dalam mata kuliah Alpro II untuk keberkahanNya
    maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/
// PENGGUNAAN LIBRARY
#include <stdio.h>
#include <string.h>

/*
 * MESIN KATA
 */
// deklarasi variabel global
extern int idx;     // index dari karakter terakhir pada kata
extern int wlen;    // panjang kata (word length)
extern char cw[50]; // kata saat ini (current word)

// bagian untuk memulai, mereset, dan mengakhiri mesin kata
void start(char str[]);
void reset();
int eop(char str[]);

// bagian memajukan mesin kata
void inc(char str[]);

// bagian mendapatkan variabel global/atribut mesin kata
int getlen();
char *getcw();

/*
 * SUBPROGRAM LAIN
 */
// bagian muntuk menentukan kevalidan kata
int isValidWord(char *word, char target, int minTargetCount);