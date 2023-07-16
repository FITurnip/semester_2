#include "header.h"
void tukar(char p[100], char q[100]) {
    char r[100];
    strcpy(r, p);
    strcpy(p, q);
    strcpy(q, r);
}

void urutkanMenaik(int n, char nama[n][100]) { // Insertion sort
    int i, j;
    char temp[100];
    for(i = 1; i < n; i++) {
        strcpy(temp, nama[i]);
        j = i - 1;
        while(j >= 0 && strcmp(temp, nama[j]) < 0) {
            strcpy(nama[j + 1], nama[j]);
            j--;
        }
        strcpy(nama[j + 1], temp);
    }
}

void urutkanMenurun(int n, char nama[n][100]) { // Selection sort
    int idxMin, i, j;
    for(i = 0; i < n - 1; i++) {
        idxMin = i;
        for(j = i + 1; j < n; j++) {
            if(strcmp(nama[idxMin], nama[j]) < 0) {
                idxMin = j;
            }
        }
        tukar(nama[i], nama[idxMin]);
    }
}

void scanElemen(int n, char nama[n][100]) {
    for(int i = 0; i < n; i++) {
        scanf("%s", nama[i]);
    }
}

void tampilkanElemen(int n, char nama[n][100]) {
    for(int i = 0; i < n; i++) {
        printf("%s\n", nama[i]);
    }
}