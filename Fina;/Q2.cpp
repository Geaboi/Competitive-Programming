// a
// b

//   a
//  b b
// a   b
#include <unordered_map>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

struct TrieNode {
    unordered_map<char, TrieNode*> children;
    string word;
};

struct Trie {
    TrieNode* root = new TrieNode();

    void insert(string& word){
        TrieNode* cur = root;

        for(char ch: word){
            if(!cur->children.count(ch)) cur->children[ch]= new TrieNode();

            cur = cur->children[ch];
        }

        cur->word = word;
    }
};

pair<bool,bool> dfs(TrieNode* node){
    if(node->children.empty()) return {false,true};
    bool win = false, lose = false;

    for(auto& [ch,child] : node->children){
        auto [cw,cl] = dfs(child);
        if(!cw) win = true;
        if(!cl) lose = true;

    }
    
    return{win,lose};

}

void Game(TrieNode* node){
    int canWins, canLoses;
    canWins = 0;
    canLoses = 0;
    
    for(auto& [ch,child] : node->children){
        auto [cw,cl] = dfs(child);

        if(cw && !cl) canLoses++;
        if(!cw && cl) canWins++;
    }

    int total = canWins + canLoses;

    cout << double(canWins) / double(total) << " " << double(canLoses) / double(total) << endl;
}

int main(){
    int n;
    cin >> n;

    Trie t;

    for(int i = 0; i < n; i++){
        string temp;
        cin >> temp;
        t.insert(temp);
    }

    TrieNode* root = t.root;

    Game(root);

    
}