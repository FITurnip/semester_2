#include "header.h"
int pangkatkan(int dasar, int derajat) {
    if(derajat > 0) {
        return dasar * pangkatkan(dasar, derajat - 1);
    } else if(derajat == 0) {
        return 1;
    }
}