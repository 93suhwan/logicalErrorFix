#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define all(x) x.begin(), x.end()
const int N = 2e6 + 5, MOD = 1e9 + 7;


void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	if(m < n - 1 || m > n*(n - 1)/2) {
		cout << "NO\n";
		return;
	}
	if(n == 1) {
		if(k > 1) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
		return;
	}
	if(m == n*(n - 1)/2) {
		if(k > 2) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
		return;
	} 
	if(k > 3) {
		cout << "YES\n";
	}
	cout << "NO\n";
}


int main() {
	int tc = 1;
	cin >> tc;
	for(int tt = 1; tt <= tc; tt++) {
		solve();
	}
} 









