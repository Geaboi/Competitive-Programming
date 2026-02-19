#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

using namespace std;

int case1(const vector<int>& attack, const vector<int>& defense, const vector<int>& ciel){
    //Attack only case
    int best = 0;
    int m = ciel.size();
    int n = attack.size();

    int damage = 0;

    int i = 0;
    int j = m - 1;

    while(i < n && j >=0 && ciel[j] >= attack[i]){
        damage += ciel[j] - attack[i];
        best = max(best, damage);
        i++;
        j--;
    }



    return best;
}

int case2(const vector<int>& attack, const vector<int>& defense, const vector<int>& ciel){
    vector<int> available(ciel); // sorted copy
    int ciel_used_on_def = 0;
    
    // Assign smallest sufficient Ciel card to each DEF card (need strictly greater)
    for(int d : defense){
        // Find smallest card > d
        auto it = upper_bound(available.begin(), available.end(), d);
        if(it == available.end()) return 0; // can't kill all
        ciel_used_on_def += *it;
        available.erase(it);
    }
    
    // Assign smallest sufficient Ciel card to each ATK card (need >=)
    for(int a : attack){
        auto it = lower_bound(available.begin(), available.end(), a);
        if(it == available.end()) return 0; // can't kill all
        available.erase(it);
    }
    
    // Total damage = sum(ciel) - ciel_used_on_def - sum(atk)
    int sum_ciel = 0;
    for(int c : ciel) sum_ciel += c;
    int sum_atk = 0;
    for(int a : attack) sum_atk += a;
    
    return sum_ciel - ciel_used_on_def - sum_atk;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> attack;
    vector<int> defense;
    int total = 0;

    for(int i = 0; i < n; i++){
        string s;
        cin >> s;

        int strength;
        cin >> strength;
        if(s == "ATK"){
            attack.push_back(strength);
        } else {
            defense.push_back(strength);
        }
    }

    int ciel_total = 0;
    vector<int> ciel(m);
    for(int i = 0; i < m; i++){
        cin >> ciel[i];
    }

    sort(attack.begin(), attack.end());
    sort(defense.begin(), defense.end());
    sort(ciel.begin(), ciel.end());

    cout << max(case1(attack, defense, ciel), case2(attack, defense, ciel)) << endl;
}