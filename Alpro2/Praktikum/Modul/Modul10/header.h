#include <stdio.h>

#define f(variabel, batasBawah, batasAtas) for(int i = batasBawah; i <= batasAtas; i++)

// deklarasi tipe bungkusan mahasiswa
typedef struct {
    char nim[20], nama[50], nilai[10];
} student;

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
 * MESIN QUERY
 */

void modify_data(int urutanPerintah, char str[], int *banyakData, student data[]);