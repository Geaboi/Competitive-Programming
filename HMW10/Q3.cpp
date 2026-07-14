class TrieNode {
    public:
    int indx;
    TrieNode* children[26];

    TrieNode() {
        indx = -1;
        for(int i = 0; i < 26; i++){
            children[i] = nullptr;
        }
    }

    void addWord(string& word, int i){
        TrieNode *cur = this;

        for(auto w: word){
            int index = w - 'a';
            if(!cur->children[index]) cur->children[index] = new TrieNode();

            cur = cur->children[w - 'a'];
        }

        cur->indx = i;
    }
};
 


class Solution {
public:
    vector<string> res;

    void backtrack(TrieNode* cur, int row, int col, vector<vector<char>>& board, vector<string>& words){
        //Base Case
        if(row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || board[row][col] == '*' || !cur->children[board[row][col] - 'a'] ) return;

        //Add solution


        char temp = board[row][col];
        board[row][col] = '*';
        TrieNode* node = cur->children[temp - 'a'];

        if(node->indx != -1){
            res.push_back(words[node->indx]);
            node->indx = -1;
            
        }

        backtrack(node, row + 1, col, board, words);
        backtrack(node, row - 1, col, board, words);
        backtrack(node, row, col + 1, board, words);
        backtrack(node, row, col - 1, board, words);

        board[row][col] = temp;
        return;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        for(int i = 0; i < words.size(); i++){
            root->addWord(words[i],i);
        }

        for(int r = 0; r < board.size(); r++){
            for(int c = 0; c < board[0].size(); c++){
                backtrack(root, r, c, board, words);
            }
        }
        return res;
    }
};