
class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();

        vector<vector<int>> adj(n);

      
        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }

        vector<int> newParent(n);
        newParent[0] = -1;

        vector<int> last(26, -1);

     
        function<void(int)> dfs = [&](int u) {
            int c = s[u] - 'a';

            int previous = last[c];

            if (previous != -1) {
                newParent[u] = previous;
            } else {
                newParent[u] = parent[u];
            }

            last[c] = u;

            for (int v : adj[u]) {
                dfs(v);
            }

            last[c] = previous;
        };

        dfs(0);

        vector<vector<int>> tree(n);

        for (int i = 1; i < n; i++) {
            tree[newParent[i]].push_back(i);
        }

        vector<int> ans(n, 1);

        function<int(int)> calculate = [&](int u) {
            for (int v : tree[u]) {
                ans[u] += calculate(v);
            }

            return ans[u];
        };

        calculate(0);

        return ans;
    }
};
