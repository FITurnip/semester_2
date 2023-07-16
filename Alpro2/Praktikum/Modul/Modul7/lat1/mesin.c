#include "header.h"
int komp(int a, int b) {
    int flag = 1;
    if(a < 10) {
        flag = 0;
    } else {
        a %= 100;
        a /= 10;
        if(a != b) {
            flag = 0;
        }
    }
    return flag;
}

int sequentialSearch(int i, int n, int arr[], int target) {
    int ditemukan = 0;
    while(i < n && ditemukan == 0) {
        if(komp(arr[i], target) == 0) {
            i++;
        } else {
            ditemukan = 1;
        }
    }

    return i;
}