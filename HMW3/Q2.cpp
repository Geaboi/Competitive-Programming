#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;

    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<int> arr(n);
        vector<int> pos(n + 1,0);

        for(int i = 0; i < n; i++){
            cin >> arr[i];
            pos[arr[i]] = i;
        }
        int res = 0;
        for(int i = 2; i <= n; i++){
            if(pos[i] < pos[i - 1]){
                res++;
            }
        }

        cout << res << endl;

    }

}