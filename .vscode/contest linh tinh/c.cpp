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
const long long MOD = 1e9+7;
const int dx[8] = {-1,-1,-1,0,0,1,1,1};
const int dy[8] = {-1,0,1,-1,1,-1,0,1};


const int n=100005;

int sang[n+5], kq[n+5], nghich[n*50];
vector<int> a[n+5];
map<int,int> f[n+1];

void sangnt(){
    for(int i=2;i*i<=n;i++){
        if(!sang[i]){
            for(int j=i*i;j<=n;j+=i){
                if(!sang[j]) sang[j]=i;
            }
        }
    }
    for(int i=2;i<=n;i++){
        if(!sang[i]) sang[i]=i;
    }
}

void dfs(int u, int p=0){
    for(int v : a[u]){
        if(u==p) continue;
        dfs(v,u);
        kq[u]=kq[u]*kq[v]%MOD;
        if((int)f[u].size() < (int)f[v].size()) swap(f[u],f[v]);
        for(auto x : f[v]){
            if(f[u][x.first]) kq[u] = kq[u]*(f[u][x.first]+x.second+1)*nghich[f[u][x.first]+1]*nghich[x.second+1];
            f[u][x.first]+=x.second;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    // freopen("input.inp","r",stdin);
    // freopen("output.out","w",stdout);
    sangnt();
    nghich[1]=1;
    for(int i=2;i<50*n;i++){
        nghich[i]=(MOD-MOD/i)*nghich[MOD%i]%MOD;
    }
    int n,q; cin >> n >> q;
    for(int i=1;i<=n;i++){
        int dem=0;
        int x; cin >> x;
        kq[i]=1;
        while(sang[x]){
            if(!f[i][sang[x]]){
                kq[i]=kq[i]*(dem+1)%MOD;
                dem=0;
            }
            dem++;
            f[i][sang[x]]++;
            x/=sang[x];
        }
        kq[i] = kq[i]*(dem+1)%MOD;
    }
    for(int i=1;i<n;i++){
        int u,v; cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    dfs(1);
    while(q--){
        int u;
        cin >> u;
        cout << kq[u] << " ";
    }
    return 0;
}




#include <iostream>
using namespace std;

const long long mod = 998244353;

void multiply(long long a[2][2], long long b[2][2], long long c[2][2]) {
    long long x00 = (a[0][0] * b[0][0] % mod + a[0][1] * b[1][0] % mod) % mod;
    long long x01 = (a[0][0] * b[0][1] % mod + a[0][1] * b[1][1] % mod) % mod;
    long long x10 = (a[1][0] * b[0][0] % mod + a[1][1] * b[1][0] % mod) % mod;
    long long x11 = (a[1][0] * b[0][1] % mod + a[1][1] * b[1][1] % mod) % mod;
    c[0][0] = x00;
    c[0][1] = x01;
    c[1][0] = x10;
    c[1][1] = x11;
}

int main() {
    long long n;
    cin >> n;

    long long base[2][2] = {{1, 1}, {1, 0}};
    long long res[2][2] = {{1, 0}, {0, 1}};

    while (n) {
        if (n & 1) {
            long long temp[2][2];
            multiply(res, base, temp);
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    res[i][j] = temp[i][j];
                }
            }
        }
        long long temp[2][2];
        multiply(base, base, temp);
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                base[i][j] = temp[i][j];
            }
        }
        n /= 2;
    }

    long long F_n_plus_1 = (res[0][0] + res[0][1]) % mod;
    long long F_n = (res[1][0] + res[1][1]) % mod;
    long long area = F_n_plus_1 * F_n % mod;
    cout << area << endl;

    return 0;
}