#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

// 2 3 3 1 2 3 5 1 1 7
int main(){
    int t;
    cin >> t;

    while(t--){
        long long n;
        cin >> n;
        vector<long long> a(n);

        unordered_map<long long, vector<long long>> positions;

        for(int i = 0; i < n; i++){
            cin >> a[i];
            positions[a[i]].push_back(i);
        }

        vector<long long> dp(n + 1, 0);

        for(int i = 0; i < n; i++){
            dp[i + 1] = dp[i];                          
            long long v = a[i];
            auto &pos = positions[v];
            int idx = (int)(lower_bound(pos.begin(), pos.end(), i) - pos.begin());

            if(idx - (v - 1) >= 0){                    // enough copies before?
                int j = pos[idx - (v - 1)];            // where the block started
                dp[i + 1] = max(dp[i + 1], dp[j] + v); // extend from before block
            }
        }

        cout << dp[n ] << endl;
    }
}