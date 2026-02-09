#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n; long long m;
        scanf("%d%lld",&n,&m);
        vector<int> a(n+1);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        

        vector<int> sorted_a(a.begin()+1, a.end()); 
        
        vector<pair<int,int>> va(n);
        for(int i=0;i<n;i++) va[i]={a[i+1], i+1};
        sort(va.begin(), va.end());
        
        vector<long long> prefix(n+1, 0);
        for(int i=0;i<n;i++) prefix[i+1] = prefix[i] + va[i].first;
        
        vector<int> pos_in_sorted(n+1); 
        for(int i=0;i<n;i++) pos_in_sorted[va[i].second] = i;
        auto cheapest = [&](int j, int idx) -> long long {
            if(j <= 0) return 0;
            if(idx < 1 || idx > n) return prefix[j]; 
            int p = pos_in_sorted[idx];
            if(p < j) {
                if(j+1 <= n)
                    return prefix[j+1] - a[idx];
                else
                    return (long long)1e18; 
            } else {
                return prefix[j];
            }
        };
        
        int best_place = n+1; 
        
        for(int k=0; k<=n; k++){
            if(k+1 <= n){
                long long cost;
                if(k == 0){
                    cost = a[k+1];
                } else {
                    cost = a[k+1] + cheapest(k-1, k+1);
                }
                if(cost <= m){
                    int place = n - k - 1 + 1;
                    best_place = min(best_place, place);
                }
            }
            
            {
                long long cost;
                int above;
                if(k+1 <= n){
                    cost = cheapest(k, k+1);
                    above = n - k; 
                } else {
                    cost = prefix[n];
                    above = 0;
                }
                if(cost <= m){
                    int place = above + 1;
                    best_place = min(best_place, place);
                }
            }
        }
        
        printf("%d\n", best_place);
    }
}