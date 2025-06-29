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


bool check(int a[], int n, ll r, int k){
    ll count = 1;
    int l = a[0];
    for(int i=0;i<n;i++){
        if(a[i] > l + 1LL*2*r){
            count++;
            l = a[i];
            if(count > k) return false;
        }
    }
    return true;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    // freopen("input.inp","r",stdin);
    // freopen("output.out","w",stdout);
    int n,k; cin >> n >> k;
    int a[n];   
    for(int &x : a) cin >> x;
    sort(a,a+n);
    ll l=0,r=1000000000;
    while(l < r){
        ll m = (l+r)>>1;
        if(check(a,n,m,k)) r = m;
        else l = m+1;
    }
    cout << l << endl;
}
