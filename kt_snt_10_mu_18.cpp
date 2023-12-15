#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll binpow(ll a, ll b, ll m){
    if(b==0) return 1;
    ll x = binpow(a,b/2,m);
    if(b % 2 == 1){
        return ((x%m) * (x*m) % m) * a%m % m;
    }
    else{
        return (x%m) * (x%m) % m;
    }
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	// freopen("input.inp","r",stdin);
	// freopen("output.out","w",stdout);
    ll n; cin >> n;
    int ok = 0;
    for(int i=2;i<=51;i++){
        if(binpow(i,n-1,n) == 1) ok = 1;
    }
    cout << ok << endl;
	return 0;
}



