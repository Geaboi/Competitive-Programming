#include <bits/stdc++.h>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;

    cin >> s;

    int n = s.size();
    vector<char> minSuffix(n + 1, '~');

    string u = "";

    for(int i = n - 1; i >= 0; i--){
        minSuffix[i] = min(minSuffix[i + 1], s[i]);
    }

    stack<char> st;
    int i = 0;
    while(i < n || !st.empty()){
        if(!st.empty() && (i >= n || st.top() <= minSuffix[i])){
            u += st.top();
            st.pop();
        } else{
            st.push(s[i]);
            i++;
        }

    }

    cout << u << endl;


}