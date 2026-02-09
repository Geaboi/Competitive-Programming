#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n, k;
        cin >> n >> k;
        
        vector<long long> a(n), b(n);
        
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        
        vector<long long> a_sorted = a;
        vector<long long> b_sorted = b;
        sort(a_sorted.begin(), a_sorted.end());
        sort(b_sorted.begin(), b_sorted.end());
        
        set<long long> price_set(a.begin(), a.end());
        price_set.insert(b.begin(), b.end());
        
        long long max_earnings = 0;
        
        for (long long price : price_set) {
            int pos_reviews = n - (lower_bound(a_sorted.begin(), a_sorted.end(), price) - a_sorted.begin());
            
            int total_buyers = n - (lower_bound(b_sorted.begin(), b_sorted.end(), price) - b_sorted.begin());
            
            int neg_reviews = total_buyers - pos_reviews;
            
            if (neg_reviews <= k) {
                long long earnings = price * total_buyers;
                max_earnings = max(max_earnings, earnings);
            }
        }
        
        cout << max_earnings << "\n";
    }
    
    return 0;
}