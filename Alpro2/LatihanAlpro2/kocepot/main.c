#include "header.h"
int main() {
    int banyakKasus;
    int indeksJenisLangkah;

    scanf("%d", &banyakKasus);

    Robot robot[banyakKasus];
    for(int i = 0; i < banyakKasus; i++) {
        scanf(" %d %d", &robot[i].koordinat.x, &robot[i].koordinat.y);
        scanf(" %d", &robot[i].jumlahLangkah);
        for(int j = 0; j < robot[i].jumlahLangkah; j++) {
            scanf(" %s %d", robot[i].langkah[j].jenis, &robot[i].langkah[j].banyak);

            indeksJenisLangkah = 0;

            if(robot[i].langkah[j].jenis[indeksJenisLangkah] == '-') {
                indeksJenisLangkah++;
                robot[i].langkah[j].banyak *= -1;
            }

            switch(robot[i].langkah[j].jenis[indeksJenisLangkah]) {
                case 'h':
                geserLurus(&robot[i].koordinat.x, robot[i].langkah[j].banyak);
                break;
                case 'v':
                geserLurus(&robot[i].koordinat.y, robot[i].langkah[j].banyak);
                break;
                case 'm':
                geserMiring(&robot[i].koordinat, robot[i].langkah[j].banyak);
                break;
            }

            // printf("%d %d\n", robot[i].koordinat.x, robot[i].koordinat.y);
        }
        // printf("\n");
    }

    for(int i = 0; i < banyakKasus; i++) printf("%d %d\n", robot[i].koordinat.x, robot[i].koordinat.y);
    return 0;
}