#include "header.h"
int main() {
    int n;
    Koordinat koor;
    int order, banyakLangkah, banyakRotasi;
    char arahMenghadap;
    int kodeArahMenghadap;

    scanf("%d", &n);
    scanf("%d %d", &koor.x, &koor.y);

    scanf(" %c", &arahMenghadap);
    kodeArahMenghadap = kodekanArahMenghadap(arahMenghadap);

    for(int i = 0; i < n; i++) {
        scanf("%d", &order);
        switch(order) {
            case 1:
            scanf("%d", &banyakLangkah);
            gerakkanRobot(kodeArahMenghadap, banyakLangkah, &koor);
            break;
            case 2:
            scanf("%d", &banyakLangkah);
            gerakkanRobot(kodeArahMenghadap, -banyakLangkah, &koor);
            break;
            case 3:
            scanf("%d", &banyakRotasi);
            rotasikan(&kodeArahMenghadap, -banyakRotasi);
            break;
            case 4:
            scanf("%d", &banyakRotasi);
            rotasikan(&kodeArahMenghadap, banyakRotasi);
            break;
            case 5:
            printf("%d %d\n", koor.x, koor.y);
            break;
            case 6:
            tampilkan(koor);
            break;
        }
    }
    
    return 0;
}