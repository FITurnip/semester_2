/*
    Saya Franklin Impianro Turnip(2203211) mengerjakan evaluasi TMD dalam mata kuliah Alpro II untuk keberkahanNya
    maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/
// LIBRARY
#include <stdio.h>
#include <stdlib.h>

// MAKRO
// defisinikan CLS sesuai os
#ifdef __unix__ // Linux
    #define CLS "clear"
#else           // Windows
    #define CLS "cls"
#endif

// VARIABLE
/*
 * MESIN KATA
 */
// deklarasi variabel global
extern int idx;      // index dari karakter terakhir pada kata
extern int wlen;     // panjang kata (word length)
extern char cw[100]; // kata saat ini (current word)

/*
 * DBMS
 */
// table
extern int existTemp;
extern int customerCounter, oweCounter;
extern int typeOfTable;

// keberjalanan DBMS
extern int typeOfError;
extern int DBMSStopped;
extern int posTarget;

// query
extern char query[6][8];
extern int typeOfquery;

// STRUCT
typedef struct {
    // data yang akan diinput user
    char id[20], name[20];

    // flag exist data
    int existState;
} Customer;

typedef struct {
    // data yang akan diinput user
    char id[20], customerId[20];
    int totalOwe;

    // flag exist data
    int existState;
} Owe;

typedef struct {
    // data-data yang menjadi ciri hubungan kedua tabel
    char customerId[20], oweId[20];
    int customerPos, owePos;
} ForeignKey;

// PROCEDURE & FUNGSI
/*
 * MESIN KATA
 */
// bagian untuk memulai, mereset, dan mengakhiri mesin kata
void startWordMachine(char str[]);
void resetWordMachine();
int eopWordMachine(char str[]);

// bagian memajukan mesin kata
void inc(char str[]);

// bagian mendapatkan variabel global/atribut mesin kata
int getlen();
char *getcw();

/*
 * MANIPULASI FILE
 */
// pembaca data dari file
void readCustomerFromFile(Customer source[], char filename[]);
void readOweFromFile(Owe source[], char filename[]);

// penulis data ke file
void writeCustomerToFile(Customer source[], char filename[]);
void writeOweToFile(Owe source[], char filename[]);

/*
 * DBMS
 */
// manipulasi jendela dan layar
void clearscreen();

// mulai dan tutup dbms
void startDBMS(Customer *customer, Owe *owe);
void stopDBMS(Customer *customer, Owe *owe);
int didDBMSStop();

// perbadingan dan pencarian
int compareString(char *p, char *q);
int searchByForeignKey(int lowerBoundIndex, int upperBoundIndex, char *target);
int sequentialSearch(int lowerBoundIndex, Customer *customer, Owe *owe, int typeOfTable, char *target);
int getTypeOfTable(char *table);

// konversi
int isDigit(int number);
int stoi(char *str);
void itos(int src, char *dst);

// handle Error
void handleError();

// penempelan data
void makeTempRecord(char *tape);
void insertEditRecord(Customer *customer, Owe *owe, int typeOfTable);
void insertEditForeignKey(int foreignKeyPos, int customerPos, int owePos);
void makeRelation(Customer *customer, Owe *owe);

// crud
void insertIntoTable(Customer *customer, Owe *owe, char *tape);
void editFromTable(Customer *customer, Owe *owe, char *tape);
void deleteFromTable(Customer *customer, Owe *owe, char *tape);

// menampilkan isi table
void repeatPrint(char c, int sum);
void printAColumn(char *content, int width);
void showTable(Customer *customer, Owe *owe, char *tape);

// pembaca query
void readQuery(char *tape, Customer *customer, Owe *owe);
