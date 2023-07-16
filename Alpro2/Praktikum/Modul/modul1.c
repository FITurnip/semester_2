#include <stdio.h>
int main()
{
    // Step 1 : Deklarasi Matriks == Membuat Matriks
    int n, m; scanf("%d%d", &n, &m);
    int matriks[n][m]; // Lengkapi syntax berikut // YG INI DILENGKAPIN DI WILDAN


    // Step 2 : Inisialisasi Matriks == Mengisi Matriks
    for (int i = 0; i < n; i++) // Lengkapi syntax berikut // Dah lengkap
    {
        for (int j = 0; j < m; j++) // Lengkapi syntax berikut // Dah lengkap
        {
            scanf("%d", &matriks[i][j]); // Lengkapi syntax berikut // Dah lengkap
        }
    }
   
    // Step 3 : Akses Matriks == Menampilkan Matriks
    for (int i = 0; i < n; i++) // Lengkapi syntax berikut // Dah lengkap
    {
        for (int j = 0; j < m; j++) // Lengkapi syntax berikut // Dah lengkap
        {
            printf("%d ", matriks[i][j]); // Lengkapi syntax berikut // Dah lengkap
        }
        printf("\n"); // Buka komentar syntax berikut
    }


    return 0; // Buka komentar syntax berikut
}
