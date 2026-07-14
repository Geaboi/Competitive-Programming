#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
 
using namespace std;
 
// Each node stores the state of brackets in its specific range
struct Node {
    int ans;            // Length of correct bracket subsequence (pairs * 2)
    int unmatchedOpen;  // Number of '(' that haven't been matched
    int unmatchedClosed; // Number of ')' that haven't been matched
 
    Node() : ans(0), unmatchedOpen(0), unmatchedClosed(0) {}
};
 
// The core logic: combining two range summaries into one
Node merge(const Node& left, const Node& right) {
    Node parent;
    
    // Find how many new pairs are formed by matching left '(' with right ')'
    int newMatches = min(left.unmatchedOpen, right.unmatchedClosed);
    
    parent.ans = left.ans + right.ans + 2 * newMatches;
    parent.unmatchedOpen = left.unmatchedOpen + right.unmatchedOpen - newMatches;
    parent.unmatchedClosed = left.unmatchedClosed + right.unmatchedClosed - newMatches;
    
    return parent;
}
 
vector<Node> tree;
string s;
 
// Recursively builds the tree in O(N)
void build(int node, int start, int end) {
    if (start == end) {
        if (s[start] == '(') {
            tree[node].unmatchedOpen = 1;
        } else {
            tree[node].unmatchedClosed = 1;
        }
        return;
    }
    
    int mid = (start + end) / 2;
    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);
    
    tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
}
 
// Queries a range [L, R] in O(log N)
Node query(int node, int start, int end, int L, int R) {
    // 1. No overlap
    if (R < start || end < L) {
        return Node();
    }
    // 2. Total overlap
    if (L <= start && end <= R) {
        return tree[node];
    }
    // 3. Partial overlap
    int mid = (start + end) / 2;
    Node leftRes = query(2 * node, start, mid, L, R);
    Node rightRes = query(2 * node + 1, mid + 1, end, L, R);
    
    return merge(leftRes, rightRes);
}
 
int main() {
    // Faster I/O for 10^5 queries
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    if (!(cin >> s)) return 0;
    int n = s.size();
    
    tree.resize(4 * n + 1);
    build(1, 0, n - 1);
    
    int m;
    cin >> m;
    while (m--) {
        int l, r;
        cin >> l >> r;
        // Queries are 1-indexed in the problem, convert to 0-indexed
        Node result = query(1, 0, n - 1, l - 1, r - 1);
        cout << result.ans << "\n";
    }
    
    return 0;
}