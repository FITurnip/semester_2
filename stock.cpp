#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a; i < b; i++)
using namespace std;

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, n;
    cin >> t;

    FOR(i, 0, t) {
        cin >> n;
        int price[n];
        
        FOR(j, 0, n) {
            cin >> price[j];
        }
        
        int totalSaham = 1, totalProfit = 0, totalHargaSaham = price[0], jual = 0, idxTerendah = 0;

        FOR(j, 1, n) {
            if(price[j] < price[idxTerendah]) {
                totalProfit = totalProfit + (price[j - 1] * (totalSaham - 1) - (totalHargaSaham - price[j - 1]));

                totalHargaSaham = price[j];
                totalSaham = 1;
                jual = 1;
                idxTerendah = j;
            } else {
                totalSaham++;
                totalHargaSaham += price[j];
                jual = 0;
            }
            // cout << totalSaham << " " << totalHargaSaham << " " << totalProfit << endl;
        }

        if(jual == 0) {
            totalProfit = totalProfit + (price[n - 1] * totalSaham - totalHargaSaham);
        }

        cout << totalProfit << endl;
    }
    return 0;
}