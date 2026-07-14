#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

struct Node {
    int ones, zeros;
};

int n;
string s;
Node tree[4 * MAXN];

Node merge(Node L, Node R) {
    int matched = min(L.zeros, R.ones);
    return {L.ones + R.ones - matched, L.zeros + R.zeros - matched};
}

Node makeLeaf(char c) {
    if (c == '1') return {1, 0};
    return {0, 1};
}

void build(int node, int start, int end) {
    if (start == end) {
        tree[node] = makeLeaf(s[start]);
        return;
    }
    int mid = (start + end) / 2;
    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);
    tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
}

void update(int node, int start, int end, int pos) {
    if (start == end) {
        s[pos] = (s[pos] == '0' ? '1' : '0');
        tree[node] = makeLeaf(s[pos]);
        return;
    }
    int mid = (start + end) / 2;
    if (pos <= mid)
        update(2 * node, start, mid, pos);
    else
        update(2 * node + 1, mid + 1, end, pos);
    tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
}

Node query(int node, int start, int end, int l, int r) {
    if (l <= start && end <= r) return tree[node];
    int mid = (start + end) / 2;
    if (r <= mid) return query(2 * node, start, mid, l, r);
    if (l > mid) return query(2 * node + 1, mid + 1, end, l, r);
    return merge(query(2 * node, start, mid, l, r),
                 query(2 * node + 1, mid + 1, end, l, r));
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
            int x;
            cin >> x;
            update(1, 0, n - 1, x - 1);
        } else {
            int l, r;
            cin >> l >> r;
            Node res = query(1, 0, n - 1, l - 1, r - 1);
            cout << res.ones + res.zeros << "\n";
        }
    }

    return 0;
}