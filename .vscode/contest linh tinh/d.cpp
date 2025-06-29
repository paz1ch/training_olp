#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

const int MAXN = 100005;
const int LOG = 17; // ceil(log2(MAXN))

struct Edge {
    int u, v, w;
};

int n, q;
vector<Edge> edges;
vector<pair<int, int>> adj[MAXN];
int parent[MAXN][LOG], depth[MAXN], maxWeight[MAXN][LOG];
vector<pair<int, int>> queries; // {l, r}
vector<int> result;

void dfs(int u, int par, int weight) {
    parent[u][0] = par;
    maxWeight[u][0] = weight;
    for (int i = 1; i < LOG; ++i) {
        if (parent[u][i - 1] != -1) {
            parent[u][i] = parent[parent[u][i - 1]][i - 1];
            maxWeight[u][i] = max(maxWeight[u][i - 1], maxWeight[parent[u][i - 1]][i - 1]);
        } else {
            break;
        }
    }

    for (auto &edge : adj[u]) {
        int v = edge.first, w = edge.second;
        if (v != par) {
            depth[v] = depth[u] + 1;
            dfs(v, u, w);
        }
    }
}

int getMaxWeight(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);

    int max_w = 0;
    int diff = depth[u] - depth[v];
    for (int i = 0; i < LOG; ++i) {
        if ((diff >> i) & 1) {
            max_w = max(max_w, maxWeight[u][i]);
            u = parent[u][i];
        }
    }

    if (u == v) return max_w;

    for (int i = LOG - 1; i >= 0; --i) {
        if (parent[u][i] != parent[v][i]) {
            max_w = max({max_w, maxWeight[u][i], maxWeight[v][i]});
            u = parent[u][i];
            v = parent[v][i];
        }
    }
    return max({max_w, maxWeight[u][0], maxWeight[v][0]});
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> q;

    edges.resize(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = {u, v, w};
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    queries.resize(q);
    for (int i = 0; i < q; ++i) {
        cin >> queries[i].first >> queries[i].second;
    }

    // Initialize LCA structures
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < LOG; ++j) {
            parent[i][j] = -1;
            maxWeight[i][j] = 0;
        }
    }

    // DFS from node 1 (or any root)
    depth[1] = 0;
    dfs(1, -1, 0);

    // Calculate all pairwise distances
    vector<int> allWeights;
    for (const auto &edge : edges) {
        allWeights.push_back(edge.w);
    }
    sort(allWeights.begin(), allWeights.end());

    // Process queries
    vector<tuple<int, int, int>> sortedQueries;
    for (int i = 0; i < q; ++i) {
        sortedQueries.emplace_back(queries[i].second, queries[i].first, i);
    }
    sort(sortedQueries.begin(), sortedQueries.end());

    result.resize(q);
    int idx = 0;

    for (const auto &query : sortedQueries) {
        int r = get<0>(query), l = get<1>(query), queryIndex = get<2>(query);
        while (idx < allWeights.size() && allWeights[idx] <= r) {
            ++idx;
        }

        // Count weights in range [l, r]
        int count = upper_bound(allWeights.begin(), allWeights.end(), r) - 
                    lower_bound(allWeights.begin(), allWeights.end(), l);
        result[queryIndex] = count;
    }

    for (const auto &res : result) {
        cout << res << " ";
    }
    cout << endl;

    return 0;
}
