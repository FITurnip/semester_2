/*
    Saya Franklin Impianro Turnip(2203211) mengerjakan evaluasi EVAL dalam mata kuliah Alpro II untuk keberkahanNya
    maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/
// PENGGUNAAN LIBRARY
#include "header.h"

// Deklarasi variable
int idx;                    // index pita
int wlen;                   // panjanag kata yang ditunjuk pada pita
char cw[102];               // kata yang sedang ditunjuk

int ticketCount = 0;        // jumlah tiket saat ini
int DBMSisStop = 0;         // kondisi/flag keadaan DBMS

int colLen[3] = {8, 9, 5};  // panjang ketiga kolom pada tabel

// Prosedur untuk memulai mesin kata
void start(char str[]) {
    // inisialisasi index dan panjang kata
    idx = 0;
    wlen = 0;

    // jika karakter dalam index adalah spasi, maka index terus maju
    while (str[idx] == ' ') {
        idx++;
    }
    // jika masukan berupa karakter selain spasi dan EOP, kata diatur ke variabel global
    while ((str[idx] != ' ') && (eop(str) == 0)) {
        cw[wlen] = str[idx];
        wlen++;
        idx++;
    }
    // mengatur agar kata saat ini index terakhirnya menjadi NULL
    cw[wlen] = '\0';
}

// Prosedur untuk mengosongkan kata yang dibaca dalam mesin kata
void reset() {
    // inisialisasi panjang kata dan kata saat ini agar NULL
    wlen = 0;
    cw[wlen] = '\0';
}

// Fungsi untuk memeriksa akhir dari proses
int eop(char str[]) {
    // Memeriksa apakah karakter saat ini merupakan simbol akhir pita
    if (str[idx] == '!') {
        return 1;
    } else {
        return 0;
    }
}

// Prosedur untuk memajukan kata
void inc(char str[]) {
    // inisialisasi ulang panjang kata
    wlen = 0;

    // jika karakter dalam pita adalah spasi, maka index terus maju
    while (str[idx] == ' ') {
        idx++;
    }

    // jika masukan berupa karakter selain spasi dan EOP, kata diatur ke variabel global
    while ((str[idx] != ' ') && (eop(str) == 0)) {
        cw[wlen] = str[idx];
        wlen++;
        idx++;
    }
    
    // mengatur agar kata saat ini index terakhirnya menjadi NULL
    cw[wlen] = '\0';
}

// Fungsi untuk mendapatkan panjang kata saat ini
int getlen() {
    return wlen;
}

// Fungsi untuk mendapatkan kata saat ini
char *getcw() {
    return cw;
}

// Fungsi untuk mengetahui posisi mana yang lebih dahulu, a atau b
int compTicketIndex(TicketIndex a, TicketIndex b) {
    int compVal = strcmp(a.no, b.no);

    if(compVal < 0) {
        return -1;
    } else if(compVal == 0){
        return 0;
    }

    return 1;
}

// Fungsi untuk mendapatkan nilai yang lebih besar antara adan b
int max(int a, int b) {
    if(a > b) {
        return a;
    }
    return b;
}

// Prosedur untuk mengurutkan kata dari indeks kiri sampai kanan
void qsort(TicketIndex arr[], int left, int right) {
    // deklarasi
    int i, j;           // iterator
    TicketIndex temp, pivot;   // penyimpanan sementara dan acuan

    // mulai iterasi
    i = left, j = right;
    pivot = arr[(right + left) / 2]; // menyimpan data yang ada di tengah arr
    do {
        while (compTicketIndex(arr[i], pivot) < 0 && (i <= j)) { // data sebelah kiri lebih kecil daripada pivot
            i++;
        }

        while (compTicketIndex(pivot, arr[j]) < 0 && (i <= j)) { // data sebelah kanan lebih besar daripada pivot
        
            j--;
        }
        
        // jika masih iterator kiri dan kanan belum bertemu,
        // tukar, iterasi, dan lanjutkan looping
        if (i < j) {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    } while (i < j);
    
    // jika selebah kanan pivot sudah diurutkan, urutkan sebelah kiri pivot
    if (left < j && j < right) {
        qsort(arr, left, j);
    }

    // jika selebah kiri pivot sudah diurutkan, urutkan sebelah kanan pivot
    if (i < right && i > left) {
        qsort(arr, i, right);
    }
}

// Prosedur untuk mendapatkan panjang maksimum dari kolom sebelumnya dengan panjang string record terbaru
void getColLen(Ticket *ticket) {
    // isikan terlebih dahulu panjang string record baru
    ticket->lenNo = strlen(ticket->no);
    ticket->lenDesc = strlen(ticket->desc);
    ticket->lenPrice = strlen(ticket->price);

    // perbarui panjang kolom dengan membandingkannya dengan panjang kolom saat ini
    colLen[0] = max(ticket->lenNo, colLen[0]);
    colLen[1] = max(ticket->lenDesc, colLen[1]);
    colLen[2] = max(ticket->lenPrice + 2, colLen[2]);
}

// Prosedur untuk melakukan pengindexan terhadap kolom nomor pada ticket
void indexingTicket(Ticket *ticket, TicketIndex *ticketIndex) {
    strcpy(ticketIndex->no, ticket->no);
    ticketIndex->pos = ticketCount;
}

// Prosedur untuk mencari data
int binarySearch(int kiri, int kanan, TicketIndex arr[], TicketIndex target) {
    // DEKLARASI VARIABLE
    int tengah; // menyimpan nilai tengah index yang dilakukan pencarian
    int ditemukan = 0;// flag ditemukan(1) atau belumnya(0) posisi dari nilai data  yang sama dengan target
    int posisi = -1; // flag yang menyatakan posisi target pada arr, sehingga -1 diasumsikan sebagai ketidakmasukakalan atau ketidakadaan target pada arr
    int komp; // flag komparasi 2 data

    while(ditemukan == 0 && kiri <= kanan) { // itetasi hingga ditemukan atau index kiri melebihi index kanan
        tengah = (kiri + kanan) / 2; // menghitung nilai tengah
        
        komp = compTicketIndex(arr[tengah], target); // membandingkan nilai yang di tengah dengan target
        if(komp != 0) { // apabila tidak sama
            if(komp > 0) { // apabila angkanya lebih besar, geser index kanan ke tengah - 1 karena diasumsikan data berada di sebelah kiri index tengah
                kanan = tengah - 1;
            } else { // apabila angkanya lebih kecil, geser index kiri ke tengah + 1 karena diasumsikan data berada di sebelah kanan index tengah
                kiri = tengah + 1;
            }
        } else { // apabila sama
            ditemukan = 1; // hentikan iterasi
        }
    }

    if(ditemukan != 0) { // apabila ditemukan
        posisi = tengah; // masukan posisi tempat ditemukannya
    }

    return posisi;
}

// Prosedur untuk memasukkan data pita ke ticket
void insertIntoTicket(char *tape, Ticket *ticket) {
    inc(tape);
    strcpy(ticket->no, getcw());
    inc(tape);
    strcpy(ticket->desc, getcw());
    inc(tape);
    strcpy(ticket->price, getcw());

    // isikan nilai default state
    ticket->state = 1; // bermakna data dalam keadaan belom dihapus
}

// Prosedur untuk enghapus data secara semu dari ticket
void deleteFromTicket(char *tape, Ticket *ticket, TicketIndex *ticketIndex) {
    // deklarasi variable
    TicketIndex temp; // penyimpanan sementara untuk menampung target

    inc(tape);
    strcpy(temp.no, getcw()); // tampung target

    int pos = binarySearch(0, ticketCount - 1, ticketIndex, temp); // cari posisi target pada table target index

    if(pos != -1) {
        ticket[ticketIndex[pos].pos].state = 0; // ubah state menjadi nol pada posisi yang didapat dari table ticketindex
    }
}

// Prosedur untuk menampilkan c sebanyak n
void loopingPrint(char c, int n) {
    for(int i = 0; i < n; i++) {
        printf("%c", c);
    }
}

// prosedur untuk menampilkan list tiket yang tidak/belum dijual
void getList(Ticket *ticket) {
    // deklarasi variable
    int totalLen = colLen[0] + colLen[1] + colLen[2] + 10; // lebar pembatas horizontal

    // table header
    loopingPrint('~', totalLen);
    printf("\n");

    printf("! ID Tiket");
    loopingPrint(' ', colLen[0] - 7);
    
    printf("! Deskripsi");
    loopingPrint(' ', colLen[1] - 8);
    
    printf("! Harga");
    loopingPrint(' ', colLen[2] - 4);

    printf("!\n");

    loopingPrint('~', totalLen);
    printf("\n");

    // table body
    for(int i = 0; i < ticketCount; i++) {
        if(ticket[i].state == 1) {
            printf("! %s", ticket[i].no);
            loopingPrint(' ', colLen[0] - ticket[i].lenNo + 1);

            printf("! %s", ticket[i].desc);
            loopingPrint(' ', colLen[1] - ticket[i].lenDesc + 1);

            printf("! Rp%s", ticket[i].price);
            loopingPrint(' ', colLen[2] - (ticket[i].lenPrice + 2) + 1);

            printf("!\n");
        }
    }

    // border
    loopingPrint('~', totalLen);
    printf("\n");

}

// Prosedur untuk membaca query dari pita dan mengekeskusi sesuai dengan perintah
void readQuery(char *tape, Ticket *ticket, TicketIndex *ticketIndex) {
    start(tape);    // mulai mesin kata

    char *substring = getcw(); // simpan kata yang ditunjuk

    // Periksa perintah mana yang sesuai
    if(strcmp(substring, "LIST") == 0) {
        getList(ticket);    // tampilkan data ticket
    } else if(strcmp(substring, "STOP") == 0) {
        DBMSisStop = 1;     // DBMS dibuat dalam kondisi tidak dapat beroperasi lagi dengan cara mengubah flag menjadi 1
    } else if(strcmp(substring, "BELI") == 0) {
        // masukkan data baru
        insertIntoTicket(tape, &ticket[ticketCount]);

        // lakukan indexing
        indexingTicket(&ticket[ticketCount], &ticketIndex[ticketCount]);
        qsort(ticketIndex, 0, ticketCount);

        // perbarui lebar kolom pada tabel karena ada data baru yang masuk
        getColLen(&ticket[ticketCount]);

        // iterasi karena ada data baru yang masuk
        ticketCount++;

    } else if(strcmp(substring, "JUAL") == 0) {
        deleteFromTicket(tape, ticket, ticketIndex);    // hapus ticket 
    }
}

// Fungsi untuk mengetahui apakah DBMS telah dihentikan operasinya
int isDBMSStop() {
    return DBMSisStop;
}