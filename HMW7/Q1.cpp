#include <iostream>
#include <vector>
#include <stack>
#include <iomanip>

using namespace std;

vector<vector<int>> adj;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    adj.resize(n + 1);

    for(int i = 0; i < n - 1; i++){
        int from, to;
        cin >> from >> to;
        adj[from].push_back(to);
        adj[to].push_back(from);
    }

    vector<int> parent(n + 1, -1);
    vector<int> order;
    order.reserve(n);

    vector<bool> visited(n + 1, false);
    stack<int> stk;
    stk.push(1);
    visited[1] = true;
    while(!stk.empty()){
        int u = stk.top(); stk.pop();
        order.push_back(u);
        for(int v : adj[u]){
            if(!visited[v]){
                visited[v] = true;
                parent[v] = u;
                stk.push(v);
            }
        }
    }

    vector<double> f(n + 1, 0.0);
    for(int i = (int)order.size() - 1; i >= 0; i--){
        int u = order[i];
        int k = 0;
        double sum = 0;
        for(int v : adj[u]){
            if(v != parent[u]){
                k++;
                sum += f[v];
            }
        }
        if(k > 0)
            f[u] = 1.0 + sum / k;
    }

    cout << fixed << setprecision(15) << f[1] << endl;
    return 0;
}