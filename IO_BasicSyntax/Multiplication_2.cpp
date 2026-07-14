#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    bool hasZero = false;

    int n;
    cin >> n;

    vector<long long> arr(n);

    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if(arr[i] == 0){
            std::cout << "0" << std::endl;
            return 0;
        }
    }


    long long res{1};
    long long overflow = 1e18;
    for(int i = 0; i < n; i++){

        if(arr[i] > overflow / res){
            cout << "-1" << endl;
            return 0;
        }

        res *= arr[i];

    }

    cout << res << endl;

    return 0;
}