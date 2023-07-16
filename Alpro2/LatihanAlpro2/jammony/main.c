#include "header.h"

int main() {
    int n;

    scanf("%d", &n);

    int jumDetik[n];
    FormatJam formatJam[n];

    for(int i = 0; i < n; i++) {
        scanf("%d", &jumDetik[i]);
        jumDetik[i] %= 86400;
    }

    insertionSort(n, jumDetik);

    for(int i = 0; i < n; i++) {
        konversiKeFormatJam(jumDetik[i], &formatJam[i]);
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 3; j++) {
            if(formatJam[i].fj[j] < 10) {
                printf("0");
            }
            printf("%d", formatJam[i].fj[j]);
            if(j < 2) {
                printf(":");
            }
        }
        printf("\n");
    }

    return 0;
}