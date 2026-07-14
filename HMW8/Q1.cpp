#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int main(){
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<pair<int, long long>>> graph(n + 1);
    for(int i = 0; i < m; i++){
        int u, v;
        long long x;
        cin >> u >> v >> x;
        graph[u].push_back({v, x});
        graph[v].push_back({u, x});
    }

    vector<pair<int, long long>> trains(k);
    for(int i = 0; i < k; i++){
        cin >> trains[i].first >> trains[i].second;
        graph[1].push_back({trains[i].first, trains[i].second});
        graph[trains[i].first].push_back({1, trains[i].second});
    }

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    vector<bool> visited(n + 1, false);
    vector<long long> dist(n + 1, LLONG_MAX);
    vector<int> road_count(n + 1, 0);

    dist[1] = 0;
    pq.push({0, 1});

    while(!pq.empty()){
        auto [d, u] = pq.top();
        pq.pop();

        if(visited[u]) continue;
        visited[u] = true;

        for(auto [v, w] : graph[u]){
            if(!visited[v]){
                if(d + w < dist[v]){
                    dist[v] = d + w;
                    road_count[v] = 1;
                    pq.push({dist[v], v});
                } else if(d + w == dist[v]){
                    road_count[v]++;
                }
            }
        }
    }

    int res = 0;
    for(int i = 0; i < k; i++){
        int s = trains[i].first;
        long long y = trains[i].second;
        if(y > dist[s]){
            res++;
        } else if(y == dist[s] && road_count[s] > 1){
            res++;
            road_count[s]--;
        }
    }

    cout << res << endl;
}