#include <stdio.h>
#include <string.h>

typedef struct {
    char s[1000];
    int pos, banyakA;
} String;

void konversi(String *arr, char *pita);
void insertionSort(int n, String *arr);