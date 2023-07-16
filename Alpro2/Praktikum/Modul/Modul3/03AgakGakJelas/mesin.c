#include "header.h"
void agakGakJelas(int p, int q) {
    if(p >= 1) {
        printf("%d - %d\n", p, q);
        agakGakJelas(p / 2, q * 2);
    }
}