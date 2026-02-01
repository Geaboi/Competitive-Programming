#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int testcases;
    cin >> testcases;

    while(testcases--){
        long long n, m, h;
        cin >> n >> m >> h;

        vector<long long> arr(n);
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }

        vector<long long> sum(n, 0);
        vector<int> lastRest(n,-1);
        int crash = -1;

        for(int i = 0; i < m; i++){
            int b, c;

            cin >> b >> c;

            if(lastRest[b-1] < crash){
                sum[b-1] = 0;
                lastRest[b-1] = crash;
            }

            sum[b-1] += c;

            if(sum[b-1] + arr[b-1] > h){
                crash = i;
            }

        }

        for(int i = 0; i < n; i++){
            if(lastRest[i] < crash){
                cout << arr[i] << " ";
            }else{
                cout << arr[i] + sum[i] << " ";
            }
        }
        cout << '\n';
    }

    return 0;
}