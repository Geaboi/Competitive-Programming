#include <vector>
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n), b(n), pos(n + 1);
    
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        pos[b[i]] = i;
    }
    
    vector<int> c(n);
    for (int i = 0; i < n; i++) c[i] = pos[a[i]];
    
    vector<int> tails;
    for (int x : c) {
        auto it = lower_bound(tails.begin(), tails.end(), x);
        if (it == tails.end()) tails.push_back(x);
        else *it = x;
    }
    
    cout << tails.size() << "\n";
}