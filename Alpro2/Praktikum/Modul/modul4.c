#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);

    int arr[n];

    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int temp;
    int idxMin, i, j;
    for(i = 0; i < n - 1; i++) {
        idxMin = i;
        for(j = i + 1; j < n; j++) {
            if(arr[idxMin] < arr[j]) {
                idxMin = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[idxMin];
        arr[idxMin] = temp;
    }

    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}