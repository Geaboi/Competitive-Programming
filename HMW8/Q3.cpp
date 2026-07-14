class Solution
{
    int timer = 1;
    void dfs(int node, int parent, vector<int> &time, vector<int> &low,
             vector<bool> &vis, vector<vector<int>> &adj, vector<vector<int>> &bridges)
    {
        vis[node] = true;
        time[node] = low[node] = timer++;
        for (auto it : adj[node])
        {
            if (it == parent)
                continue;
            if (!vis[it])
            {
                dfs(it, node, time, low, vis, adj, bridges);
                low[node] = min(low[node], low[it]);
                if (low[it] > time[node])
                {
                    bridges.push_back({it, node});
                }
            }
            else
            {
                low[node] = min(low[node], time[it]);
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
    {
        vector<vector<int>> adj(n);
        for (auto it : connections)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> time(n), low(n);
        vector<bool> vis(n, false);
        vector<vector<int>> bridges;
        dfs(0, -1, time, low, vis, adj, bridges);
        return bridges;
    }
};