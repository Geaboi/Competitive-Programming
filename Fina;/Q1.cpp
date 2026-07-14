//Do two bfs Checks
//One BFS check that checks up left down right
//Another that checks up left down right plus diagonals

#include <vector>
#include <iostream>
#include <queue>

using namespace std;

vector<pair<int,int>> directions1 = {{1,0}, {0,1}, {-1,0}, {0,-1}};
vector<pair<int,int>> directions2 = {{1,0}, {0,1}, {-1,0}, {0,-1}, {1,1}, {-1,1},{1,-1}, {-1,-1}};

void bfs1(vector<string>& grid, vector<vector<bool>>& seen, int r, int c){
    int rows = grid.size();
    int cols = grid[0].size();

    queue<pair<int,int>> q;
    q.push({r, c});

    while(!q.empty()){
        auto [row, col] = q.front();
        q.pop();

        seen[row][col] = true;

        for(auto [dx,dy] : directions1){
            int nr = dx + row;
            int nc = dy + col;

            if(nr < 0 || nr >= rows || nc < 0 || nc >= cols || grid[nr][nc] == '-' || seen[nr][nc] ) continue;

            q.push({nr,nc});
        }
    }
}


void bfs2(vector<string>& grid, vector<vector<bool>>& seen, int r, int c){
    int rows = grid.size();
    int cols = grid[0].size();

    queue<pair<int,int>> q;
    q.push({r, c});

    while(!q.empty()){
        auto [row, col] = q.front();
        q.pop();

        seen[row][col] = true;

        for(auto [dx,dy] : directions2){
            int nr = dx + row;
            int nc = dy + col;

            if(nr < 0 || nr >= rows || nc < 0 || nc >= cols || grid[nr][nc] == '-' || seen[nr][nc] ) continue;

            q.push({nr,nc});
        }
    }
}


int main() {
    int n, m;

    cin >> n >> m;


    vector<string> grid(n);
    for(int i = 0; i < n; i++){
        cin >> grid[i];
    }

    vector<vector<bool>> visited1(n, vector<bool>(m,false));

    vector<vector<bool>> visited2(n, vector<bool>(m,false));

    int maxAstroids = 0;
    int leastAstroids = 0;
    for(int row = 0; row < n; row++){
        for(int col = 0; col < m; col++){
            if(grid[row][col] == 'X'){
                if(!visited1[row][col]){
                    bfs1(grid, visited1, row, col);
                    maxAstroids++;
                }

                if(!visited2[row][col]){
                    bfs2(grid,visited2, row, col);
                    leastAstroids++;
                }
            }
        }
    }

    cout << leastAstroids << " " << maxAstroids << endl;
}
