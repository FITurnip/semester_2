#include "header.h"
int main() {
    int n;
    scanf("%d", &n);

    char nama[n][100];
    char metodePengurutan[100];
    
    scanElemen(n, nama);
    scanf("%s", metodePengurutan);

    if(metodePengurutan[0] == 'i') urutkanMenaik(n, nama);
    else urutkanMenurun(n, nama);
    tampilkanElemen(n, nama);
    return 0;
}