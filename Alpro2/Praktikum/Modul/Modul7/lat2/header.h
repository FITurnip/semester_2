#include <stdio.h>
#include <string.h>

typedef struct {
    char nim[8], nama[100], kelas[8];
} Mahasiswa;
int binarySearch(int n, Mahasiswa arr[], char target[]);