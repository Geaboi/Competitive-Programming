//Point updates so this is a fenwick Tree
//How can I represent this
//3 Fenwick trees
#include <iostream>

#include <vector>

using namespace std;

struct Fenwick{
    int n; 
    vector<long long> top;
    vector<long long> vertical;
    vector<long long> horizontal;

    Fenwick(int n): n(n), top(n , 0), vertical(n + 1, 0) , horizontal(n , 0) {};

    void add(int i, long long delta, int type){
        if(type == 1){
        for(; i <=n; i += i & -i) {
            top[i] += delta;


        }
        }else if(type == 2){
                    for(; i <=n + 1; i += i & -i) {
            vertical[i] += delta;
        }
        }else if(type == 3){
                    for(; i <=n; i += i & -i) {

            horizontal[i] += delta;

        }
        }

    }

    long long sum(int i) {
        long long ans = 0;
        for(; i > 0; i -=i & -i){

            if(top[i] != - 1){
                ans += top[i];
            }
            if(horizontal[i] != - 1){
                ans += horizontal[i];
            }
            if(vertical[i] != - 1){
                ans += vertical[i];
            }
        }

        return ans;
    }

    long long rangeSum(int l, int r){
        return sum(r) - sum(l - 1);
    }
};

int main(){
    int n, q;

    cin >> n >> q;

    Fenwick f(n);

    vector<long long> top;
    vector<long long> vertical;
    vector<long long> horizontal;

    for(int i = 0; i < n; i++){
        int x;
         cin >> x;
         top.push_back(x);
    }

    for(int i = 0; i <= n; i++){
        int x;
        cin >> x;
        vertical.push_back(x);
    }

    for(int i = 0; i < n; i++){
        int x;
         cin >> x;
         horizontal.push_back(x);
    }

    f.top = top;
    f.vertical = vertical;
    f.horizontal = horizontal;

    for(int i = 0; i < q; i++){
    char Q;
    cin >> Q;
        if(Q == 'Q'){
            int l, r;
            cin >> l >> r;
            cout << f.rangeSum(l,r) << '\n';
        }else{
            int type, idx, w;
            cin >> type >> idx >> w;
            f.add(idx, w, type);
        }
    }

    
}