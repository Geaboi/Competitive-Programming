#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
   int n, q;
    cin >> n >> q;

    vector<long long> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    vector<long long> diff(n + 1, 0);
    for(int i = 0; i < q; i++){
        int l, r;
        cin >> l >> r;
        diff[l - 1]++;
        diff[r]--;
    }

    // Convert diff to frequencies in-place
    for(int i = 1; i < n; i++){
        diff[i] += diff[i - 1];
    }

    sort(diff.begin(), diff.end() - 1);  // Sort first n elements
    sort(arr.begin(), arr.end());

    long long ans = 0;
    for(int i = 0; i < n; i++){
        ans += diff[i] * arr[i];
    }

    cout << ans << endl;
}