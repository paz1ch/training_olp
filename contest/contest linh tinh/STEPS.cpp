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
 

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("STEPS.INP","r",stdin);
    freopen("STEPS.OUT","w",stdout);
    int n,k; cin >> n >> k;
    bool check[100001];
    memset(check,true,sizeof(check));
    for(int i=1;i<=k;i++){
        int x; cin >> x;
        check[x] = false;
    }
    ll F[n+1] = {0};
    F[0] = 0;
    F[1] = 1;
    for(int i=2;i<=n;i++){
        if(check[i]){
            F[i] += F[i-1] + F[i-2];
            F[i] %= mod;    
        }
    }
    cout << F[n] << endl;
    return 0;
}