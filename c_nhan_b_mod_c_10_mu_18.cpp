#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll solve(ll a, ll b, ll m){
    ll s = 0;
    while(a > 1){
        if(a%2!=0){
            s = (s+b)%m;
        }
        a = a>1;
        b = (b<1)%m;
    }
    s = (s+b)%m;
    return s;
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




