/*
    Saya Franklin Impianro Turnip(2203211) mengerjakan evaluasi TP5 dalam mata kuliah Alpro II untuk keberkahanNya
    maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/
// PENGGUNAAN LIBRARY
#include "header.h"
int main() {
    // DEKLARASI VARIABLE
    int jumlahMuridAR, jumlahMuridJC, jumlahMuridBS, jumlahMuridPC; // Jumlah murid tiap asrama; tiap nama asrama diambil inisialnya
    int totalJumlahMurid; // total murid dari semua asrama
    int minimalJumlahPower; // minimal jumlah power yang diperlukan
    char asasPengurutan[6]; // flag yang menentukan asas pengurutan berdasarkan Spell atau Power
    int jumlahMuridBerangkat; // total murid yang berangkat
    int totalPower, battlePower, evacuationPower; // statistik power

    // MEMINTA INPUT DARI USER
    // Masukkan jumlah murid pada asrama X dan input data murid-murid tersebut dengan lambang asrama seperti tertera
    scanf("%d", &jumlahMuridAR);
    Murid adoraRourie[jumlahMuridAR];
    scanElement(jumlahMuridAR, adoraRourie, '@');

    scanf("%d", &jumlahMuridJC);
    Murid jocelinCosu[jumlahMuridJC];
    scanElement(jumlahMuridJC, jocelinCosu, '&');
    
    scanf("%d", &jumlahMuridBS);
    Murid bodenSournois[jumlahMuridBS];
    scanElement(jumlahMuridBS, bodenSournois, '!');
    
    scanf("%d", &jumlahMuridPC);
    Murid pyneresCannes[jumlahMuridPC];
    scanElement(jumlahMuridPC, pyneresCannes, '$');

    scanf("%d %s", &minimalJumlahPower, asasPengurutan);

    // MENGOLAH DATA
    // Sorting semua murid dalam grup berupa asrama
    qsTengah(adoraRourie, 0, jumlahMuridAR - 1, asasPengurutan[0]);
    qsTengah(jocelinCosu, 0, jumlahMuridJC - 1, asasPengurutan[0]);
    qsTengah(bodenSournois, 0, jumlahMuridBS - 1, asasPengurutan[0]);
    qsTengah(pyneresCannes, 0, jumlahMuridPC - 1, asasPengurutan[0]);

    totalJumlahMurid = jumlahMuridAR + jumlahMuridBS + jumlahMuridJC + jumlahMuridPC; // Menjumlahkan semua murid dari semua asrama

    // Mendeklarasikan data yang digunakan secara sementara gabungan asrama dan semua data gabungan
    // Pada jumlah array yang lebih banyak, penggunaan temp seperti berikut akan lebih berguna karena dapat menghemat varible
    Murid temp[2][totalJumlahMurid], murid[totalJumlahMurid];

    merge(adoraRourie, jumlahMuridAR, jocelinCosu, jumlahMuridJC, temp[0], asasPengurutan[0]); // menggabungkan murid AR dan JC ke dalam temp[0]
    merge(bodenSournois, jumlahMuridBS, temp[0], jumlahMuridAR + jumlahMuridJC, temp[1], asasPengurutan[0]); // menggabungkan murid BS, AR, dan JC ke dalam temp[1]
    merge(pyneresCannes, jumlahMuridPC, temp[1], jumlahMuridAR + jumlahMuridJC + jumlahMuridBS, murid, asasPengurutan[0]); // mengggabungkan semua murid ke dalam struct murid

    // MENAMPILKAN DATA
    printf("*-,_,-*`*-,_,-*`*-,_,-*`*-,_,-*`*-,_,-*\n\n");
    printf("= A L L   W I Z A R D S =\n");
    printElement(totalJumlahMurid, murid); // Menampilkan semua data murid

    // Menghitung jumlah murid yang akan berangkat
    jumlahMuridBerangkat = hitungJumlahBerangkat(totalJumlahMurid, murid, minimalJumlahPower);

    printf("\n*-,_,-*`*-,_,-*`*-,_,-*`*-,_,-*`*-,_,-*\n\n");
    printf("= B A T T L E   L I N E U P =\n");
    printElement(jumlahMuridBerangkat, murid); // Menampilkan semua data murid yang akan berangkat

    // Menghitung statistik power saat ini
    battlePower = hitungTotalPower(0, jumlahMuridBerangkat, murid); // total power yang berangkat
    evacuationPower = hitungTotalPower(jumlahMuridBerangkat, totalJumlahMurid, murid); // total power yang tidak berangkat
    totalPower = battlePower + evacuationPower; // total power semua murid

    // Menampilkan statistik tersebut
    printf("\n*-,_,-*`*-,_,-*`*-,_,-*`*-,_,-*`*-,_,-*\n\n");
    printf("= P O W E R   S T A T I S T I C S =\n");
    printf("Total Power      : %d\n", totalPower);
    printf("Battle Power     : %d\n", battlePower);
    printf("Evacuation Power : %d\n", evacuationPower);
    printf("\n*-,_,-*`*-,_,-*`*-,_,-*`*-,_,-*`*-,_,-*\n");
    return 0;
}