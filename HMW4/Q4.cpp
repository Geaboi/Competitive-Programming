#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--){
        int n, k;

        cin >> n >> k;

        vector<int> arr(n);
        bool k_exists = false;
        for(int i = 0; i < n; i++){
            cin >> arr[i];
            if(arr[i] == k){
                k_exists = true;
            }
        }

        if(!k_exists){
            cout << "no" << endl;
            continue;
        }

        if(n == 1){
            cout << "yes" << endl;
            continue;
        }

        bool found = false;
        int last = -1;
        for(int i = 0; i < n; i++){
            if(arr[i] >= k && last != -1){

                if(i - last <= 2){
                    found = true;
                    break;
                }else{
                    last = i;
                }
            }else if(arr[i] >= k){
                last = i;
            }
        }

        if(found){
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }

    }


}