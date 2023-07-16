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

int cariSesuaiKriteia(char pita[1000]) {
    int jumlah = 0;
    int ujung = strlen(pita) - 1;
    int i = 0;
    while(i < ujung) {
        if(berupaKarakter(pita[i]) == 1) {
            if(pita[i + 1] == ' ' && i + 1 < ujung) {
                if(berupaKarakter(pita[i + 2]) == 1 && i + 2 < ujung) {
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