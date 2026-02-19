// arr[i] = min number of seconds needed to destroy the enitre line
// U can remove to form a palindrome or remove a palindrome which takes one second
// Either delete the palindrome or keep it for another one ig
// 1 4 4 2 3 2 1
// Do something where I calculate palindromes or something
// Exponenetial time recaculating and calculating all palindromes

#include <vector>
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    vector<vector<int>> dp(n, vector<int> (n, 1e9));

    for(int i = 0; i < n; i++){
        dp[i][i] = 1;
    }

    for(int len = 2; len <= n; len++){
        for(int i = 0; i <= n - len; i++){
            int j = i + len - 1;

            if(arr[i] == arr[j]){
                dp[i][j] = (len == 2) ? 1 : dp[i + 1][j-1];
            }

            //Try all splitting points
            for(int m = i; m < j; m++){
                dp[i][j] = min(dp[i][j], dp[i][m] + dp[m + 1][j]);
            }

        }
    }

    cout << dp[0][n-1] << '\n';
}