class Solution {
public:

class SegmentTree {
    struct Node {
        int leftVal;   // value at left end
        int rightVal;  // value at right end

        int pref;      // longest same-value prefix
        int suff;      // longest same-value suffix
        int best;      // longest same-value subarray

        int len;       // length of segment
    };

    vector<Node> tree;
    vector<int> arr;

    // Merge two children
    Node merge(Node left, Node right) {

        // If one side doesn't exist
        if (left.len == 0) return right;
        if (right.len == 0) return left;

        Node res;

        res.len = left.len + right.len;

        res.leftVal = left.leftVal;
        res.rightVal = right.rightVal;

        // Initially, best is maximum from either side
        res.best = max(left.best, right.best);

        // Prefix
        res.pref = left.pref;

        if (left.pref == left.len &&
            left.rightVal == right.leftVal) {
            res.pref = left.len + right.pref;
        }

        // Suffix
        res.suff = right.suff;

        if (right.suff == right.len &&
            left.rightVal == right.leftVal) {
            res.suff = right.len + left.suff;
        }

        // Run crossing the boundary
        if (left.rightVal == right.leftVal) {
            res.best = max(
                res.best,
                left.suff + right.pref
            );
        }

        return res;
    }

    void build(int node, int l, int r) {

        if (l == r) {
            tree[node] = {
                arr[l],  // leftVal
                arr[l],  // rightVal
                1,       // pref
                1,       // suff
                1,       // best
                1        // len
            };

            return;
        }

        int mid = l + (r - l) / 2;

        build(2 * node, l, mid);
        build(2 * node + 1, mid + 1, r);

        tree[node] = merge(
            tree[2 * node],
            tree[2 * node + 1]
        );
    }

    void update(int node, int l, int r, int idx, int val) {

        if (l == r) {
            tree[node] = {
                val,
                val,
                1,
                1,
                1,
                1
            };

            return;
        }

        int mid = l + (r - l) / 2;

        if (idx <= mid) {
            update(2 * node, l, mid, idx, val);
        } else {
            update(2 * node + 1, mid + 1, r, idx, val);
        }

        tree[node] = merge(
            tree[2 * node],
            tree[2 * node + 1]
        );
    }

public:

    SegmentTree(vector<int>& a) {

        arr = a;

        int n = a.size();

        tree.resize(4 * n);

        build(1, 0, n - 1);
    }

    // Change a[index] = value
    void update(int index, int value) {

        update(1, 0, arr.size() - 1, index, value);
    }

    // Longest continuous sequence
    int getLongest() {
        return tree[1].best;
    }
};
    vector<int> longestRepeating(string s, string &qc, vector<int>& q) {
        vector<int>temp;
        for(auto c : s) {
            temp.push_back(c-'a');
        }

        SegmentTree st(temp);

        vector<int>ans;

        for(int i = 0; i < q.size(); i++) {
            int val = qc[i]-'a';
            int idx = q[i];
            st.update(idx, val);
            ans.push_back(st.getLongest());
        }
        return ans;
    }
};