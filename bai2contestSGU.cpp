#include <bits/stdc++.h>
#define endl "\n"
#define maxn 100
// #define int long long 
#define __int8 char
#define __int16 short
#define __int32 int
#define __int64 long long
 
using namespace std;
using ll = long long;
const long long mod = 14062008;
const int dx[8] = {-1,-1,-1,0,0,1,1,1};
const int dy[8] = {-1,0,1,-1,1,-1,0,1};

int parent[3*100005], sz[3*100005];
int Find(int u){
    if(u == parent[u]) return u;
    return parent[u] = Find(parent[u]);
}

bool Union(int u, int v){
    u = Find(u);
    v = Find(v);
    if(u == v) return false;
    if(sz[u] < sz[v]) swap(u,v);
    sz[u] += sz[v];
    parent[v] = u;
    return true;
}

int find_sz(int u){
    u = Find(u);
    return sz[u];
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    // freopen("input.inp","r",stdin);
    // freopen("output.out","w",stdout);
    int n,q; cin >> n >> q;
    set<pair<int,int>> s[100005];
    while(q--){
        int u,x,v;
        cin >> u;
        int temp = 1;
        if(u == 1){
            cin >> x >> v;
            
        }
        else if(u == 2){
            cin >> x;
            cout << find_sz(x) << endl;
        }
        else if(u == 3){
            cin >> x;
            
        }
    }
}