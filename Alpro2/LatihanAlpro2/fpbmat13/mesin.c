#include "header.h"

long long euclid(long long a, long long b) {
    if(a == 0) {
        return b;
    } else {
        return euclid(b % a, a);
    }
}