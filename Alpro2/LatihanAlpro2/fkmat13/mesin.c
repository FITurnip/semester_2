#include "header.h"

long long faktorial(long long n) {
    if(n < 2) {
        return 1;
    } else {
        return faktorial(n - 1) * n;
    }
}