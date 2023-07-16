#include <stdio.h>
#include <string.h>
typedef struct {
    char nama[216];
    char id_jurusan[6];
    char id_fakultas[6];
} Mahasiswa;

typedef struct {
    char id[6];
    char nama[216];
} SimpleData;

void insertionSort(int kiri, int kanan, SimpleData *sumber);
int bacaFileKeSimpleData(char *nama_file, SimpleData *dst);
int bacaFileKeMahasiswa(char *nama_file, Mahasiswa *dst);
int binarySearch(int kiri, int kanan, SimpleData arr[], char *target);