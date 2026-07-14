#include <iostream>
#include <vector>

using namespace std;

// Each node stores the bitwise AND of its range (val)
// and a pending bitwise OR update (lazy).
struct Node {
    int val;
    int lazy;
};

class SegmentTree {
    int n;
    vector<Node> tree;

public:
    SegmentTree(int n) : n(n) {
        tree.assign(4 * n + 1, {0, 0});
    }

    void push(int node, int start, int end) {
        if (tree[node].lazy == 0) return;

        // If every element in a range is OR-ed with 'lazy', 
        // the AND result of that range is also OR-ed with 'lazy'.
        tree[node].val |= tree[node].lazy;

        if (start != end) {
            tree[2 * node].lazy |= tree[node].lazy;
            tree[2 * node + 1].lazy |= tree[node].lazy;
        }
        tree[node].lazy = 0;
    }

    void update(int node, int start, int end, int l, int r, int q) {
        push(node, start, end);
        if (start > end || start > r || end < l) return;

        if (start >= l && end <= r) {
            tree[node].lazy |= q;
            push(node, start, end);
            return;
        }

        int mid = (start + end) / 2;
        update(2 * node, start, mid, l, r, q);
        update(2 * node + 1, mid + 1, end, l, r, q);
        tree[node].val = tree[2 * node].val & tree[2 * node + 1].val;
    }

    int query(int node, int start, int end, int l, int r) {
        push(node, start, end);
        if (start > end || start > r || end < l) {
            return (1 << 30) - 1; // Neutral element for AND
        }

        if (start >= l && end <= r) {
            return tree[node].val;
        }

        int mid = (start + end) / 2;
        return query(2 * node, start, mid, l, r) & 
               query(2 * node + 1, mid + 1, end, l, r);
    }
};

struct Constraint {
    int l, r, q;
};

int main() {
    // Fast I/O is necessary for 10^5 operations
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<Constraint> constraints(m);
    SegmentTree st(n);

    // Step 1: Construction phase (Range OR)
    for (int i = 0; i < m; ++i) {
        cin >> constraints[i].l >> constraints[i].r >> constraints[i].q;
        st.update(1, 1, n, constraints[i].l, constraints[i].r, constraints[i].q);
    }

    // Step 2: Verification phase (Range AND)
    bool possible = true;
    for (int i = 0; i < m; ++i) {
        if (st.query(1, 1, n, constraints[i].l, constraints[i].r) != constraints[i].q) {
            possible = false;
            break;
        }
    }

    // Step 3: Output Result
    if (possible) {
        cout << "YES" << "\n";
        for (int i = 1; i <= n; ++i) {
            cout << st.query(1, 1, n, i, i) << (i == n ? "" : " ");
        }
        cout << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}