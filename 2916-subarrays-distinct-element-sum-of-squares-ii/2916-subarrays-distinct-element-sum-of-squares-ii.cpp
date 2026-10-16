class LazySegmentTree {
public:
    int n;
    long long kMod = 1e9 + 7;
    vector<long long> lazy, sums, squaredSums;

    LazySegmentTree(int n) : n(n){
        lazy.resize(4 * n, 0);
        sums.resize(4 * n, 0);
        squaredSums.resize(4 * n, 0);
    }

    void propagate(int i, int l, int r){
        long long gap = r - l + 1;

        squaredSums[i] = (
            squaredSums[i]
            + 2 * lazy[i] * sums[i]
            + lazy[i] * lazy[i] * gap
        ) % kMod;

        sums[i] = (sums[i] + lazy[i] * gap) % kMod;

        if (l < r){ 
            lazy[i * 2 + 1] += lazy[i];
            lazy[i * 2 + 2] += lazy[i];
        }
        lazy[i] = 0;
    }

    void updateRange(int l, int r){
        updateRange(0, 0, n - 1, l, r);
    }

    long long getTreeSquaredSums(){
        return squaredSums[0];
    }

private:
    void updateRange(int i, int start, int end, int l, int r){
        if (lazy[i] > 0)
            propagate(i, start, end);

        if (end < l || start > r)
            return;

        if (start >= l && end <= r) {
            lazy[i] = 1;
            propagate(i, start, end);
            return;
        }

        int mid = (start + end) / 2;

        updateRange(i * 2 + 1, start, mid, l, r);
        updateRange(i * 2 + 2, mid + 1, end, l, r);

        sums[i] = (sums[i * 2 + 1] + sums[i * 2 + 2]) % kMod;

        squaredSums[i] = (
            squaredSums[i * 2 + 1] + squaredSums[i * 2 + 2]
        ) % kMod;
    }
};

class Solution {
public:
    int sumCounts(vector<int>& nums) {
        const int n = nums.size();
        const int kMod = 1e9 + 7;

        long long ans = 0;
        unordered_map<int, int> lastSeen;
        LazySegmentTree tree(n);

        for (int r = 0; r < n; r++) {
            int l = lastSeen.count(nums[r])
                ? lastSeen[nums[r]] + 1
                : 0;

            tree.updateRange(l, r);
            lastSeen[nums[r]] = r;

            ans = (ans + tree.getTreeSquaredSums()) % kMod;
        }
        return ans;
    }
};