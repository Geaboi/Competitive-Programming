#include <bits/stdc++.h>
#include <string>

using namespace std;

int main () {
    string str;
    cin >> str;

    stack<char> s;
    for (char & c : str){
        if(s.empty()){
            s.push(c);
        }else{
            if(s.top() == c){
                s.pop();
            }else{
                s.push(c);
            }
        }
    }

    int moves = (str.length() - s.size()) / 2;
    
    if(moves % 2 == 1){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }

    return 0;
}