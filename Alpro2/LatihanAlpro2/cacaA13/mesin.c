#include "header.h"
int berupaKarakter(char c) {
    int betul = 0;
    if(c >= 'a' && c <= 'z') {
        betul = 1;
    } else if(c >= 'A' && c <= 'Z') {
        betul = 1;
    }

    return betul;
}

int cariSesuaiKriteria(char pita[100]) {
    int jumlah = 0;
    int i = 1;
    int ujung = strlen(pita) - 1;
    while(i < ujung) {
        if(pita[i] == 'a') {
            if(berupaKarakter(pita[i - 1]) == 1) {
                if(berupaKarakter(pita[i + 1]) == 1 && i < ujung) {
                    jumlah++;
                    i += 2;
                } else {
                    i++;
                }
            } else {
                i++;
            }
        } else {
            i++;
        }
    }

    return jumlah;
}