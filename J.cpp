#include <bits/stdc++.h>
#define endl "\n"
#define maxn 100005
#define __int8 char
#define __int16 short
#define __int32 int
#define __int64 long long
 
using namespace std;
using ll = long long;
const long long mod = 1e9+7;
const int dx[4] = {1,-1,0,0};
const int dy[4] = {0,0,1,-1};


vector<int> adj[100005]; 
int parent[100005][17],n,q;   
int depth[100005];

void dfs(int u, int p) {
    parent[u][0] = p;
    for (int v : adj[u]) {
        if (v != p) {
            depth[v] = depth[u] + 1;
            dfs(v, u);
        }
    }
}

void preprocess(int n) {
    for (int j = 1; j < 17; j++) {
        for (int i = 1; i <= n; i++) {
            if (parent[i][j - 1] != -1)
                parent[i][j] = parent[parent[i][j - 1]][j - 1];
        }
    }
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);

    for (int i = 16; i >= 0; i--) {
        if (depth[u] - (1 << i) >= depth[v])
            u = parent[u][i];
    }

    if (u == v) return u;

    for (int i = 16; i >= 0; i--) {
        if (parent[u][i] != parent[v][i]) {
            u = parent[u][i];
            v = parent[v][i];
        }
    }

    return parent[u][0];
}

int distance(int u, int v) {
    int ancestor = lca(u, v);
    return depth[u] + depth[v] - 2 * depth[ancestor];
}

bool check(int x, int y, int z) {
    return distance(x, z) == distance(x, y) + distance(y, z);
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    // freopen("input.inp","r",stdin);
    // freopen("output.out","w",stdout);
    cin >> n >> q;
    for(int i=1;i<=n-1;i++){
        int x,y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1,-1);
    preprocess(n);
    while(q--){
        int x,y,z; cin >> x >> y >> z;
        if(check(x,y,z)){
            cout << "YES" << endl;
        }
        else cout << "NO" << endl;
    }
    return 0;   
}


