#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
  
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> oset;
typedef long long ll;

#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define debug(x) cout << #x << ": " << x << '\n';

const int N = 1e5+5;

int sight[N];

void solve () {

	int n, m; cin >> n >> m;
	vector< pair < int, int > > a;
	for (int i = 0; i < n * m; ++i) {
		int power; cin >> power;
		sight[i] = power;
		a.push_back({power, i});
	}
	sort(all(a));
	int ptr = 0;
	int ans = 0;
	for (int row = 0; row < n; ++row) {
		vector < int > sitting;
		while (ptr < row * m + m) {
			sitting.push_back(a[ptr].ss);
			++ptr;
		}
		oset s;
		sort(all(sitting));
		for (int people : sitting) {
			ans += s.order_of_key(sight[people]);
			s.insert(sight[people]);
		}
	}
	cout << ans << '\n';

}

int main () {
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t = 1;
	cin >> t;

	for (int testcase = 1; testcase <= t; ++testcase) {
		// cout << "Case #" << testcase << ": ";
		solve();
	}

	return 0;
}