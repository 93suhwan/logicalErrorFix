#include<bits/stdc++.h>
#define ll Loli
#define lli long long int
#define eb emplace_back
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define pii pair<int, int>
#define F first
#define S second
#define get_bit(x, i) ((x>>i)&1) 
#define mkp make_pair
#define de(x) cout << #x << " = " << x << '\n'
#define deb(x, y) cout << #x << " = " << x << " " << #y << " = " << y << '\n'

using namespace std;
const int mxN = 1e6 + 1;

lli x, y;

lli to_dec(vector<int> v) {
//	reverse(all(v));
	lli res = 0;
	for (int i = 0; i < sz(v); i++) {
		if (v[i]) res |= (1LL<<i);	
	}
	return res;
}

bool bfs() {
	if (x == y) return 1;
	int mx = __builtin_popcountll(y);
	int mxlen = __lg(y);
	queue<lli> q; q.push(x);
	map<lli, int> mp;
	mp[x] = 1;
	while (!q.empty()) {
		if (mp.find(y) != mp.end()) return true;	
		lli now = q.front(); q.pop();	
		int h = __lg(now);
		vector<int> va, vb;
		va.eb(1);
		vb.eb(0);
		for (int i = 0; i <= h; i++) {
			va.eb(get_bit(now, i));	
			vb.eb(get_bit(now, i));
		}
		lli a = to_dec(va);	
		lli b = to_dec(vb);	
		if (__builtin_popcountll(a) <= mx and __lg(a) <= mxlen and !mp[a]) {
			mp[a] = 1;
			q.push(a);
		}
		if (__builtin_popcountll(b) <= mx and __lg(b) <= mxlen and !mp[b]) {
			mp[b] = 1;
			q.push(b);
		}
	}
	return false;
}

inline void solve() {
	cin >> x >> y;
	if (bfs()) cout << "Yes\n";
	else cout << "No\n";
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);	
	solve();
}