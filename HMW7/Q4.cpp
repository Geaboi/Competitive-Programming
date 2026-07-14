class Solution {
public:
    void dfs(vector<vector<char>>& grid, int& islands, set<pair<int,int>>& seen,int row,int col){
        seen.insert({row,col});
        stack<pair<int,int>> s;
        s.push({row,col});
        while(!s.empty()){
            auto [r, c] = s.top();
            s.pop();

            int directions[4][2] = {
                {r + 1, c},
                {r - 1, c},
                {r, c + 1},
                {r, c - 1}
            };

            for(auto d: directions){
                if(d[0] < 0 || d[0] >= grid.size()) continue;

                if(d[1] < 0 || d[1] >= grid[0].size()) continue;

                if(grid[d[0]][d[1]] == '0' || seen.contains({d[0],d[1]})) continue;

                s.push({d[0],d[1]});
                seen.insert({d[0],d[1]});
            }

        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
        set<pair<int,int>> seen;
        int rows = grid.size();
        int cols = grid[0].size();

        for(int i = 0 ; i < rows ; i++){
            for(int j = 0; j < cols ; j++){
                if(seen.contains({i, j}) || grid[i][j] == '0') continue;

                dfs(grid, islands, seen, i, j);
                islands++;
            }
        }
        return islands;
    }
};