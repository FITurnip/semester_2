#include "header.h"
int main() {
    int i = 0;
    int n = 0;
    char pita[1000];

    do {
        scanf("%c", &pita[i]);

        if(pita[i] == ' ' || pita[i] == '.') {
            n++;
        }
        i++;
    } while(pita[i - 1] != '.');

    String arr[n];

    konversi(arr, pita);

    insertionSort(n, arr);

    for(int i = 0; i < n; i++) {
        if(arr[i].banyakA > 0) {
            if(i > 0) {
                printf(" ");
            }
            printf("%s", arr[i].s);
        }
    }

    printf("\n");

    return 0;
}