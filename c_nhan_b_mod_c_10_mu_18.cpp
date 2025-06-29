	#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll solve(ll a, ll b, ll mod){
    if(b == 0) return 0;
    ll x = solve(a,b/2,mod)%mod;
    if(b&1) return ((x+x)%mod + a%mod)%mod;
    else return (x+x)%mod;
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	// freopen("input.inp","r",stdin);
	// freopen("output.out","w",stdout);
	ll a,b,m; cin >> a >> b >> m;
	cout << solve(a,b,m) << endl;
	return 0;
}




