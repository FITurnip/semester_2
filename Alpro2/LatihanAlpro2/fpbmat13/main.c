#include <stdio.h>
#include "header.h"
int main() {
    char t;
    struct headerMatriks hm;
    for(long long i = 0; i < 2; i++) {
        scanf(" %c", &t);
        scanf(" %lld", &hm.o[i]);
        for(long long j = 0; j < hm.o[i]; j++) {
            scanf(" %lld", &hm.h[i][j]);
        }
    }
    
    for(long long i = 0; i < hm.o[1]; i++) {
        for(long long j = 0; j < hm.o[0]; j++) {
            printf("%lld\n", euclid(hm.h[1][i], hm.h[0][j]));
        }
    }
    return 0;
}