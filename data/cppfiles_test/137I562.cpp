#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define all(x)      x.begin(), x.end()
#define pb          push_back
#define sz(x)       (int)(x.size())
#define ll          long long
#define fi          first
#define se          second
#define lbd         lower_bound
#define ubd         upper_bound

template <typename T>
using ordered_set = tree<T, null_type,
      less<T>, rb_tree_tag,
      tree_order_statistics_node_update>;

const int MOD = 1e9 + 7;
const double eps = 1e-10;
const long long INF = 1e18;
const int N = 2e5 + 10;


void solve() {
	ll x, y;
	cin >> x >> y;
	if (x == y) {
		cout << "YES";
		return;
	}
	if (y % 2 == 0) {
		cout << "NO";
		return;
	}

	auto f = [](ll n) {
		string ans;
		while (n) {
			if (n & 1) ans += '1';
			else ans += '0';
			n >>= 1;
		}
		return ans;
	};

	auto chk = [&](string s) {
		for (int j = 0; j < sz(s); j++) {
			if (s[j] == '0') continue;
			for (int k = j + 1; k < sz(s); k++) {
				ll curr = 0;
				for (int i = j; i <= k; i++) {
					if (s[i] == '1') curr += (1LL << (i - j));
				}
				while (curr < x) curr <<= 1;
				bool ok = 0;
				if (curr == x) {
					ok = 1;
					for (int i = 0; i < j; i++) {
						if (s[i] == '0') {
							ok = 0;
							break;
						}
					}
					for (int i = k + 1; i < sz(s); i++) {
						if (s[i] == '0') {
							ok = 0;
							break;
						}
					}
				}
				if (ok) return true;
			}
		}
		reverse(all(s));
		for (int j = 0; j < sz(s); j++) {
			if (s[j] == '0') continue;
			for (int k = j + 1; k < sz(s); k++) {
				ll curr = 0;
				for (int i = j; i <= k; i++) {
					if (s[i] == '1') curr += (1LL << (i - j));
				}
				while (curr < x) curr <<= 1;
				bool ok = 0;
				if (curr == x) {
					ok = 1;
					for (int i = 0; i < j; i++) {
						if (s[i] == '0') {
							ok = 0;
							break;
						}
					}
					for (int i = k + 1; i < sz(s); i++) {
						if (s[i] == '0') {
							ok = 0;
							break;
						}
					}
				}
				if (ok) return true;
			}
		}
		return false;
	};
	if (chk(f(y))) cout << "YES";
	else cout << "NO";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tt = 1;
	//cin >> tt;
	while (tt--) {
		solve();
		cout << '\n';
	}
	return 0;
}