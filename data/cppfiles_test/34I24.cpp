#include<bits/stdc++.h>
#define INF (ll)(1e18)
#define MOD (ll)(1e9+7)
#define pb push_back
#define mp make_pair
#define ft first
#define sd second

using namespace std;
using ll = long long;
using ul = unsigned long;

void f_io () { ios_base :: sync_with_stdio (false); cin.tie (nullptr);;
 cout.tie (nullptr); }
const ll p1 = MOD, p2 = 998244353;


pair<ll, ll> rh (ll x, ll y) {
	ll f = (x + p1 * 1LL * y) % p2;
	ll s = (x + p2 * 1LL * y) % p1;
	return mp (f, s);
}

ll gc (ll a, ll b) {
	if (!a || !b) {
		return max (a, b);
	}
	assert (b != 0);
	ll r = a % b;
	while (r) {
		a = b;
		b = r;
		r = a % b;
	}
	return b;
}

inline ll mult (ll a, ll b) {
	return ((a % MOD)  * 1LL * (b % MOD)) % MOD;
}

inline ll add (ll a, ll b) {
	b = (b % MOD + MOD) % MOD;
	return (a + b) % MOD;
}

ll pw (ll a, ll b) {
	if (b < 0) {
		return 1;
	}
	ll r = 1;
	while (b) {
		if (b & 1) {
			r = mult (a, r);
		}
		b >>= 1;
		a = mult (a, a);
	}
	return r;
}
ll nc2 (ll n) {
	return ((n - 1) * 1LL * (n)) / 2;
}

ll nc3 (ll n) {
	return ((n - 1) * (n - 2) * n) / 6;
}

const int MAX = 1e5;

vector<int> v[5010];
int re[MAX], mi[MAX];

int main () {
	f_io ();
	int n;
	cin >> n;
	int ar[n], p[n] = {};
	fill (re, re + MAX, -1);
	fill (mi, mi + MAX, MOD);
	re[0] = 0;
	for (int i = 0; i < n; ++i) {
		cin >> ar[i];
		if (v[ar[i]].size ()) {
			p[i] = v[ar[i]].back ();
		}
		v[ar[i]].pb (i);
	}
	set<pair<int, int>> sp;
	mi[0] = -1;
	sp.insert (mp (0, 0));
	for (int i = 0; i < n; ++i) {
		vector<int> vp;
		for (auto it = sp.rbegin (); it != sp.rend () && it -> first >= p[i]; ++it) {
			if (mi[it -> sd] >= ar[i]) {
				continue;
			}
			int xo = (it -> sd) ^ ar[i];
			if (re[xo] == -1 || mi[xo] > ar[i]) {
				mi[xo] = ar[i];
				vp.pb (xo);
			}
		}
		for (int y : vp) {
			if (re[y] != -1) {
				assert (sp.find (mp (re[y], y)) != sp.end ());
				sp.erase (mp (re[y], y));
			}
			re[y] = i;
			sp.insert (mp (i, y));
		}
	}
	vector<int> ans;
	for (int i = 0; i < MAX; ++i) {
		if (re[i] > -1) {
			ans.pb (i);
		}
	
	}
	for (int x : ans) {
		cout << x << " ";
	}
	cout << "\n";
}
