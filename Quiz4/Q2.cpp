#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

struct Gate {
    char type;
    ll val;
};

void solve() {
    int n;
    if (!(cin >> n)) return;

    vector<Gate> left_gates(n), right_gates(n);
    for (int i = 0; i < n; ++i) {
        // Reads '+9' as type='+' and val=9 automatically
        cin >> left_gates[i].type >> left_gates[i].val;
        cin >> right_gates[i].type >> right_gates[i].val;
    }

    // dp[i] = how much 1 person at level i is worth by the end
    vector<ll> dp_l(n + 1, 1), dp_r(n + 1, 1);

    for (int i = n - 1; i >= 0; --i) {
        // Max weight for people added/existing at this step
        ll next_max = max(dp_l[i+1], dp_r[i+1]);

        // Left Gate: If multiplier, 1 person becomes 'val' people
        if (left_gates[i].type == '+') {
            dp_l[i] = dp_l[i+1];
        } else {
            // New population = current + (multiplier - 1) * max_future_weight
            dp_l[i] = dp_l[i+1] + (left_gates[i].val - 1) * next_max;
        }

        // Right Gate
        if (right_gates[i].type == '+') {
            dp_r[i] = dp_r[i+1];
        } else {
            dp_r[i] = dp_r[i+1] + (right_gates[i].val - 1) * next_max;
        }
    }

    // Starting people (1 in each lane)
    ll total = dp_l[0] + dp_r[0];

    // Add people from addition gates (always pick the lane with higher future weight)
    for (int i = 0; i < n; ++i) {
        ll future_weight = max(dp_l[i+1], dp_r[i+1]);
        if (left_gates[i].type == '+') {
            total += left_gates[i].val * future_weight;
        }
        if (right_gates[i].type == '+') {
            total += right_gates[i].val * future_weight;
        }
    }

    cout << total << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while (t--) solve();
    }
    return 0;
}