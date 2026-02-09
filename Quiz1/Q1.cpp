#include <bits/stdc++.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> arr(n);
    vector<long long> sorted_arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sorted_arr[i] = arr[i];
    }

    sort(sorted_arr.begin(), sorted_arr.end());
    vector<long long> prefix_sum(n + 1, 0);
    vector<long long> sort_prefix_sum(n + 1, 0);

    for(int i = 1; i <= n; i++){
        prefix_sum[i] = prefix_sum[i-1] + arr[i-1];
        sort_prefix_sum[i] = sort_prefix_sum[i-1] + sorted_arr[i-1];
    }

    int t;

    cin >> t;

    while(t--){
        int type, l , r;

        cin >> type >> l >> r;

        if(type == 1){
            cout << prefix_sum[r] - prefix_sum[l-1] << endl;
        }
        else{
            cout << sort_prefix_sum[r] - sort_prefix_sum[l-1] << endl;
        }
    }

}