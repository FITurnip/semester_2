/*
    Saya Franklin Impianro Turnip(2203211) mengerjakan evaluasi TMD dalam mata kuliah Alpro II untuk keberkahanNya
    maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/
// LIBRARY
#include "dbms.h"
#include <string.h>

// MAKRO
#define REP(itr, lwrBound, uprBound) for(int itr = lwrBound, limit = uprBound; itr <= limit; itr++)

// VARIABLE
/*
 * MESIN KATA
 */
int idx;
int wlen;
char cw[100];

/*
 * DBMS
 */
// Keperluan Table
Customer customerTemp;
Owe oweTemp;
ForeignKey foreignKey[1000];
int existTemp;
int customerCounter = 0, oweCounter = 0;
int typeOfTable;

// Keperluan Keberjalanan Mesin DBMS
int typeOfError;
int DBMSStopped = 0;
int posTarget;

// Keperluan Query
char query[6][8] = {"INSERT\0", "EDIT\0", "DELETE\0", "SHOW\0", "jangan\0"};
int typeOfquery;

/*
 * MESIN KATA
 */
// Prosedur untuk memulai mesin kata
void startWordMachine(char str[]) {
    // inisialisasi index dan panjang kata
    idx = 0;
    wlen = 0;

    // jika karakter dalam index adalah spasi, maka index terus maju
    while (str[idx] == ' ') {
        idx++;
    }
    // jika masukan berupa karakter selain spasi dan EOP, kata diatur ke variabel global
    while ((str[idx] != ' ') && (eopWordMachine(str) == 0)) {
        cw[wlen] = str[idx];
        wlen++;
        idx++;
    }
    // mengatur agar kata saat ini index terakhirnya menjadi NULL
    cw[wlen] = '\0';
}

// Prosedur untuk mengosongkan kata yang dibaca dalam mesin kata
void resetWordMachine() {
    // inisialisasi panjang kata dan kata saat ini agar NULL
    wlen = 0;
    cw[wlen] = '\0';
}

