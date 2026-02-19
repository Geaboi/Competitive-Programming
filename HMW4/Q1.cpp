#include <vector>
#include <iostream>
#include <set>

using namespace std;
int main() {
    int n;
    
    cin >> n;
    vector<int> a(n);
    for(int i = 0 ; i < n; i++){
        cin >> a[i];
    }

    int min_removed = n;

    set<int> prefix_elements;
    for(int i = 0; i <= n; i++){
        if(i > 0){
            if(prefix_elements.count(a[i - 1]) > 0){
                break;
            }
            prefix_elements.insert(a[i - 1]);
        }

        set<int> combined = prefix_elements;
        int suffix_start = n;
        for(int j = n - 1; j >= i; j--){
            if(combined.count(a[j]) > 0){
                break;
            }
            combined.insert(a[j]);
            suffix_start = j;
        }
        min_removed = min(min_removed, suffix_start - i);
    }
    cout << min_removed << endl;
}