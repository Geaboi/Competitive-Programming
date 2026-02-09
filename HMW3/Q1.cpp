#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<int,int>> b;

    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        b.push_back({x,y});
    }

    sort(b.begin(), b.end());

    for(int i = 0; i < n - 1; i++){
        if(b[i].second > b[i + 1].second){
            cout << "Happy Alex" << endl;
            return 0;
        }
    }

    cout << "Poor Alex" << endl;
}