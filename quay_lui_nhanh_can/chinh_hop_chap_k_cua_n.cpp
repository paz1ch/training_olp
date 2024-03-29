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
 
int n,m;
int x[100];
bool check[100];

void print(){
	for(int i=1;i<=m;i++){
		cout << x[i] << " ";
	}
	cout << endl;
}

void solve(int i){
	for(int j=1;j<=n;j++){
		if(check[j]){
			x[i] = j;
			check[j] = false;
			if(i==m){
				print();
			}
			else solve(i+1);
			check[j]= true;
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	// freopen("input.inp","r",stdin);
	// freopen("output.out","w",stdout);
	cin >> n >> m;
	memset(check,true,sizeof(check));
	solve(1);
	return 0;
}