#include <iostream>
#include <vector>
#include <string>
#include <utility>

using namespace std;

int main(){
    int H, W;
    int x_start, y_start;
    cin >> H >> W >> x_start >> y_start;

    vector<vector<char>> grid(H, vector<char>(W));

    string X;

    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cin >> grid[i][j];
        }
    }

    cin >> X;

    pair<int,int> cur_pos{x_start - 1, y_start - 1};

    for(char c : X){
        if(c == 'L'){
            if(cur_pos.second > 0){
                if(grid[cur_pos.first][cur_pos.second - 1] == '.'){
                    cur_pos = {cur_pos.first, cur_pos.second - 1};
                }
            }
        }else if(c=='R'){
            if(cur_pos.second < W - 1){
                if(grid[cur_pos.first][cur_pos.second + 1] == '.'){
                    cur_pos = {cur_pos.first, cur_pos.second + 1};
                }
            }
        }else if(c=='U'){
            if(cur_pos.first > 0){
                if(grid[cur_pos.first - 1][cur_pos.second] == '.'){
                    cur_pos = {cur_pos.first - 1, cur_pos.second};
                }
            }
        }else if(c=='D'){
            if(cur_pos.first < H - 1){
                if(grid[cur_pos.first + 1][cur_pos.second] == '.'){
                    cur_pos = {cur_pos.first + 1, cur_pos.second};
                }
            }
        }

    }

    cout << cur_pos.first + 1 << " " << cur_pos.second + 1 << endl;

    return 0;
}