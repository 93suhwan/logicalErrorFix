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
			const string &s1 = v[i1];
			const string &s2 = v[i2];
			const int n = min(s1.size(), s2.size());
			for (int i = 0; i < n; ++i) {
				if (s1[i] == s2[i]) { continue; }
				if (i & 1) { // odd in 1-based
					return s1[i] < s2[i];
				} else { // even in 1-based
					return s2[i] < s1[i];
				}
			}
			assert(false);
		});
		for (int index : indices) {
			cout << index + 1 << ' ';
		}
		cout << '\n';
	}
	return 0;
}
