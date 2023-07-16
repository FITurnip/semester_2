#include "header.h"
int main() {
    int i = 0;
    int n = 0;
    int batas;
    char pita[1000];

    do {
        scanf("%c", &pita[i]);

        if(pita[i] == ' ' || pita[i] == '.') {
            n++;
        }
        i++;
    } while(pita[i - 1] != '.');
    scanf(" %d", &batas);

    String arr[n];

    konversi(arr, pita);

    // for(int i = 0; i < n; i++) {
    //     printf("%s %d\n", arr[i].s, arr[i].banyakA);
    // }

    char ans[n][1000];

    for(int i = 0; i < n; i++) {
        ans[i][0] = 0;
    }

    buatTampilkan(n, ans, arr, batas);
    int len = 0;

    for(int i = 0; i < n; i++) {
        len = strlen(ans[i]);
        if(len > 0) {
            for(int j = len; j < batas; j++) {
                // printf("%d", j % 10);
                printf(" ");
            }
            printf("%s\n", ans[i]);
        }
    }

    return 0;
}