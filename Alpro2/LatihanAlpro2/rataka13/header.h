#include <stdio.h>
#include <string.h>
typedef struct {
    char s[1000];
    int pos, banyakA;
} String;

void konversi(String *arr, char *pita);
void buatTampilkan(int n, char c[n][1000], String *arr, int batas);