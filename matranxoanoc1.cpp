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
 


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("input.inp","r",stdin);
    freopen("output.out","w",stdout);
    int n,m; cin >> n >> m;
    int a[n*m];
    for(int i=0;i<n*m;i++){
        cin >> a[i];
    }
    sort(a,a+(n*m));
    int ans[n][m];
    int h1 = 0,h2=n-1,c1=0,c2=m-1;
    int temp = 0;
    cout << endl;
    while(temp < n*m){
        for(int i=c1;i<=c2;i++){
            ans[h1][i] = a[temp++];
        }
        h1++;
        for(int i=h1;i<=h2;i++){
            ans[i][c2] = a[temp++];
        }
        c2--;
        for(int i=c2;i>=c1;i--){
            ans[h2][i] = a[temp++];
        }
        h2--;
        for(int i=h2;i>=h1;i--){
            ans[i][c1] = a[temp++];
        }
        c1++;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}