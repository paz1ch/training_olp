#include <bits/stdc++.h>
#define endl "\n"
#define maxn 200005
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
 
int tree[maxn+1];

void update(int index, int value, int n){
        while (index <= n) {
            tree[index] += value;
            index += index & -index;
        }
}

int query(int index) {
        int sum = 0;
        while (index > 0) {
            sum += tree[index];
            index -= index & -index;
        }
        return sum;
}

int count(int n, vector<pair<int, int>> points) {
    sort(points.begin(), points.end());
    vector<int> vs;
    for (pair<int,int> p : points) {
        vs.push_back(p.second);
    }
    vector<int> sorted_vs = vs;
    sort(sorted_vs.begin(), sorted_vs.end());

    map<int, int> rank;
    int rank_count = 1;
    for (int v : sorted_vs) {
        rank[v] = rank_count++;
    }

    vector<int> r_vs;
    for (int v : vs) {
        r_vs.push_back(rank[v]);
    }
    int res = 0;

    for (int v : r_vs) {
        res += query(n) - query(v);
        update(v, 1,n);
    }

    return res;
}


signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	// freopen("input.inp","r",stdin);
	// freopen("output.out","w",stdout);
	int n;
    cin >> n;
    vector<pair<int, int>> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].first >> points[i].second;
    }
    cout << count(n,points) << endl;
	return 0;
}
	