#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n, m, c0, d0;
    cin >> n >> m >> c0 >> d0;

    vector<int> a(m), b(m), c(m), d(m);
    for(int i = 0; i < m; i++)
        cin >> a[i] >> b[i] >> c[i] >> d[i];

    // dp[j] = max profit using first i stuffing types with j grams of dough
    vector<int> dp(n + 1, 0);

    for(int i = 0; i < m; i++){
        int maxk = a[i] / b[i]; // max buns of type i (limited by stuffing)
        // iterate backwards for bounded knapsack
        for(int j = n; j >= 0; j--){
            for(int k = 1; k <= maxk && k * c[i] <= j; k++){
                dp[j] = max(dp[j], dp[j - k * c[i]] + k * d[i]);
            }
        }
    }

    // finally, spend remaining dough on plain buns
    int ans = 0;
    for(int j = 0; j <= n; j++){
        int plain = (n - j) / c0;
        ans = max(ans, dp[j] + plain * d0);
    }

    cout << ans << endl;
}