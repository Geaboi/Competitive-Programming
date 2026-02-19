#include <vector>
#include <iostream>

using namespace std;


int main() {
    int t;
    cin >> t;

    while(t--){
        long long n, p, k;

        cin >> n >> p >> k;

        vector<int> arr(n + 1, 0);

        string s;
        cin >> s;
        long long x,y;
        cin >> x >> y;
        for(int i = 1; i <= n; i++) arr[i] = s[i-1] - '0';



        vector<int> suffix(n + k + 1, 0);
        for(int i = n; i >= 1; i--){
            suffix[i] = (arr[i] == 0) + (i + k <= n ? suffix[i + k] : 0);
        }

        long long min_cost = 1e18;

        for(int i = p; i <= n; i++){
            long long current_removals = (i - p) * y;

            long long missing = suffix[i];
            long long current_additions = missing * x;

            min_cost = min(min_cost, current_additions + current_removals);
        }

        cout << min_cost << '\n';
    }

}