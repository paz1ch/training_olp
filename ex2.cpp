#include <bits/stdc++.h>

using namespace std;




signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	// freopen("input.inp","r",stdin);
	// freopen("output.out","w",stdout);

    int t=0,b=0,g=0;
    for(int i=0;i<n-1;i++){
        t+= a[i+1] > a[i];
        b += a[i+1] == a[i];
        g += a[i+1] < a[i];
    }
    t=t>0;
    b=b>0;
    g=g>0;
    int temp =
	return 0;
}



