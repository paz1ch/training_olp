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
const long long mod = 1e9+7;
const int dx[8] = {-1,-1,-1,0,0,1,1,1};
const int dy[8] = {-1,0,1,-1,1,-1,0,1};
 
ll check(ll n){
    ll res = 0;
    while(n != 0){
        res += n % 10;
        n /= 10;
    }
    return res;
}

ll check_pow(ll n){
    ll res = 0;
    while(n != 0){
        res += 1LL * (n%10) * (n%10);
        n /= 10;
    }
    return res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("input.inp","r",stdin);
    freopen("output.out","w",stdout);
    int n; cin >> n;
    while(n--){
        ll a,b; cin >> a >> b;
        ll ans = 0;
        for(ll i=a;i<=b;i++){
            if(__gcd(check(i),check_pow(i)) == 1) ans++;
        }
        cout << ans << endl;
    }
    return 0;
}