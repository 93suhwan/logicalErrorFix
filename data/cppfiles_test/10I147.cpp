#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define deb(x) cout<<#x<<'='<<x<<'\n';
#define deb2(x,y) cout<<#x<<'='<<x<<", "<<#y<<'='<<y<<'\n';
#define int long long
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
#define pb push_back
#define F first
#define S second
const double PI = 3.1415926535897932384626;
const int mod = 1000000007;

void solve() {
	int n, k; cin >> n >> k;
	int a[n];
	map<int, int> mp;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		mp[a[i]]++;
	}

	int p = 0;
	for (auto P : mp)
		if (P.S < k)
			p += P.S;

	p %= k;

	int ans[n] = {0};
	map<int, int> last;
	int last_col = 0;
	for (int i = 0; i < n; i++) {
		if (mp[a[i]] >= k) {
			int& x = last[a[i]];
			if (x < k) {
				x++;
				ans[i] = x;
			}
		}
		else {
			if (p > 0) p--;
			else {
				last_col++;
				ans[i] = last_col;
				if (last_col == k) last_col = 0;
			}
		}
	}

	for (int i = 0; i < n; i++)
		cout << ans[i] << " \n"[i == (n - 1)];
}

signed main() {
	FASTIO
#ifndef ONLINE_JUDGE
	freopen("../input1.txt", "r", stdin);
	freopen("../output1.txt", "w", stdout);
#endif

	int t = 1;

	cin >> t;

	for (int i = 1; i <= t; i++) {
		solve();
	}

	return 0;
}