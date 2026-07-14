//Nested Segments

#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

class SegmentTree {
public:
    SegmentTree(int n) {
        this->n = n;
        tree.resize(4 * n, 0);
    }

    void update(int pos, int val) {
        update(1, 0, n - 1, pos, val);
    }

    int query(int l, int r) {
        if (l > r) return 0;
        return query(1, 0, n - 1, l, r);
    }

private:
    vector<int> tree;
    int n;

    void update(int node, int start, int end, int pos, int val) {
        if (start == end) {
            tree[node] += val;
            return;
        }
        int mid = (start + end) / 2;
        if (pos <= mid) {
            update(2 * node, start, mid, pos, val);
        } else {
            update(2 * node + 1, mid + 1, end, pos, val);
        }
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    int query(int node, int start, int end, int l, int r) {
        if (r < start || l > end) return 0;
        if (l <= start && end <= r) return tree[node];
        int mid = (start + end) / 2;
        return query(2 * node, start, mid, l, r)
             + query(2 * node + 1, mid + 1, end, l, r);
    }
};


int main(){
    int n;
    cin >> n;

    SegmentTree st(n);


    vector<tuple<int,int,int>> segs(n);
    vector<int> rights(n);

    for(int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;

        segs[i] = {l,r,i};
        rights[i] = r;
    }

    sort(rights.begin(), rights.end());

    for(int i = 0; i < n; i++){
        int r = get<1>(segs[i]);
        int rank = lower_bound(rights.begin(), rights.end(), r) - rights.begin();
        get<1>(segs[i]) = rank;
}

    sort(segs.begin(), segs.end());
    vector<int> answer(n);

    for(int i = n - 1; i >= 0; i--){
        int rank = get<1>(segs[i]);
        int orig = get<2>(segs[i]);
        answer[orig] = st.query(0, rank - 1);
    
        st.update(rank, 1);
    }

    for (int i = 0; i < n; i++) {
        cout << answer[i] << "\n";
    }

}