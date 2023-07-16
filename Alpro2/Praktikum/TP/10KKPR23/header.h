/*
    Saya Franklin Impianro Turnip(2203211) mengerjakan evaluasi TP dalam mata kuliah Alpro II untuk keberkahanNya
    maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/
// PENGGUNAAN LIBRARY
#include <stdio.h>
#include <string.h>

// struct
typedef struct {
    char string[102];
    int typeOfWord; // 1 kata terenkripsi, 2 kata kunci, 3 kata biasa
} Word;

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
 * SUBPROGRAM TAMBAHAN
 */
// bagian mengecek jenis kata
int isEncrypted(char *word, char codename);
void refreshTypeOfWord(Word *src, int *encryptedWordCount, int *commonWordCount);

// bagian kepengurutan
int comp(Word a, Word b);
void qsTengah(Word arr[], int left, int right);

// bagian menampilkan element
void printElement(Word word[], int idxStart, int endOfArray);