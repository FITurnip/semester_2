#include <stdio.h>
typedef struct {
    char jenis[11];
    int banyak;
} Langkah;

typedef struct {
    int x, y;
} Koordinat;

typedef struct {
    Koordinat koordinat;
    int jumlahLangkah;
    Langkah langkah[100];
} Robot;

void geserLurus(int *X, int banyakLangkah);
void geserMiring(Koordinat *koordinat, int banyakLangkah);