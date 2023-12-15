#include <bits/stdc++.h>
#define maxn 10000000

using namespace std;
using ll = long long;


int count_prime(ll n){
    int ans = 0;
    int res = 1;
    for(int i=2;i<=sqrt(n);i++){
        int temp = 0;
        if(n%i==0){
            ans++;
            while(n%i==0){
                n/=i;
                temp++;
            }
            res *= temp+1;
        }
    }
    if(n > 1) ans++;
    cout << res << endl;
    return ans;
}


signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	// freopen("input.inp","r",stdin);
	// freopen("output.out","w",stdout);
    ll n; cin >> n;
    cout << count_prime(n) << endl;
	return 0;
}



