#include "header.h"
void geserLurus(int *X, int banyakLangkah) {
    (*X) += banyakLangkah;
}

void geserMiring(Koordinat *koordinat, int banyakLangkah) {
    geserLurus(&(*koordinat).x, banyakLangkah);
    geserLurus(&(*koordinat).y, banyakLangkah);
}