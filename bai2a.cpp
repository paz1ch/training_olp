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
using ld = long double;
const long long mod = 14062008;
const int dx[8] = {-1,-1,-1,0,0,1,1,1};
const int dy[8] = {-1,0,1,-1,1,-1,0,1};


int t[4*100001],n,a[100001];

void build(int id, int l, int r){
    if(l == r){
        t[id] = a[l];
        return;
    }
    int m = (l+r)/2;
    build(id*2,l,m);
    build(id*2+1,m+1,r);
    t[id] = max(t[id*2],t[id*2+1]);
}

void update(int id, int l, int r, int x, int y, int val){
    if(y < l || x > r) return;
    if(l >= x && r <= y){
        t[id] += val;
        return;
    }
    int m = (l+r)/2;
    update(2*id,l,m,x,y,val);
    update(2*id,m+1,r,x,y,val);
    t[id] = max(t[id*2],t[id*2+1]);
}

int get(int id, int l, int r, int x, int y){
    if(y < l || x > r) return -1e9;
    if(l >=x && r <= y){
        return t[id];
    }
    int m = (l+r)/2;
    return max(get(id*2,l,m,x,y),get(id*2+1,m+1,r,x,y));
}

signed main() { 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    // freopen("input.inp","r",stdin);
    // freopen("output.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    build(1,1,n);
    int q; cin >> q;
    while(q--){
        int e,x,y,val; cin >> e;
        if(e == 1){
            cin >> x >> y >> val;
            update(1,1,n,x,y,val);
        }
        else if(e == 2){
            cin >> x >> y;
            cout << get(1,1,n,x,y) << endl;
        }
    }
}
