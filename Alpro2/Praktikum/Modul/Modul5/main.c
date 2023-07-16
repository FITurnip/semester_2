#include "header.h"
int main() {
    int n;
    char metodeSorting;
    scanf("%d", &n);

    Pecahan pecahan[n];
    for(int i = 0;i < n; i++) {
        scanf("%d %d", &pecahan[i].pmb, &pecahan[i].pny);
    }

    scanf(" %c", &metodeSorting);
    
    switch(metodeSorting) {
        case 'b':
        bubbleSort(pecahan, n);
        break;
        case 'q':
        qsTengah(pecahan, 0, n - 1);
        break;
    }

    for(int i = 0; i < n; i++) {
        if(i > 0) {
            printf(" ");
        }
        printf("%d", pecahan[i].pmb);
    }
    printf("\n");

    for(int i = 0; i < n; i++) {
        if(i > 0) {
            printf(" ");
        }
        printf("-");
    }
    printf("\n");

    for(int i = 0; i < n; i++) {
        if(i > 0) {
            printf(" ");
        }
        printf("%d", pecahan[i].pny);
    }
    printf("\n");
}