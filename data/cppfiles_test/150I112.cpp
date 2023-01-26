#include<bits/stdc++.h>	
 
/*
#pragma optimize ("g",on)
#pragma GCC optimize("inline")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("03")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,avx2,mmx,fma,avx,tune=native")
*/

//01001101 01100001 01101011 01101000 01100001  01100111 01100001 01111001 

using namespace std;

#define all(a) a.begin(), a.end()                                                   
#define rall(a) a.rbegin(), a.rend()
#define ll long long
#define pb push_back
#define sz(a) a.size()
#define nl '\n'
#define popb pop_back()                                                                   
#define ld double
#define ull unsigned long long
#define ff first                                         
#define ss second  
#define fix fixed << setprecision
#define pii pair<int, int>                          
#define E exit (0)
#define int long long
 
const int inf = 1e18, N = 1e6 + 1, mod = 998244353;                    

vector<pii> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

main() {                                                         
	//freopen("cowrect.in", "r", stdin);                                                                                     
	//freopen("cowrect.out", "w", stdout);                                                                                     
	ios_base::sync_with_stdio(NULL);                                                                                        
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int a[n + 1];
		for (int i = 1; i <= n; i++) cin >> a[i];
		int mx = 0, ok = 0, ok1 = 0;
		for (int i = 1; i <= n; i++) {
			if (a[i] % 3 == 1) ok = 1;
			if (a[i] % 3 == 2) ok1 = 1;
			mx = max(mx, a[i]);
		}
		if (!ok && !ok1) cout << mx / 3 << nl;
		else if (ok && ok1) {
			int mx1 = 0, mx2 = 0, mx3 = 0;
			for (int i = 1; i <= n; i++) {
				if (a[i] == 1) {
					mx1 = max(mx1, 1ll);	
				}else if (a[i] == 2) {
					mx2 = max(mx2, 1ll);
				}else {
					if (a[i] % 3 == 0) {
						mx3 = max(mx3, a[i] / 3 - 1);
					}else if (a[i] % 3 == 1) {
						mx3 = max(mx3, a[i] / 3 - 1);
						mx2 = max(mx2, 2ll);
					}else {
						mx3 = max(mx3, a[i] / 3);
						mx2 = max(mx2, 1ll);
					}
				}
			}
			cout << min(mx / 3 + 2, mx1 + mx2 + mx3) << nl;
		}else cout << mx / 3 + 1 << nl;
	}
}                                 