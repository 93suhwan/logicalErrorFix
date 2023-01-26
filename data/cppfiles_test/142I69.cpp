//                        YATIN KWATRA

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize ("Ofast")
//#pragma GCC optimize "trapv" // to detect overflow

#define ll                      long long
#define ar                      array
#define sz(v)                   (int)(v.size())
#define int                     ll
#define FIO                     ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld                      long double
#define ull                     unsigned long long
#define endl                    "\n"
#define fo(i,a,b)               for(int i = a; i<=b ; i++)
#define rfo(i,a,b)              for(int i = a; i>=b ; i--)
#define vii                     vector<int>
#define pq                      priority_queue
#define uomii                   unordered_map<int,int,best_hash>
#define all(v)                  v.begin(),v.end()
#define mp                      make_pair
#define pb                      push_back
#define pob                     pop_back
#define ff                      first
#define ss                      second
#define pii                     pair<int,int>
#define mii                     map<int,int>
#define vvii                    vector<vii>
#define mod                     1000000007
#define inf                     5e18
#define pi                      3.1415926535897932384626433832795
#define cz(x)                   63 - __builtin_clzll(x)

using namespace std;
using namespace __gnu_pbds;
template<class T> using oset =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


struct best_hash {
	static uint64_t splitmix64(uint64_t x) {

		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}

	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}
};

// m - shops
// n - friends

vvii v;
int m, n;

bool possible(int x) {
	int cnt = 0;

	multiset<int>val[n];

	int mn = 1e9;

	fo(j, 0, n - 1) {
		fo(i, 0, n - 1) {
			val[j].insert(v[i][j]);
		}
		mn = min(mn, *(val[j].rbegin()));
	}
	if (mn >= x) return 1;

	fo(i, n, m - 1) {
		// remove contribution of i- n
		mn = 1e9;
		fo(j, 0, n - 1) {
			val[j].erase(val[j].lower_bound(v[i - n][j]));
			val[j].insert(v[i][j]);
			mn = min(mn, *(val[j].rbegin()));
		}
		if (mn >= x) return 1;
	}
	return 0;
}

void solve()
{
	cin >> m >> n;
	v.resize(m);
	fo(i, 0, m - 1) v[i].resize(n);
	fo(i, 0, m - 1) {
		fo(j, 0, n - 1) cin >> v[i][j];
	}

	int ans = 1e9;

	if (m < n) {
		fo(j, 0, n - 1) {
			int mx = 0;
			fo(i, 0, m - 1) {
				mx = max(mx, v[i][j]);
			}
			ans = min(ans, mx);
		}
		cout << ans << endl;
		return;
	}

	int low = 1, high = 1e9, mid;
	ans = 0;

	while (low <= high) {
		mid = (low + high) / 2;
		if (possible(mid)) {
			ans = mid;
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	cout << ans << endl;
}
signed main() {

	FIO
	int t;
	t = 1;
	cin >> t;
	fo(i, 0, t - 1) {
		solve();
	}
	return 0;
}

