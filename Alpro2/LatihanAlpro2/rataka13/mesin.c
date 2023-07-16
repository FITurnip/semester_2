#include "header.h"
void konversi(String *arr, char *pita) {
    int i = 0, j = 0, k = 0;

    arr[j].banyakA = 0;
    do {
        if(pita[i] != ' ' && pita[i] != '.') {
            arr[j].s[k] = pita[i];
            if(pita[i] == 'a') {
                arr[j].banyakA++;
            }

            k++;
        } else {
            arr[j].s[k] = 0;
            arr[j].pos = j;
            j++;
            arr[j].banyakA = 0;
            k = 0;
        }

        i++;
    } while(pita[i - 1] != '.');
}
void gabung(char *str1, char *str2) {
    int i = strlen(str1), j = 0, len = strlen(str2);
    while(j < len) {
        str1[i] = str2[j];
        i++;
        j++;
    }

    str1[i] = 0;
}

void buatTampilkan(int n, char c[n][1000], String *arr, int batas) {
    int i = 0, j = 0, lenC, lenS;
    while(i < n) {
        if(arr[i].banyakA > 0) {
            lenC = strlen(c[j]);
            lenS = strlen(arr[i].s);
            if(lenC == 0) {
                gabung(c[j], arr[i].s);
            } else {
                if(lenS + 1 + lenC < batas) {
                    gabung(c[j], " ");
                    gabung(c[j], arr[i].s);
                } else if(lenS + 1 + lenC == batas) {
                    gabung(c[j], " ");
                    gabung(c[j], arr[i].s);
                    j++;
                } else {
                    i--;
                    j++;
                }
            }
        }
        i++;
    }
}