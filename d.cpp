#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> q;
    for(int i=1;i<=n-1;i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // depth[1] = 0;
    dfs(1,-1);
    pre();
    while(q--){
        int x,y,z; cin >> x >> y >> z;
        int xy=lca(x,y);
        int xz=lca(x,z);
        int yz=lca(y,z);
        // cout << xy << " " << xz << " " << yz << endl;
        int res=xy;
        if(depth[yz] > depth[res]) res = yz;
        if(depth[xz] > depth[res]) res = xz;
        cout << min(min(dis(x,res),dis(y,res)),dis(z,res)) << endl;
    }
}
    
