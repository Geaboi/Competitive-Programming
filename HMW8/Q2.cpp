#include <bits/stdc++.h>
using namespace std;

int par[200001], rnk[200001];

int find(int x) {
    while (par[x] != x) x = par[x] = par[par[x]];
    return x;
}

bool unite(int a, int b) {
    a = find(a); b = find(b);
    if (a == b) return false;
    if (rnk[a] < rnk[b]) swap(a, b);
    par[b] = a;
    if (rnk[a] == rnk[b]) rnk[a]++;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        long long k;
        cin >> n >> m >> k;

        vector<array<long long, 3>> edges(m);
        for (int i = 0; i < m; i++)
            cin >> edges[i][0] >> edges[i][1] >> edges[i][2];

        sort(edges.begin(), edges.end(), [](auto& a, auto& b) {
            return a[2] < b[2];
        });

        for (int i = 1; i <= n; i++) { par[i] = i; rnk[i] = 0; }

        long long excess = 0;
        long long maxw = 0;
        int cnt = 0;

        for (int i = 0; i < m; i++) {
            if (unite(edges[i][0], edges[i][1])) {
                cnt++;
                maxw = edges[i][2];
                if (edges[i][2] > k) excess += edges[i][2] - k;
            }
            if (cnt == n - 1) break;
        }

        long long ans;
        if (maxw >= k) {
            ans = excess;
        } else {
            long long best_below = 0;
            for (int i = m - 1; i >= 0; i--) {
                if (edges[i][2] <= k) {
                    best_below = edges[i][2];
                    break;
                }
            }
            ans = k - best_below;
            for (int i = 0; i < m; i++) {
                if (edges[i][2] >= k) {
                    ans = min(ans, edges[i][2] - k);
                    break;
                }
            }
        }

        cout << ans << "\n";
    }
    return 0;
}