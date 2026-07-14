#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
int n;
string s;
int tree[4 * MAXN];

void build(int node, int start, int end) {
    if (start == end) {
        tree[node] = 1 << (s[start] - 'a');
        return;
    }
    int mid = (start + end) / 2;
    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);
    tree[node] = tree[2 * node] | tree[2 * node + 1];
}

void update(int node, int start, int end, int pos, char c) {
    if (start == end) {
        tree[node] = 1 << (c - 'a');
        return;
    }
    int mid = (start + end) / 2;
    if (pos <= mid)
        update(2 * node, start, mid, pos, c);
    else
        update(2 * node + 1, mid + 1, end, pos, c);
    tree[node] = tree[2 * node] | tree[2 * node + 1];
}

int query(int node, int start, int end, int l, int r) {
    if (r < start || end < l) return 0;
    if (l <= start && end <= r) return tree[node];
    int mid = (start + end) / 2;
    return query(2 * node, start, mid, l, r) | query(2 * node + 1, mid + 1, end, l, r);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s;
    n = s.size();
    build(1, 0, n - 1);

    int q;
    cin >> q;
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int pos;
            char c;
            cin >> pos >> c;
            update(1, 0, n - 1, pos - 1, c);
        } else {
            int l, r;
            cin >> l >> r;
            cout << __builtin_popcount(query(1, 0, n - 1, l - 1, r - 1)) << "\n";
        }
    }

    return 0;
}