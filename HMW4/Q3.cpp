#include <iostream>
#include <vector>

using namespace std;

int main(){
    int t;
     
    cin >> t;

    while(t--){
        long long n, m, k;

        cin >> n >> m >> k;

        int l = 0;
        int r = 0;

        while (true){
            bool tried = false;

            if(l < k - 1 && l + max(l + 1, r) + r <= m){
                l += 1;
                tried = true;
            }

            if(r < n - k && l + max(l, r + 1) + r <= m){
                r += 1;
                tried = true;
            }

            if(!tried){
                break;
            }
        }

        cout << l + r + 1 << endl;
    }
}