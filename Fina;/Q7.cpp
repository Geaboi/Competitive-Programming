//I think a DP problem.
// Has to be like coin change where I do W - a or b. Keep going down and take the best answer from that


#include <iostream>
#include <vector>
#include <cmath>


using namespace std;

int top_down(vector<int>& dp, int i, int a, int b, bool used){
    if(i < 0) return INT_MAX;
    if(dp[i] != INT_MAX) return dp[i];

    int one;
    int two;
    if(i - a > 0){
        one = top_down(dp, i - a, a, b, true);

    } else if(i - floor(a / 2) > 0 && used){
        one = top_down(dp, floor(a / 2), a, b, false);

    }


    if(i - b > 0){
        one = top_down(dp, i - b, a, b, true);

    } else if(i - floor(b / 2) > 0 && used){
        one = top_down(dp, i - floor(b / 2), a, b, false);

    }

    dp[i] = min(one, two);
    return dp[i];
}


int main(){
    int w;
    int a, b;
    cin >> w >> a >> b;

    vector<int> dp(w + 1, INT_MAX);


    top_down(dp, w, a, b, true);

    cout << w - (dp[w] - 1) << endl;
}