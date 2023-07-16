/*
    Saya Franklin Impianro Turnip(2203211) mengerjakan evaluasi EVAL dalam mata kuliah Alpro II untuk keberkahanNya
    maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/
// PENGGUNAAN LIBRARY
#include <stdio.h>
#include <string.h>

// struct
typedef struct {
    char no[102], desc[102], price[102];
    int state;

    int lenNo, lenDesc, lenPrice;
} Ticket;

typedef struct {
    char no[102];
    int pos;
} TicketIndex;

/*
 * MESIN KATA
 */
// deklarasi variabel global
extern int idx;     // index dari karakter terakhir pada kata
extern int wlen;    // panjang kata (word length)
extern char cw[102]; // kata saat ini (current word)

extern int DBMSisStop;
extern int ticketCount;

extern int colLen[3];

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
// bagian pengurutan dan pencarian
int compTicketIndex(TicketIndex a, TicketIndex b);
void qsort(TicketIndex arr[], int left, int right);
int binarySearch(int kiri, int kanan, TicketIndex arr[], TicketIndex target);

// bagian mendapat nilai panjang kolom terbesar
int max(int a, int b);
void getColLen(Ticket *ticket);

// bagian memasukkan data baru
void indexingTicket(Ticket *ticket, TicketIndex *ticketIndex);
void insertIntoTicket(char *tape, Ticket *ticket);

// bagian menghapus data
void deleteFromTicket(char *tape, Ticket *ticket, TicketIndex *ticketIndex);

// bagian menampilkan data
void loopingPrint(char c, int n);
void getList(Ticket *ticket);

// bagian pembacaan query
void readQuery(char *tape, Ticket *ticket, TicketIndex *ticketIndex);
int isDBMSStop();