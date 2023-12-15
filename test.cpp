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

int n,m,q;
vector<pair<int,int>> adj[2005];


void dijkstra(int s, int t, int &max_time, int ok = 1){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    q.push({0,1});
    vector<int> d(n+1,1e9); d[1] = 0;
    for(int i=1;i<=n;i++){
        for(pair<int,int> &u : adj[i]){
            if(max_time == u.second){
                if(u.second < t) break;
                u.second = t;
                max_time = t;
                break;
            }
        }
    }
    // for(int i=1;i<=n;i++){
    //     for(pair<int,int> u : adj[i]){
    //         cout << i << " " << u.first << " " << u.second << endl;
    //     }
    // }
    while(!q.empty()){
        pair<int,int> p = q.top(); q.pop();
        if(p.first > d[p.second]) continue;
        for(pair<int,int> u : adj[p.second]){
            // if(d[u.first] < d[p.second] + u.second) continue;
            if(d[u.first] > d[p.second] + u.second){
                d[u.first] = d[p.second] + u.second;
                q.push({d[u.first],u.first});
            }
        }
    }
    cout << d[s] << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    // freopen("input.inp","r",stdin);
    // freopen("output.out","w",stdout);
    cin >> n >> m >> q;
    int max_time = INT_MIN;
    for(int i=1;i<=m;i++){
        int x,y,z; cin >> x >> y >> z;
        adj[x].push_back({y,z});
        if(z > max_time) max_time = z;
    }
    while(q--){
        int s,t;
        cin >> s >> t;
        dijkstra(s,t, max_time);
    }
    return 0;
}