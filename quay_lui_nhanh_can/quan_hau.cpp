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
 
/* Đặt n quân hậu trên bàn cờ vua nx
sao cho không có 2 quân hậu nào khống chế nhau.
*/

int n,x[100];
bool cot[100],xuoi[100],nguoc[100];

void print(){
	for(int i=1;i<=n;i++){
		cout << "con hau nam o hang " << i << " cot " << x[i] << endl;
	}
}

void solve(int i){
	for(int j=1;j<=n;j++){
		if(!cot[j] && !xuoi[i-j+n] && !nguoc[i+j-1]){
			x[i] = j;
			cot[j] = true;
			xuoi[i-j+n] = true;
			nguoc[i+j-1] = true;
			if(i==n){
				print();
				cout << endl;
			}
			else{
				solve(i+1);
			}
			cot[j] = false;
			xuoi[i-j+n] = false;
			nguoc[i+j-1] = false;
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	// freopen("input.inp","r",stdin);
	// freopen("output.out","w",stdout);
	cin >> n;
	memset(cot,false,sizeof(cot));
	memset(xuoi,false,sizeof(xuoi));
	memset(nguoc,false,sizeof(nguoc));
	solve(1);
	return 0;
}