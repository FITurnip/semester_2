#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a; i < b; i++)
using namespace std;

int hitungSec(int n, int arr[]) {
    int sum = 0, negatif = arr[0];
    bool exist = 0;

    FOR(i, 0, n) {
        if(arr[i] >= 0) {
            sum += arr[i];
            exist = 1;
        }
        else if(arr[i] > negatif) negatif = arr[i];
    }
    if(exist) {
        return sum;
    } else {
        return negatif;
    }
}

int hitungArr(int n, int Arr[]) {
    int sum = 0, maxSum = -1 * pow(10, 9);

    FOR(i, 0, n) {
        FOR(j, i, n) {
            sum = 0;
            FOR(k, i, j + 1) sum += Arr[k];
            maxSum = max(sum, maxSum);
        }
    }

    return maxSum;
}

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, n;
    cin >> t;
    int sumArr, sumSec;
    FOR(i, 0, t) {
        cin >> n;

        int arr[n];
        FOR(j, 0, n) cin >> arr[j];
        sumArr = hitungArr(n, arr);
        sumSec = hitungSec(n, arr);
        cout << sumArr << " " << sumSec << endl;
    }
	return 0;
}