// Fungsi untuk memeriksa akhir dari proses
int eopWordMachine(char str[]) {
    // Memeriksa apakah karakter saat ini merupakan simbol akhir pita
    if (str[idx] == ';') {
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
    while ((str[idx] != ' ') && (eopWordMachine(str) == 0)) {
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

/*
 * MANIPULASI FILE
 */
// membaca data customer dari file
void readCustomerFromFile(Customer source[], char filename[]) {
    // deklarasi variable
    FILE *fTemp = fopen(filename, "r"); // buka file dengan mode read
    int stop = 0;                       // flag keberlangsungan pembacaan
    int returnVal;                      // flag keberakhiran data dari file

    do{
        // baca data hingga data berakhir
        returnVal = fscanf(fTemp, " %s %s",
                                    source[customerCounter].id,
                                    source[customerCounter].name);
        source[customerCounter].existState = 1;
        if(returnVal != EOF) {
            customerCounter++;
        } else {
            stop = 1;
        }
    } while (stop == 0);

    

    // "tutup file"
    fclose(fTemp);
}

// membaca data owe dari file
void readOweFromFile(Owe source[], char filename[]) {
    // deklarasi variable
    FILE *fTemp = fopen(filename, "r"); // buka file dengan mode read
    int stop = 0;                       // flag keberlangsungan pembacaan
    int returnVal;                      // flag keberakhiran data dari file

    do{
        // baca data hingga data berakhir
        returnVal = fscanf(fTemp, " %s %s %d",
                                    source[oweCounter].id,
                                    source[oweCounter].customerId,
                                    &source[oweCounter].totalOwe);

        source[oweCounter].existState = 1;
        if(returnVal != EOF) {
            oweCounter++;
        } else {
            stop = 1;
        }
    } while (stop == 0);

    // "tutup file"
    fclose(fTemp);
}

// menulis data customer ke file
void writeCustomerToFile(Customer source[], char filename[]) {
    FILE *fTemp = fopen(filename, "w"); // buka file dengan mode write

    // tulis data yang exist ke file
    REP(i, 0, customerCounter - 1) {
        if(source[i].existState == 1) {
            fprintf(fTemp, "%s %s\n",
                            source[i].id,
                            source[i].name);
        }
    }

    // "tutup file"
    fclose(fTemp);
}

// menulis data owe ke file
void writeOweToFile(Owe source[], char filename[]) {
    FILE *fTemp = fopen(filename, "w"); // buka file dengan mode write

    // tulis data yang exist ke file
    REP(i, 0, oweCounter - 1) {
        if(source[i].existState == 1) {
            fprintf(fTemp, "%s %s %d\n",
                            source[i].id,
                            source[i].customerId,
                            source[i].totalOwe);
        }
    }

    // "tutup file"
    fclose(fTemp);
}

/*
 * DBMS
 */
// membersihkan layar
void clearscreen() {
    system(CLS);
    typeOfError = -1; // mencegah menampilkan pemberitahuan error
}

// membaca semua data dari file
void startDBMS(Customer *customer, Owe *owe) {
    // baca data customer dan owe
    readCustomerFromFile(customer, "customers.dat");
    readOweFromFile(owe, "owes.dat");

    // hubungkan data
    makeRelation(customer, owe);

    clearscreen(); // bersihkan layar dan tampilkan pesan bahwa telah mesin telah dapat dijalankan pengguna
    printf("HELLO! THIS IS DMBS\n");
    printf("THIS USE FOR RECORDING OWE DATA FROM CUSTOMER\n");
    printf("DMBS Version 1.0\n\n");
}

// menulis semua data ke file
void stopDBMS(Customer *customer, Owe *owe) {
    printf("HARAP TUNGGU...\n"); 
    clearscreen(); // bersihkan layar

    // flush data
    // tulis data customer dan owe ke fi
    writeCustomerToFile(customer, "customers.dat");
    writeOweToFile(owe, "owes.dat");

    exit(1);
}

// mengecek keberjalanan DBMS
int didDBMSStop() {
    return DBMSStopped;
}

// membadningkan lebih dahulu string p atau q
int compareString(char *p, char *q) {
    int compVal = strcmp(p, q);
    if(compVal < 0) return -1;
    else if(compVal == 0) return 0;
    return 1;
}

// mencari target pada struct foreign key
int searchByForeignKey(int lowerBoundIndex, int upperBoundIndex, char *target) {
    // deklarasi variable
    int i = lowerBoundIndex;
    int found = 0;
    int tableSource = typeOfTable;

    switch(tableSource) {
        case 1:
        while(i < oweCounter && found == 0) {
            if(compareString(foreignKey[i].customerId, target) != 0) i++;
            else found = 1;
        }
        break;

        case 2:
        while(i < oweCounter && found == 0) {
            if(compareString(foreignKey[i].oweId, target) != 0) i++;
            else found = 1;
        }
        break;
    }

    return i;
}

// mencari target pada struct customer atau owe
int sequentialSearch(int lowerBoundIndex, Customer *customer, Owe *owe, int typeOfTable, char *target) {
    int i = lowerBoundIndex;
    int found = 0;
    
    switch(typeOfTable) {
        case 1:
        while(i < customerCounter && found == 0) {
            if(compareString(customer[i].id, target) != 0) i++;
            else if(customer[i].existState == 0) i++;
            else found = 1;
        }
        break;
        case 2:
        while(i < oweCounter && found == 0) {
            if(compareString(owe[i].id, target) != 0) i++;
            else if(owe[i].existState == 0) i++;
            else found = 1;
        }
        break;
    }

    return i;
}

// mendapatkan tipe dari table
int getTypeOfTable(char *table) {
    if(strcmp(table, "customer") == 0) return 1;
    else if(strcmp(table, "owe") == 0) return 2;

    typeOfError = 201;
    return 0;
}

// membandingkan number berupa digit atau tidak
int isDigit(int number) {
    if(number >= 0 && number <= 9) return 1;
    return 0;
}

// konversi string ke integer
int stoi(char *str) {
    int number = 0, numberTemp;
    int i = 0, len = strlen(str);
    int stop = 0;

    while(stop == 0 && i < len) {
        numberTemp = str[i] - '0';

        i++;

        if(isDigit(numberTemp) == 1) number = (number * 10) + numberTemp;
        else stop = 1;
    }

    return number;
}

// menkonversi src berupa int ke menjadi string (dst)
void itos(int src, char *dst) {
    int digit[255], len = 0;
    while(src != 0) {
        digit[len] = src % 10;
        len++;
        src /= 10;
    }

    REP(i, 0, len) {
        dst[i] = digit[len - i - 1] + '0';
    }
    dst[len] = 0;
}

// menampilkan error yang terjadi
void handleError() {
    switch(typeOfError) {
        // tidak ada error 0 dan -1, tetapi hanya tampilkan pemberitahuan untuk 0
        case 0:
        printf("Successfully.\n");
        break;

        // argument tidak valid
        case 101:
        printf("Wrong query.\n");
        break;
        case 102:
        printf("Too few argument.\n");
        break;
        case 103:
        printf("Too much argument.\n");
        break;
        case 104:
        printf("Too much character.\n");
        break;

        // error pada pencarian
        case 201:
        printf("Cannot find the table.\n");
        break;
        case 202:
        printf("Cannot find Id\n");
        break;
        case 203:
        printf("Id was exist. It cannot be used.\n");
        break;
    }

    printf("\n");
}

/*
 * penggunaan return di bawah di gunakan untuk menghentikan subprogram
 * dengan tujuan untuk mencegah pekerjaan lebih lanjut dari DBMS
 * diakibatkan dari ditemukannya error
 */
// menyimpan data dari masukan ke penyimpan sementara
void makeTempRecord(char *tape) {
    inc(tape);
    if(eopWordMachine(tape) == 1) return;
    if(getlen() >= 20) {
        typeOfError = 104;
        return;
    }

    /*
     * masukkan seluruh data dari tape terurut berdasarkan urutan pada field pada struct
     * exist state diisi 1 karena data dianggap exist
    */
    switch(typeOfTable) {
        case 1:
        strcpy(customerTemp.id, getcw());

        inc(tape);
        if(eopWordMachine(tape) == 0) {
            typeOfError = 103;
            return;
        }
        if(getlen() >= 20) {
            typeOfError = 104;
            return;
        }

        strcpy(customerTemp.name, getcw());

        customerTemp.existState = 1;

        break;

        case 2:
        strcpy(oweTemp.id, getcw());

        inc(tape);

        if(eopWordMachine(tape) == 1) return;
        if(getlen() >= 20) {
            typeOfError = 104;
            return;
        }

        strcpy(oweTemp.customerId, getcw());

        inc(tape);
        if(eopWordMachine(tape) == 0) {
            typeOfError = 103;
            return;
        }
        if(getlen() >= 20) {
            typeOfError = 104;
            return;
        }

        oweTemp.totalOwe = stoi(getcw());
        oweTemp.existState = 1;
        break;
    }

    typeOfError = 0;
}

// melakukan pengisian data dengan tujuan menginsert/edit pada table
void insertEditRecord(Customer *customer, Owe *owe, int typeOfTable) {
    /*
     * data yang telah dimasukkan ke temp sudah divalidasi
     * sehingga dapat dimasukkan ke tabel
     */
    switch(typeOfTable) {
        case 1:
        customer[posTarget] = customerTemp;
        break;
        case 2:
        owe[posTarget] = oweTemp;
        break;
    }    
}

// melakukan pengisian data dengan tujuan menginsert/edit pada foreign
void insertEditForeignKey(int foreignKeyPos, int customerPos, int owePos) {
    /*
     * hubungkan data dengan cara mengisi posisi kedua data
     */
    strcpy(foreignKey[foreignKeyPos].customerId, oweTemp.customerId);
    strcpy(foreignKey[foreignKeyPos].oweId, oweTemp.id);
    foreignKey[foreignKeyPos].customerPos = customerPos;
    foreignKey[foreignKeyPos].owePos = owePos;
}

// membuat relasi antara customer dan owe
void makeRelation(Customer *customer, Owe *owe) {
    /*
     * untuk menghubungkan relasi, cari posisi data yang berhubungan
     * lalu isi data yang dibutuhkan berupa id dan posisi ke tabel foreign key
     */
    int customerPos, owePos = 0;
    while(owePos < oweCounter) {
        customerPos = sequentialSearch(0, customer, owe, 1, owe[owePos].customerId);
        if(customerPos < customerCounter) {
            oweTemp = owe[owePos];
            insertEditForeignKey(owePos, customerPos, owePos);
        }
        owePos++;
    }
}

// menginsert data dari tape ke table
void insertIntoTable(Customer *customer, Owe *owe, char *tape) {
    /*
     * periksa terlebih dahulu, apakah query insert diikuti edit atau tidak
     * jika iya, pada saat gagal melakukan pengisian data karena id exist, perbarui record data
     */
    int editRecord = 0;

    inc(tape);

    if(strcmp(getcw(), "EDIT") == 0) {
        editRecord = 1;

        inc(tape);
    }

    if(eopWordMachine(tape) == 1) return;

    typeOfTable = getTypeOfTable(getcw()); // periksa terlebih dahulu table mana yang akan diisi;
    if(typeOfTable == 0) return;

    // simpan data masukan ke temp
    makeTempRecord(tape);

    if(typeOfError != 0) return;

    switch(typeOfTable) {
        case 1:
        // periksa apakah data eksis
        posTarget = sequentialSearch(0, customer, owe, 1, customerTemp.id);

        // jika tidak, isi data
        if(posTarget == customerCounter) {
            insertEditRecord(customer, owe, 1);

            customerCounter++;
        } else if(editRecord == 1) {
            // jika exist dan query diikuti "edit", lakukan pengeditan data
            typeOfquery = 1;
            existTemp = 1;
        } else {
            typeOfError = 203;
        }
        break;

        case 2:
        // periksa apakah data eksis
        posTarget = sequentialSearch(0, customer, owe, 2, oweTemp.id);

        // jika tidak, isi data
        if(posTarget == oweCounter) {
            int owePos = posTarget, customerPos;
            customerPos = sequentialSearch(0, customer, owe, 1, oweTemp.customerId);

            if(customerPos == customerCounter) {
                typeOfError = 202;
                return;
            }

            insertEditRecord(customer, owe, 2);

            insertEditForeignKey(oweCounter, customerPos, owePos);

            oweCounter++;
        } else if(editRecord == 1) {
            // jika exist dan query diikuti "edit", lakukan pengeditan data
            typeOfquery = 1;
            existTemp = 1;
        } else {
            typeOfError = 203;
        }
        break;
    }
}

// mengedit data dari tape dari table
void editFromTable(Customer *customer, Owe *owe, char *tape) {
    // ketiadaan data temp berarti tidak ada query insert yang mendahului query edit
    if(existTemp == 0) {
        // isi terlebih dahulu temp
        inc(tape);

        if(eopWordMachine(tape) == 1) return;

        typeOfTable = getTypeOfTable(getcw()); // periksa terlebih dahulu table mana yang akan diisi;
        if(typeOfTable == 0) return;

        makeTempRecord(tape);

        if(typeOfError != 0) return;
        
        // cari data yang hendak diedit
        switch(typeOfTable) {
            case 1:
            posTarget = sequentialSearch(0, customer, owe, 1, customerTemp.id);
            break;
            
            case 2:
            posTarget = sequentialSearch(0, customer, owe, 2, oweTemp.id);
            break;
        }
    }

    typeOfError = 0;

    // edit data
    switch(typeOfTable) {
        case 1:
        if(posTarget != customerCounter) customer[posTarget] = customerTemp;
        else typeOfError = 202;
        break;

        case 2: // cascade data owe karena terhubung dengan customer
        if(posTarget != oweCounter) {

            int owePos = posTarget, customerPos = sequentialSearch(0, customer, owe, 1, oweTemp.customerId);

            if(customerPos == customerCounter) {
                typeOfError = 202;
                return;
            }

            owe[posTarget] = oweTemp;

            insertEditForeignKey(owePos, customerPos, owePos);
        } else {
            typeOfError = 202;
        }
        break;
    }
}

// menghapus data dari tape dari table
void deleteFromTable(Customer *customer, Owe *owe, char *tape) {
    inc(tape);
    if(eopWordMachine(tape) == 1) return;
    typeOfTable = getTypeOfTable(getcw()); // periksa terlebih dahulu table mana yang akan diisi;
    if(typeOfTable == 0) return;

    inc(tape);
    if(eopWordMachine(tape) == 0) {
        typeOfError = 103;
        return;
    }

    // cari id
    char *id = getcw();
    posTarget = sequentialSearch(0, customer, owe, typeOfTable, id);

    // hapus data
    switch(typeOfTable) {
        case 1: // cascade data customer karena terhubung dengan owe
        if(posTarget != customerCounter) {
            int customerPos = posTarget, owePos = 0;

            customer[customerPos].existState = 0;

            owePos = searchByForeignKey(owePos, oweCounter, customer[posTarget].id);

            while(owePos < oweCounter) {
                owe[owePos].existState = 0;

                strcpy(owe[owePos].id, "\0");
                owePos++;
                owePos = searchByForeignKey(owePos, oweCounter, customer[posTarget].id);
            }
            
            strcpy(customer[customerPos].id, "\0");
            typeOfError = 0;
        } else {
            typeOfError = 202;
        }
        break;

        case 2:
        if(posTarget != oweCounter) {
            owe[posTarget].existState = 0;
            strcpy(owe[posTarget].id, "\0");
            typeOfError = 0;
        } else {
            typeOfError = 202;
        }
        break;
    }
}

// menampilkan karakter c sebanyak sum
void repeatPrint(char c, int sum) {
    for(int i = 0; i < sum; i++) {
        printf("%c", c);
    }
}

// menampilkan satu kolom
void printAColumn(char *content, int width) {
    printf("%s", content);
    repeatPrint(' ', width - (int) strlen(content));
}

// menampilkan table
void showTable(Customer *customer, Owe *owe, char *tape) {
    // deklarasi variable
    int i = 0, j; // iterator
    int join = 0; // mode
    char str[22]; // temp int yang disimpan dalam bentuk string

    // periksa table mana saja yang hendak ditampilkan
    inc(tape);
    typeOfTable = 10 * getTypeOfTable(getcw()); // simpan type tabel pertama ke digit paling depan
    if(typeOfTable == 0) return;

    // jika ada table selanjutnya, isi digit belakang dengan type tabel dan aktifkan mode join
    if(eopWordMachine(tape) == 0) {
        inc(tape);
        typeOfTable += getTypeOfTable(getcw());
        if(typeOfTable == 0) return;

        join = 1;

        // cegah mengjoin pada tabel yang sama
        if(typeOfTable / 10 == typeOfTable % 10 || typeOfTable == 0) {
            return;
        }
    }

    inc(tape);
    if(eopWordMachine(tape) == 0) {
        typeOfError = 103;
        return;
    }

    // geser kembali digit table untuk mempermudah sintaksis
    typeOfTable /= 10;

    typeOfError = -1; // mencegah menampilkan pemberitahuan error
    switch(join) {
        case 0: // jangan lakukan inner join
        switch(typeOfTable) {
            case 1:
            printAColumn("id", 22);
            printAColumn("name", 22);
            printf("\n");

            while(i < customerCounter) {
                if(customer[i].existState == 1) {
                    printAColumn(customer[i].id, 22);
                    printAColumn(customer[i].name, 22);
                    printf("\n");
                }
                i++;
            }
            break;

            case 2:
            printAColumn("id", 22);
            printAColumn("customerId", 22);
            printAColumn("totalOwe", 22);
            printf("\n");

            while(i < oweCounter) {
                if(owe[i].existState == 1) {
                    itos(owe[i].totalOwe, str);

                    printAColumn(owe[i].id, 22);
                    printAColumn(owe[i].customerId, 22);
                    printAColumn(str, 22);
                    printf("\n");
                }
                i++;
            }
            break;
        }
        break; // tutup mode non inner join

        case 1: // lakukan inner join
        /*
         * lakukan pencarian pada foreign key untuk mendapatkan keterhubungan data
         * jika didapatkan keterhubungan, tampilkan data
         */
        switch(typeOfTable) {
            case 1:
            printAColumn("customerId", 22);
            printAColumn("name", 22);
            printAColumn("oweId", 22);
            printAColumn("totalOwe", 22);
            printf("\n");

            while(i < customerCounter) {
                if(customer[i].existState == 1) {
                    j = 0;
                    j = searchByForeignKey(j, oweCounter, customer[i].id);

                    while(j < oweCounter) {
                        if(owe[j].existState == 1) {
                            itos(owe[j].totalOwe, str);

                            printAColumn(customer[i].id, 22);
                            printAColumn(customer[i].name, 22);
                            printAColumn(owe[j].id, 22);
                            printAColumn(str, 22);
                            printf("\n");
                        }
                        j++;
                        j = searchByForeignKey(j, oweCounter, customer[i].id);
                    }
                }
                i++;
            }
            break;

            case 2:
            printAColumn("oweId", 22);
            printAColumn("totalOwe", 22);
            printAColumn("customerId", 22);
            printAColumn("name", 22);
            printf("\n");

            while(i < oweCounter) {
                if(owe[i].existState == 1) {
                    j = 0;
                    j = searchByForeignKey(j, oweCounter, owe[i].id);
                    
                    itos(owe[i].totalOwe, str);
                    while(j < oweCounter) {
                        if(customer[j].existState == 1) {
                            printAColumn(owe[i].id, 22);
                            printAColumn(str, 22);
                            printAColumn(customer[j].id, 22);
                            printAColumn(customer[j].name, 22);
                            printf("\n");
                        }
                        j++;
                        j = searchByForeignKey(j, oweCounter, owe[i].id);
                    }
                }
                i++;
            }
            break;
        }
        break; // tutup inner join
    }
}

// menentukan query yang akan dieksekusi
void readQuery(char *tape, Customer *customer, Owe *owe) {
    // deklarasi variable
    char substrOfQuery[101];    // menyimpan sementara kata yang ditunjuk mesin kata
    int queryFound = 0;         // flag ditemnukan atau tidaknya query
    int stop = 0;

    typeOfquery = 0;
    typeOfError = 102;
    existTemp = 0;

    startWordMachine(tape); // mulai mesin kata

    strcpy(substrOfQuery, getcw()); // simpan sementara kata yang ditunjuk mesin kata

    // cari query yang kemungkinan benar dengan mencocokkan query yang exist
    while(typeOfquery < 6 && queryFound == 0) {
        if(strcmp(substrOfQuery, query[typeOfquery]) == 0) {
            queryFound = 1;
        } else {
            typeOfquery++;
        }
    }

    // lanjutkan periksa query jika kemungkinan benar
    switch(typeOfquery) {
        case 0: // insert edit
        insertIntoTable(customer, owe, tape);

        if(typeOfquery == 1) {
            editFromTable(customer, owe, tape);
        }

        break;

        case 1: // edit
        editFromTable(customer, owe, tape);
        break;

        case 2: // penghapusan
        deleteFromTable(customer, owe, tape);
        break;
        
        case 3: // menampilkan tabel
        showTable(customer, owe, tape);
        break;
        
        case 4: // mengakhiri mesin DBMS
        char exitQuery[4][8] = {"lupa\0", "bahagia\0", "hari\0", "ini\0"};
        int i = 0;
        while(i < 4 && stop == 0) {
            inc(tape);
            if(strcmp(getcw(), exitQuery[i]) != 0) {
                queryFound = 0;
                typeOfError = 101;
                stop = 1;
            } else {
                i++;
            }
        }

        if(eopWordMachine(tape) == 0) {
            typeOfError = 101;
        } else if(queryFound == 1) {
            DBMSStopped = 1;
            typeOfError = -1;
        }
        break;

        default:
        typeOfError = 101;
        break;
    }

    handleError();
}
