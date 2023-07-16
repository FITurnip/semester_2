#include "header.h"
int main() {
    Mahasiswa mhs[100];
    SimpleData jurusan[100];
    SimpleData fakultas[100];

    int banyakMhs, banyakJurusan, banyakFakultas;

    banyakMhs = bacaFileKeMahasiswa("Mahasiswa.txt", mhs);
    banyakJurusan = bacaFileKeSimpleData("Jurusan.txt", jurusan);
    banyakFakultas = bacaFileKeSimpleData("Fakultas.txt", fakultas);

    for(int i = 0; i < banyakMhs; i++) {
        printf("%s %s %s\n", mhs[i].nama, jurusan[binarySearch(0, banyakJurusan, jurusan, mhs[i].id_jurusan)].nama, fakultas[binarySearch(0, banyakFakultas, fakultas, mhs[i].id_fakultas)].nama);
    }
    return 0;
}