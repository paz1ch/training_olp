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

// bool a[10000001];
// void sang(){
//     for(int i=2;i<=1000000;i++){
//         a[i] = true;
//     }
//     a[0] = a[1] = false;
//     for(int i=2;i<=sqrt(1000000);i++){
//         if(a[i]){
//             for(int j=i*i;j<=1000000;j+=i){
//                 a[j] = false;
//             }
//         }
//     }
// }

// void solve(ll n){
//     ll uoc = 1;
//     ll uocnt = 0;
//     for(int i=1;i<=1000000;i++){
//         if(a[i]){
//             if(n % i == 0){
//                 uocnt++;
//                 int e = 0;
//                 while(n%i==0){
//                     e++;
//                     n /= i;
//                 }
//                 uoc *= (e+1);
//             }
//         }
//     }
//     if(n!=1){
//         uoc *= 2;
//         uocnt++;
//     }
//     cout << uocnt << " " << uoc << endl;
// }

int n,x;
pair<int,int> b[200005];
bool binary_search(int first, int last, int res){
    if(last > first) return false;
    int mid = (last+first) >> 1;
    if(b[mid].first == res) return true;
    else if(b[mid].first > res) return binary_search(first,mid-1,res);
    else return binary_search(mid+1,last,res);
}

bool comp(pair<int,int> a, pair<int,int> p){
    return a.first < p.first;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    // freopen("input.inp","r",stdin);
    // freopen("output.out","w",stdout);
    cin >> n >> x;
    for(int i=1;i<=n;i++){
        int x; cin >> x;
        b[i].first = x; b[i].second = i;
    }
    sort(b+1,b+n+1,comp);
    for(int i=1;i<=n;i++){
        if(binary_search(i+1,i+n+1,x-b[i].first)){
            cout << min(b[i].second,b[x-b[i].first].second) << " " << max(b[i].second,b[x-b[i].first].second) << endl;  
            return 0;
        }
    }
    cout << "IMPOSSIBLE" << endl;
}