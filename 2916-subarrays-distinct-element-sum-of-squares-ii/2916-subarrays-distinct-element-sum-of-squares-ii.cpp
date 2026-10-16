class Solution {
private:
    vector<long long> tree_sum;
    vector<long long> tree_sq;
    vector<long long> lazy;
    const long long MOD = 1e9 + 7;

    void push_down(int node, int start, int end) {
        if (lazy[node] == 0) return;

        long long val = lazy[node];
        int mid = start + (end - start) / 2;
        int left_child = 2 * node;
        int right_child = 2 * node + 1;

        // Left child updates
        long long left_len = mid - start + 1;
        tree_sq[left_child] = (tree_sq[left_child] + 2 * val * tree_sum[left_child] + val * val % MOD * left_len) % MOD;
        tree_sum[left_child] = (tree_sum[left_child] + val * left_len) % MOD;
        lazy[left_child] = (lazy[left_child] + val) % MOD;

        // Right child updates
        long long right_len = end - mid;
        tree_sq[right_child] = (tree_sq[right_child] + 2 * val * tree_sum[right_child] + val * val % MOD * right_len) % MOD;
        tree_sum[right_child] = (tree_sum[right_child] + val * right_len) % MOD;
        lazy[right_child] = (lazy[right_child] + val) % MOD;

        lazy[node] = 0;
    }

    void update(int node, int start, int end, int l, int r, long long val) {
        if (l <= start && end <= r) {
            long long segment_len = end - start + 1;
            tree_sq[node] = (tree_sq[node] + 2 * val * tree_sum[node] + val * val % MOD * segment_len) % MOD;
            tree_sum[node] = (tree_sum[node] + val * segment_len) % MOD;
            lazy[node] = (lazy[node] + val) % MOD;
            return;
        }

        push_down(node, start, end);
        int mid = start + (end - start) / 2;
        if (l <= mid) {
            update(2 * node, start, mid, l, r, val);
        }
        if (r > mid) {
            update(2 * node + 1, mid + 1, end, l, r, val);
        }

        tree_sum[node] = (tree_sum[2 * node] + tree_sum[2 * node + 1]) % MOD;
        tree_sq[node] = (tree_sq[2 * node] + tree_sq[2 * node + 1]) % MOD;
    }

public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        
        tree_sum.assign(4 * n, 0);
        tree_sq.assign(4 * n, 0);
        lazy.assign(4 * n, 0);

        long long total_ans = 0;
        unordered_map<int, int> last_seen;

        for (int j = 0; j < n; ++j) {
            int i_start = (last_seen.find(nums[j]) != last_seen.end()) ? last_seen[nums[j]] + 1 : 0;
            int i_end = j;

            update(1, 0, n - 1, i_start, i_end, 1);
            total_ans = (total_ans + tree_sq[1]) % MOD;
            last_seen[nums[j]] = j;
        }

        return (total_ans + MOD) % MOD;
    }
};
