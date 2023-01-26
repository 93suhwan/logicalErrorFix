#include<bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>  using oset =
    tree<T, null_type, less<T>,
    rb_tree_tag, tree_order_statistics_node_update>;
#define odrkey order_of_key
#define fbodr find_by_order
#define ll long long
#define sq(a) ((a)*(a))
#define ull unsigned long long
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define watch(x) cout << (#x) << " is " << (x) << endl
#define pi 3.1415926536
#define nwl cout <<"\n";
#define MAXN 300009
#define ff first
#define ss second
#define pb push_back
#define pf push_front
#define eps 0.000001
template<typename T_vector>
void output_vector(const T_vector &v, bool add_one = false, int start = -1, int end = -1) {
	if (start < 0) start = 0;
	if (end < 0) end = int(v.size());

	for (int i = start; i < end; i++)
		cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');
}
ll Pow(ll a, ll b) {
	if (a == 0) return 0LL;
	ll ans = 1;
	for (int i = 0; i < b; i++) {
		ans *= a;
	}
	return ans;
}
ll lcm(ll a, ll b) {
	return (a * b) / __gcd(a, b);
}
ll md = (ll) 1e9 + 7;
ll bigmod(ll a, ll b, ll m) {
	if (b == 0) return 1LL;
	ll tm = bigmod(a, b / 2, m);
	tm = (tm * tm) % m;
	if (b % 2) tm = (tm * a) % m;
	return tm;
}
vector<int> v;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin >> s;
	int n = s.size();

	for (ll i = 0; i <= 99999999; i += 25) {
		v.pb(i);
	}
	ll ans = 0;
	for (int x : v) {
		string tm = to_string(x);
		if (tm.size() > n) break;
		bool f = 1;
		for (int i = 0; i < n; i++) {
			if (tm[i] != s[i]) {
				if (s[i] == '_')continue;
				else if (s[i] == 'x') {
					int p = i;
					int d = tm[i];
					while (p < n) {
						if (s[p] == 'x' && tm[p] != d) {
							f = 0;
							break;
						}
						if (!f) break;
						p++;
					}
				}
				else {
					f = 0;
					break;
				}
			}
		}
		if (f)ans++;
	}
	cout << ans << "\n";
}
