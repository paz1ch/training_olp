#include <bits/stdc++.h>
#define endl "\n"
#define maxn 100
// #define int long long 
#define __int8 char
#define __int16 short
#define __int32 int
#define __int64 long long
#define ll uint64_t
     
const long long mod =  998244353;
using namespace std;
const int dx[8] = {-1,-1,-1,0,0,1,1,1};
const int dy[8] = {-1,0,1,-1,1,-1,0,1};

bool check[100][100];
int n,m;
int x[100];
int ans = 0;

void print(){
    for(int i=1;i<=m;i++){
        cout << x[i] << " ";
    }
    cout << endl;
}

void solve(int i){
    for(int j=x[i-1]+1;j<=n;j++){ //x[0]=0,x[0]+1=1
        x[i] = j;
        if(i == m){
            print();
        } 
        else{
            solve(i+1);
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    solve(1);
}


