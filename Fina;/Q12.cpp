//Do two bfs Checks
//One BFS check that checks up left down right
//Another that checks up left down right plus diagonals

#include <vector>
#include <iostream>
#include <queue>

using namespace std;

vector<pair<int,int>> directions1 = {{1,0}, {0,1}, {-1,0}, {0,-1}};
vector<pair<int,int>> directions2 = {{1,0}, {0,1}, {-1,0}, {0,-1}, {1,1}, {-1,1},{1,-1}, {-1,-1}};

void bfs1(vector<string>& grid, vector<vector<char>>& seen, int r, int c){
    int rows = grid.size();
    int cols = grid[0].size();

    queue<pair<int,int>> q;
    q.push({r, c});

    while(!q.empty()){
        auto [row, col] = q.front();
        q.pop();

        seen[row][col] = 'm';

        for(auto [dx,dy] : directions1){
            int nr = dx + row;
            int nc = dy + col;

            if(nr < 0 || nr >= rows || nc < 0 || nc >= cols || grid[nr][nc] == '-' || seen[nr][nc] == 'm') continue;

            q.push({nr,nc});
        }
    }
}


void bfs2(vector<string>& grid, vector<vector<char>>& seen, int r, int c){
    int rows = grid.size();
    int cols = grid[0].size();

    queue<pair<int,int>> q;
    q.push({r, c});

    while(!q.empty()){
        auto [row, col] = q.front();
        q.pop();

        seen[row][col] = 't';

        for(auto [dx,dy] : directions2){
            int nr = dx + row;
            int nc = dy + col;

            if(nr < 0 || nr >= rows || nc < 0 || nc >= cols || grid[nr][nc] == '-' || seen[nr][nc] == 't') continue;

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

    vector<vector<char>> visited(n, vector<char>(m,'f'));


    int maxAstroids = 0;
    int leastAstroids = 0;
    for(int row = 0; row < n; row++){
        for(int col = 0; col < m; col++){
            if(grid[row][col] == 'X'){
                if(visited[row][col] == 'f' || visited[row][col] == 't'){
                    bfs1(grid, visited, row, col);
                    maxAstroids++;
                }

                if(visited[row][col] == 'm'){
                    bfs2(grid,visited, row, col);
                    leastAstroids++;
                }
            }
        }
    }

    cout << leastAstroids << " " << maxAstroids << endl;
}
