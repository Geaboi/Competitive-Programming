#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

long long mod(long long x) {
    return ((x % MOD) + MOD) % MOD;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<int> L(n+1), R(n+1), par(n+1, -1);
        // Vertex 0 is the root, its only child is vertex 1
        // We read children for vertices 1..n
        // But the input says: each of the next n lines contains l_i and r_i for vertex i
        // Vertices are 1..n (vertex 0 is root with child 1)

        for(int i = 1; i <= n; i++){
            cin >> L[i] >> R[i];
            if(L[i] != 0) par[L[i]] = i;
            if(R[i] != 0) par[R[i]] = i;
        }
        par[1] = 0; 
        vector<long long> cost(n+1);

        vector<long long> pathsum(n+1);
        
        {
            stack<int> stk;
            stk.push(1);
            vector<bool> visited(n+1, false);
            vector<int> order;
            while(!stk.empty()){
                int v = stk.top(); stk.pop();
                order.push_back(v);
                if(L[v] != 0){
                    stk.push(L[v]);
                    stk.push(R[v]);
                }
            }
            reverse(order.begin(), order.end());
            for(int v : order){
                if(L[v] == 0){
                    // leaf
                    cost[v] = 1;
                } else {
                    cost[v] = (cost[L[v]] + cost[R[v]] + 3) % MOD;
                }
            }
        }


        {
            pathsum[1] = cost[1];
            queue<int> q;
            q.push(1);
            while(!q.empty()){
                int v = q.front(); q.pop();
                if(L[v] != 0){
                    pathsum[L[v]] = (cost[L[v]] + pathsum[v]) % MOD;
                    pathsum[R[v]] = (cost[R[v]] + pathsum[v]) % MOD;
                    q.push(L[v]);
                    q.push(R[v]);
                }
            }
        }

        for(int i = 1; i <= n; i++){
            cout << pathsum[i] << " \n"[i==n];
        }
    }
    return 0;
}