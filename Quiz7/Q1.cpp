#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

int main(){
    int t;

    cin >> t;

    while(t--){
        int n, q;

        cin >> n >> q;

        unordered_map<char, vector<int>> portals;
        unordered_map<int, vector<int>> graph;

        for(int i = 0; i < n; i++){
            string color;
            cin >> color;
            portals[color[0]].push_back(i);
            portals[color[1]].push_back(i);


        }

        for(auto &pair : portals){
            const char color = pair.first;

            for(int city : pair.second){
            }
        }

    }
}