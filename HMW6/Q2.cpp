#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> t(n), f(n);
    for(int i = 0; i < n; i++){
        long long a;
        cin >> a;
        while(a % 2 == 0){ t[i]++; a /= 2; }
        while(a % 5 == 0){ f[i]++; a /= 5; }
    }

    int maxF = 0;
    for(int i = 0; i < n; i++) maxF += f[i];

    vector<vector<int>> dp(k+1, vector<int>(maxF+1, -1));
    dp[0][0] = 0;

    for(int i = 0; i < n; i++){
        for(int j = min(i+1, k); j >= 1; j--){
            for(int s = maxF; s >= f[i]; s--){
                if(dp[j-1][s-f[i]] >= 0){
                    dp[j][s] = max(dp[j][s], dp[j-1][s-f[i]] + t[i]);
                }
            }
        }
    }

    int ans = 0;
    for(int s = 0; s <= maxF; s++){
        if(dp[k][s] >= 0)
            ans = max(ans, min(s, dp[k][s]));
    }
    cout << ans << "\n";
}