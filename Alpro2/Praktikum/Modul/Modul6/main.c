#include "header.h"
int main() {
    // SEMOGA EVALNYA G NGABISIN WAKTUU..
    int nA, nB, nC;
    scanf("%d", &nA);

    Mahasiswa a[nA];
    scanElement(nA, a);

    scanf("%d", &nB);

    Mahasiswa b[nB];
    scanElement(nB, b);

    scanf("%d", &nC);

    Mahasiswa c[nC];
    scanElement(nC, c);

    qsTengah(a, 0, nA - 1);
    qsTengah(b, 0, nB - 1);
    qsTengah(c, 0, nC - 1);

    Mahasiswa d[nA + nB], e[nA + nB + nC];
    merge(a, nA, b, nB, d);
    merge(d, nA + nB, c, nC, e);

    int len = nA + nB + nC;
    for(int i = 0; i < len; i++) {
        printf("%s %s\n", e[i].nim, e[i].nama);
    }
    return 0;
}