#include "header.h"
int main() {
    int n;
    int j;
    Permutasi permut;
    Digit digit;

    scanf("%d", &n);

    int batasBawah[n], jawaban[n];

    for(int i = 0; i < n; i++) {
        scanf("%d", &batasBawah[i]);
    }

    for(int i = 0; i < n; i++) {
        jawaban[i] = 0;

        while(jawaban[i] == 0 && batasBawah[i] < 998) {
            if(berupaBilPrima(batasBawah[i]) == 1) {
                konversiKeDigit(batasBawah[i], &digit);
                if(digit.banyak == 1) {
                    jawaban[i] = batasBawah[i];
                } else {
                    // printf("===\n");
                    permut.banyak = 0;
                    permutasikan(digit, &permut, 0);
                    permut.banyak--;
                    j = 0;
                    while(j < permut.banyak && jawaban[i] == 0) {
                        if(berupaBilPrima(permut.bil[j]) == 1) {
                            jawaban[i] = batasBawah[i];
                        }
                        j++;
                    }
                }
            }
            
            batasBawah[i]++;
        }

        printf("%d\n", jawaban[i]);
    }
    return 0;
}