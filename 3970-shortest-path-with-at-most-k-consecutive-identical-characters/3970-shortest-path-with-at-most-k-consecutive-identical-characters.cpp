class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        // Build adjacency list: adj[u] = {{v1, w1}, {v2, w2}, ...}
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v, w});
        }

        // dist[u][cur] stores the min weight to reach node u with a trailing run of 'cur' identical characters
        const int INF = 1e9 + 7;
        vector<vector<int>> dist(n, vector<int>(k + 1, INF));

        // Min-heap tracking: {current_total_weight, node, current_consecutive_run}
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

        // Initialize state for the starting node (0)
        dist[0][1] = 0;
        pq.push({0, 0, 1});

        while (!pq.empty()) {
            auto [d, u, cur] = pq.top();
            pq.pop();

            // Return the first time we pop the destination node
            if (u == n - 1) {
                return d;
            }

            // Skip processed or worse states
            if (d > dist[u][cur]) {
                continue;
            }

            // Relax edges
            for (const auto& [v, w] : adj[u]) {
                // If label matches, run increments; otherwise it resets to 1
                int nxt = (labels[v] == labels[u]) ? cur + 1 : 1;

                // Move forward if the consecutive character rule isn't violated
                if (nxt <= k && d + w < dist[v][nxt]) {
                    dist[v][nxt] = d + w;
                    pq.push({dist[v][nxt], v, nxt});
                }
            }
        }

        return -1;
    }
};