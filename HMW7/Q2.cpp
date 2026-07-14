#include <vector>
#include <iostream>
#include <functional>
#include <map>
#include <numeric>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n+1), indeg(n+1, 0);
        vector<int> par(n+1);
        iota(par.begin(), par.end(), 0);
        
        function<int(int)> fnd = [&](int x){
            return par[x] == x ? x : par[x] = fnd(par[x]);
        };
        auto unite = [&](int x, int y){
            x = fnd(x); y = fnd(y);
            if(x != y) par[x] = y;
        };
        
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            unite(i, a[i]);
            indeg[a[i]]++;
        }
        
        map<int, int> comp_size;
        map<int, bool> comp_has_bad;
        
        for(int i = 1; i <= n; i++){
            int r = fnd(i);
            comp_size[r]++;
            if(indeg[i] != 1) comp_has_bad[r] = true;
        }
        
        int b = 0, c = 0;
        for(auto& [r, sz] : comp_size){
            bool is_cycle = !comp_has_bad.count(r) && sz >= 3;
            if(is_cycle) c++;
            else b++;
        }
        
        cout << c + min(b, 1) << " " << c + b << "\n";
    }
}