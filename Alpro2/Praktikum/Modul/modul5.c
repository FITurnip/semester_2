#include <stdio.h>
void printArr(int arr[])
{
    for (int i = 0; i < 8; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


int main()
{
    int key, i, j, swap, temp;
    int n;
    scanf("%d", &n);

    int arr[n];
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Sebelum di sort:\n");
    printArr(arr);
    // algoritma bubble sort
    do
    {
        swap = 0; // inisialisasi
        for (i = 0; i < n - 1; i++)
        { // jika data i lebih besar dari i+1
            if (arr[i] > arr[i + 1])
            { // tukar data
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;


                // tanda bahwa ada data yang ditukar
                swap = 1;
            }
        }
    } while (swap  == 1);


    printf("Setelah di sort:\n");
    printArr(arr);
    return 0;
}
