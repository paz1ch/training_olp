#include <bits/stdc++.h>
#define endl "\n"
#define maxn 200005
 
using namespace std;
using ll = long long;
const int blockn = sqrt(maxn);
const int mod = (int)1e9+7;
const int dx[8] = {-1,-1,-1,0,0,1,1,1};
const int dy[8] = {-1,0,1,-1,1,-1,0,1};

ll n,x,y,z,t;
ll lcm(ll a, ll b){
    return (a / __gcd(a,b))*b;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >>  x >> y >> z >> t;
    ll ans = 0;
    ans += n/x + n/y + n/z + n/t;
    // cout << __gcd(2,3) << " " << lcm(2,3) << endl;
    // cout << ans << endl;
    ll res1=lcm(x,y);
    ll res2=lcm(x,z);
    ll res3=lcm(x,t);
    ll res4=lcm(y,z);
    ll res5=lcm(y,t);
    ll res6=lcm(z,t);
    // cout << res1 << " " << res2 << " " << res3 << " " << res4 << " " << res5 << " " << res6 << endl;
    ans -= n/res1 + n/res2 + n/res3 + n/res4 + n/res5 + n/res6;
    // cout << ans << endl;
    // cout << lcm(res1,z) << endl;
    ans += n/lcm(res1,z) + n/lcm(res1,t) + n/lcm(res2,t) + n/lcm(res4,t);
    // cout << ans << endl;
    ll res7=lcm(x,res4); 
    // cout << res7 << endl;
    ans -= n/lcm(res7,t);
    cout << ans << endl;
    return 0;
}
