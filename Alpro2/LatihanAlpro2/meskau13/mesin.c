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

int komp(String a, String b) {
    int flag = 0;
    if(a.banyakA < b.banyakA) {
        flag = 1;
    } else if(a.banyakA == b.banyakA && a.pos > b.pos) {
        flag = 1;
    }

    return flag;
}

void insertionSort(int n, String *arr) {
    // Deklarasi Variable
    int i, j; // Iterator
    String temp; // Penampungan sementara arr

    // Urutkan dengan algoritma insertion sort
    for(i = 1; i < n; i++) {
        j = i - 1;
        temp = arr[i];

        while(j >= 0 && komp(temp, arr[j]) == 0) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = temp;
    }
}