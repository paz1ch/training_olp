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
    int temp = 0;
    // for(int i=0;i<n*m;i++){
    //     cout << a[i] << " ";
    // }
    // return 0;
    int i=0,j=0;
    ans[i][j] = a[temp++];
    while(temp < n*m){
        if(i == 0 || j == m-1){
            if(j == m-1){
                ans[++i][j] = a[temp++];
            }
            else ans[i][++j] = a[temp++];
        }
        while(j > 0 && i < n-1){
            ans[++i][--j] = a[temp++];
        }
        if(j == 0 || i == n-1){
            if(i == n-1) ans[i][++j] = a[temp++];
            else ans[++i][j] = a[temp++];
        }
        while(i > 0 && j < m-1){
            ans[--i][++j] = a[temp++];
        }
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