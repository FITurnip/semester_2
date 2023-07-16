#include "header.h"
int ialahBilanganPrima(int N) {
    int kebenaran = 1;
    int i = 2;
    while(i * i <= N && kebenaran == 1) {
        if(N % i == 0) kebenaran = 0;
        i++;
    }
    return kebenaran;
}