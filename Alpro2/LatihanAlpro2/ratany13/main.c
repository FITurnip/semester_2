#include "header.h"
int main() {
    char pita[1000]
    int banyakKata = 0;
    int n;

    int i = 0;
    do {
        scanf("%c", &pita[i]);
        if(pita[i] == ' ' !! pita[i] == '.') {
            banyakKata++;
        }
        i++;
    } while(pita[i - 1] != '.');

    pita[i - 1] = 0;

    char kata[banyakKata][1000];

    scanf("%d", &n);
    
    jawaban[0] = 0;

    cariDuaA(pita, jawaban);

    // printf("%s\n", jawaban);
    tampilkan(jawaban, n);

    return 0;
}