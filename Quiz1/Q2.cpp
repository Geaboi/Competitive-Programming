#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<long long> pre_arr(n + 1, 0);
    for(int i = 1; i <= n; i++){
        long long val;
        cin >> val;
        pre_arr[i] = pre_arr[i - 1] + val;
    }

    vector<long long> b(k);
    for(int i = 0; i < k; i++){  // ADD THIS LOOP
        cin >> b[i];
    }

    set<long long> possible;
    bool first = true;

    for (int j = 0; j < k; j++) {
        set<long long> current;
        for (int i = 1; i <= n; i++) {
            current.insert(b[j] - pre_arr[i]);
        }
        
        if (first) {
            possible = current;
            first = false;
        } else {
            set<long long> intersection;
            set_intersection(possible.begin(), possible.end(),
                            current.begin(), current.end(),
                            inserter(intersection, intersection.begin()));
            possible = intersection;
        }
        
        if (possible.empty()) {
            cout << 0 << endl;
            return 0;
        }
    }

    cout << possible.size() << endl;  // ADD THIS LINE

    return 0;
}