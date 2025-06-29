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



bool check(int n){
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0) return false;
    }
    return true;
}

void solve(int n){
    ll temp;
    for(int i=2;i<=30;i++){
        if(check(i)){
            temp = pow(2,i-1)*(pow(2,i)-1);
            if(temp <= n) cout << temp << endl;
            else return;
        }
    }

}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    // freopen("input.inp","r",stdin);
    // freopen("output.out","w",stdout);
    int n; cin >> n;
    // solve(n);
    return 0;
}