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


ll bin(ll a, ll b, ll n){
    if(b == 0) return 0;
    ll x = bin(a,b/2,n);
    if(b&1) return ((x+x)%n + a%n)%n;
    else return (x+x)%n;
}


ll bin_pow(ll a, ll b, ll n){
    if(b == 0) return 1LL;
    ll x = bin_pow(a,b/2,n);
    if(b&1) return bin(bin(x,x,n),a,n);
    else return bin(x,x,n);
}

bool test(ll a, ll n, ll k, ll m){
    ll mod = bin_pow(a,m,n);
    if(mod == 1 || mod == n-1){
        return true;
    }
    for(int i=1;i<=k-1;i++){
        mod = (mod*mod)%n;
        if(mod == n-1) return true;
    }
    return false;
}

bool rabin_miller(ll n){
    if(n == 2 || n == 3 || n ==5 || n == 7) return true;
    if(n < 11) return false; 
    ll m = n-1,k=0;
    while(!m&1){
        k++;
        m/=2;
    }
    vector<int> check = {2,3,5,7};
    for(int x : check){
        if(!test(x,n,k,m)) return false;
    }
    return true;
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    // freopen("input.inp","r",stdin);
    // freopen("output.out","w",stdout);
    ll n; cin >> n;
    cout << (rabin_miller(n) ? "YES" : "NO") << endl;
}