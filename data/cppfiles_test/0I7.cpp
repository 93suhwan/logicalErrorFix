#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;

using namespace __gnu_pbds;

using ll = long long;

template <typename T>
using ordered_set = tree<T, null_type,
        less<T>, rb_tree_tag,
        tree_order_statistics_node_update>;

void fastIO() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
}

int main() {
	fastIO();
	int t = 1;// cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		vector<string> v(n);
		vector<int> indices(n);
		for (string &s : v) {
			cin >> s;
		}
		iota(indices.begin(), indices.end(), 0);
		sort(indices.begin(), indices.end(), [&v](int i1, int i2) -> bool {
			return v[i1] < v[i2];
		});
		vector<int> ans;
		for (int p = 1, i = 0, j = n - 1; i <= j; p ^= 1) {
//			cerr << i << ' ' << j << '\n';
			if (p) {
				ans.push_back(indices[i++] + 1);
			} else {
				ans.push_back(indices[j--] + 1);
			}
		}
		for (int i = 0; i < n; ++i) {
			cout << ans[i] << (" \n"[i + 1 == n]);
		}
	}
	return 0;
}
