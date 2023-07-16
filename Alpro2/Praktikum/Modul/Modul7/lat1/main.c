#include "header.h"
int main() {
    int n, nilaiPuluhan;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &nilaiPuluhan);

    int j = 0;
    int ditemukan = 0;
    while(j < n) {
        j = sequentialSearch(j, n, arr, nilaiPuluhan);
        if(j < n) {
            printf("%d ", arr[j]);
            ditemukan = 1;
        }
        j++;
    }

    if(ditemukan == 0) {
        printf("Tidak ditemukan");
    }
    printf("\n");

    return 0;
}