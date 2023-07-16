#include <stdio.h>
typedef struct {
    int x, y;
} Koordinat;
int kodekanArahMenghadap(char c);
void gerakkanRobot(int kodeArahMenghadap, int banyakLangkah, Koordinat *koor);
void rotasikan(int *kodeArahMenghadap, int banyakRotasi);
void tampilkan(Koordinat koor);