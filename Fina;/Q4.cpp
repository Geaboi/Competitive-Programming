//DP plust bit manipulation
//We have to check every possible combination + caching
//For the unlocking we just take the ~ of the unlocking pattern and AND it with the original pattern
// For locking we just take the OR 
//Now we need to be able to determine the best path.
// 1d problem 
// Our goal is 0 and we start at whatever number 10011 is at 35
//Min number of time
//

#include <iostream>
#include <vector>

using namespace std;

struct Tool{
    public:
    int time;
    int unlock;
    int lock;

    Tool(int time, int unlock, int lock){
        this->time = time;
        this->unlock = unlock;
        this->lock = lock;
    }
};

void top_down(vector<int>& dp, vector<Tool>& tools, int state){
    return;
}

void solve(){
    int n, m;

    cin >> n, m;

    //convert n to an int representation
    string temp;
    cin >> temp;
    int state;

    for(char c : temp){
        if(c == '1'){
            state | 1;
        }
        state << 1;
    }

    vector<Tool> tools;
    for(int i = 0; i < m; i++){
        int time, unlock, lock;

        cin >> time >> unlock >> lock;

        tools.push_back(Tool(time,~(unlock), lock));
    }


    vector<int> dp(state, -1);

    
    



    cout << dp[0] << endl;
}

int main(){
    int t;
    cin >> t;

    while(t--){
        solve();
    }


}