#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<vector<bool>> dp(k+1, vector<bool>(k+1, false));
    dp[0][0] = true;

    for(int i = 0; i < n; i++){
        int c;
        cin >> c;
        for(int a = k; a >= 0; a--){
            for(int b = k; b >= 0; b--){
                if(!dp[a][b]) continue;
                if(a + c <= k) dp[a+c][b] = true;
                if(b + c <= k) dp[a][b+c] = true;
            }
        }
    }

    vector<int> res;
    for(int x = 0; x <= k; x++){
        if(dp[x][k-x]) res.push_back(x);
    }

    cout << res.size() << "\n";
    for(int i = 0; i < (int)res.size(); i++){
        cout << res[i] << " \n"[i+1==(int)res.size()];
    }
}