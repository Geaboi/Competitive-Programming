//Lets just make everything equal.
//Or K?

//Seems easy for DP tbh lol

//Can I make them even or as close as possible with the resources I have
//Two choices either take or use from my pouch depending on resources avaliable

//I can check for this
//if |hi - h(i+1)| + m = k use m exactly
//also then
//If hi > h(i + 1) Just take until its even keep it.


#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--){
        long long n, m, k;
        cin >> n >> m >> k;

        vector<long long> heights(n,0);

        for(int i = 0; i < n; i++){
            cin >> heights[i];
        }

        bool possible = true;
        for(int i = 0; i < n - 1; i++){
            int need = max(0LL, heights[i + 1] - k);

            if(heights[i] + m >= need){
                m += heights[i] - need;
            }else{
                possible = false;
                break;
            }
        }

        if(possible){
            cout << "YES \n";
        }else{
            cout << "NO \n";
        }
    
    }


}