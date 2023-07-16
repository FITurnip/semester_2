#include <stdio.h>
#include <math.h>
typedef struct {
    int bil[4];
    int banyak;
} Digit;

typedef struct {
    int bil[7];
    int banyak;
} Permutasi;

int berupaBilPrima(int n);
void konversiKeDigit(int n, Digit *digit);
void permutasikan(Digit digit, Permutasi *permut, int idxKiri);