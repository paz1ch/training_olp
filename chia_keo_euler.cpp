#include <bits/stdc++.h>

using namespace std;




signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	// freopen("input.inp","r",stdin);
	// freopen("output.out","w",stdout);
    int n; cin >> n;
    pair<int,int> p[33];
    for(int i=0;i<n;i++){
        cin >> p[i].first >> p[i].second;
    }
    pair<int,int> u;
    cin >> u.first >> u.second;
    int k = n/2;
    map<pair<int,int>,int> m;
    for(int b=0;b<(1<<k);b++){
        pair<int,int> e = {0,0};
        for(int i=0;i<k;i++){
            if((b&(1<<i)) != 0){
                e.first += p[i].first;
                e.second += p[i].second;
            }
        }
        m[e]++;
    }
    k = n - k;
    int dem = 0;
    for(int b=0;b<(1<<k);b++){
        pair<int,int> e = {0,0};
        for(int i=0;i<k;i++){
            if((b&(1<<i)) != 0){
                e.first += p[n-i-1].first;
                e.second += p[n-i-1].second;
            }
        }
        pair<int,int> temp;
        temp.first = u.first - e.first;
        temp.second = u.second - e.second;
        dem += m[temp];
    }
    cout << dem << endl;
	return 0;
}




