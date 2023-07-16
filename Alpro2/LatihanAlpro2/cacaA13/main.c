#include "header.h"
int main() {
    char pita[1000];
    int jumlah;
    scanf(" %[^\n]", pita);

    jumlah = cariSesuaiKriteria(pita);
    printf("%d\n", jumlah);

    return 0;
}