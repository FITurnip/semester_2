#include <stdio.h>
#include "header.h"
int main() {
    char t;
    long long tInt = 0;
    struct headerMatriks hm;
    for(long long i = 0; i < 2; i++) {
        scanf(" %c", &t);
        scanf(" %lld", &hm.o[tInt]);
        for(long long j = 0; j < hm.o[tInt]; j++) {
            scanf(" %lld", &hm.h[tInt][j]);
            hm.h[tInt][j] = faktorial(hm.h[tInt][j]);
            // printf("%lld ", hm.h[i][j]);
        }
        // printf("\n");
        tInt++;
    }
    
    for(long long i = 0; i < hm.o[1]; i++) {
        for(long long j = 0; j < hm.o[0]; j++) {
            printf("%lld\n", hm.h[1][i] * hm.h[0][j]);
        }
    }
    return 0;
}