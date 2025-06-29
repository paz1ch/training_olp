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





int solve(int n){
    int res = 1;
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0){
            int e = 0;
            while(n%i==0){
                n/=i;
                e++;
            }
            res *= (e+1);
        }
    }
    if(n!=1) res*=2;
    return res;
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    // freopen("input.inp","r",stdin);
    // freopen("output.out","w",stdout);
    int n; cin >> n;
    int ans = INT_MIN;
    for(int i=1;i<=n;i++){
        ans = max(ans,solve(i));
    }
    cout << ans << endl;
    return 0;
}