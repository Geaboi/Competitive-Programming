#include <iostream>
#include <cstring>
using namespace std;

int a[500];
int val[500][500];
int dp[500][500];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    memset(val, -1, sizeof(val));

    for (int i = 0; i < n; i++) {
        val[i][i] = a[i];
        dp[i][i] = 1;
    }

    for (int len = 2; len <= n; len++) {
        for (int l = 0; l + len - 1 < n; l++) {
            int r = l + len - 1;
            dp[l][r] = len;

            for (int mid = l; mid < r; mid++) {
                if (val[l][mid] != -1 && val[l][mid] == val[mid + 1][r]) {
                    val[l][r] = val[l][mid] + 1;
                }
                dp[l][r] = min(dp[l][r], dp[l][mid] + dp[mid + 1][r]);
            }

            if (val[l][r] != -1) dp[l][r] = 1;
        }
    }

    cout << dp[0][n - 1] << endl;
}