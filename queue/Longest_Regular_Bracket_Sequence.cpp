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

// https://codeforces.com/problemset/problem/5/C

void check(string s){
    int res = 0;
    stack<int> q;
    int cnt = 1;
    q.push(-1);
    for(int i=0;i<(int)s.length();i++){
        if(s[i] == '(') q.push(i);
        else{ // truong hop ngoac  s[i] == )
            if(q.size() == 1){
                q.pop();
                q.push(i);
            }
            else{
                q.pop();
                int tmp = i - q.top();
                if(tmp > res){
                    cnt = 1;
                    res = tmp;
                }
                else if(tmp == res) cnt++;
            }
        }
    }
    cout << res << " " << cnt;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    queue<char> q;
    string s; cin >> s;
    check(s);
}


