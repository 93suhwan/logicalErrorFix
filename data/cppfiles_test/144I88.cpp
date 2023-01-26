//#pragma GCC optimize "trapv" 
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using ull = unsigned long long;
using ll = long long;
using namespace __gnu_pbds;

#define print(x) cout << #x << " " << x << endl;
#define print_array(x) (cout << #x); for (auto i : (x)) cout << " " << i; cout << endl;

template<typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve() {
	ll n, m, k; cin >> n >> m >> k;
	ll diff = n%m;

	ll start = 0;
	for (ll i = 0; i < k; i++) {
		ll x = start%n;
		start += (n+i)/k;
		for (ll j = 0; j < m; j++) {
			ll count = (n+j)/m;
			cout << count;
			for (ll k = 0; k < count; k++) {
				cout << " " << x+1;
				x++;
				x %= n;
			}
			cout << endl;
		}
	}
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t; cin >> t;
	while (t--) solve();

}
