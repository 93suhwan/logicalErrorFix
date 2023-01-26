#include "bits/extc++.h"

using namespace std;

template <typename T>
void dbgh(const T& t) {
	cerr << t << endl;
}

template <typename T, typename... U>
void dbgh(const T& t, const U&... u) {
	cerr << t << " | ";
	dbgh(u...);
}

#ifdef DEBUG
#define dbg(...)                                           \
	cerr << "L" << __LINE__ << " [" << #__VA_ARGS__ << "]" \
		 << ": ";                                          \
	dbgh(__VA_ARGS__)
#else
#define cerr   \
	if (false) \
	cerr
#define dbg(...) 1412
#endif

#define endl "\n"
#define long int64_t
#define sz(x) int((x).size())

const long mod = 1e9 + 7;

struct DS {
	int n;
	vector<int> psum;

	explicit DS(const vector<int>& arr) : n(sz(arr)), psum(n + 1) {
		for (int i = 0; i < n; i++) {
			psum[i + 1] = psum[i] + (arr[i] != 1);
		}
	}

	bool allz(int l, int r) {
		return psum[r] - psum[l] == r - l;
	}
};

template <typename T>
void md(T& x) {
	if (x >= mod) {
		x -= mod;
	}
}

struct BIT1 {
	int n;
	vector<int> v;

	explicit BIT1(int _n) : n(_n), v(n + 1) {}

	void update(int ind, int x) {
		ind++;
		while (ind <= n) {
			v[ind] += x;
			md(v[ind]);
			ind += ind & -ind;
		}
	}

	int psum(int ind) const {
		int ans = 0;
		while (ind > 0) {
			ans += v[ind];
			md(ans);
			ind -= ind & -ind;
		}
		return ans;
	}
};

struct BIT2 {
	int n;
	vector<BIT1> v;

	explicit BIT2(int _n) : n(_n), v(n + 1, BIT1(n)) {}

	void update(int ind, int y, int val) {
		ind++;
		while (ind <= n) {
			v[ind].update(y, val);
			ind += ind & -ind;
		}
	}

	int psum(int ind, int y) const {
		int ans = 0;
		while (ind > 0) {
			ans += v[ind].psum(y);
			md(ans);
			ind -= ind & -ind;
		}
		return ans;
	}

	int query(int x1, int y1, int x2, int y2) const {
		if (x1 <= x2 && y1 <= y2) {
			x2++;
			y2++;
			return psum(x2, y2) - psum(x1, y2) - psum(x2, y1) + psum(x1, y1);
		}
		return 0;
	}
};

bool eq(int a, int b) {
	return a == b || a == 2 || b == 2;
}

vector<pair<int, int>> nxt(const vector<int>& arr) {
	int n = sz(arr);
	DS cds(arr);
	vector<pair<int, int>> ans(n);
	for (int i = 0; i < n; i++) {
		int mn = 1e9, mx = 0;
		for (int ni = i + 1; ni < n; ni++) {
			if (cds.allz(i + 1, ni)) {
				mn = min(mn, ni);
				mx = max(mx, ni);
			}
		}
		ans[i] = {mn, mx};
	}
	return ans;
}

vector<vector<long>> solve(const vector<int>& s, const vector<int>& t) {
	int n = sz(s);
	DS sds(s), tds(t);
	auto snxt = nxt(s);
	auto tnxt = nxt(t);
	BIT2 ds(n);
	vector<vector<long>> dp(n, vector<long>(n));
	for (int i = n - 1; i >= 0; i--) {
		for (int j = n - 1; j >= 0; j--) {
			if (eq(s[i], 1) && eq(t[j], 1)) {
				auto [l1, r1] = snxt[i];
				auto [l2, r2] = tnxt[j];
				dp[i][j] = sds.allz(i + 1, n) && tds.allz(j + 1, n);
				dp[i][j] += ds.query(l1, l2, r1, r2);
				md(dp[i][j]);
				ds.update(i, j, dp[i][j]);
			}
		}
	}
	return dp;
}

vector<vector<long>> spref(vector<int> s, vector<int> t) {
	reverse(begin(s), end(s));
	reverse(begin(t), end(t));
	auto ans = solve(s, t);
	reverse(begin(ans), end(ans));
	for (auto& a : ans) {
		reverse(begin(a), end(a));
	}
	return ans;
}

vector<int> conv(const string& s) {
	static string sconv = "01?";
	vector<int> ans(sz(s));
	for (int i = 0; i < sz(s); i++) {
		ans[i] = sconv.find(s[i]);
		if ((i & 1) && ans[i] != 2) {
			ans[i] ^= 1;
		}
	}
	return ans;
}

void solve() {
	int n;
	cin >> n;
	string sin, tin;
	cin >> sin >> tin;
	auto s = conv(sin);
	auto t = conv(tin);
	auto suff = solve(s, t);
	auto pref = spref(s, t);
	dbg(suff[1][0], pref[1][0]);
	long ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (eq(s[i], 1) && eq(t[j], 1)) {
				ans += abs(i - j) * pref[i][j] % mod * suff[i][j] % mod;
			}
		}
	}
	cout << ans % mod << endl;
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cin.exceptions(ios::failbit);
	int t = 1;
	cin >> t;
	for (int _ = 1; _ <= t; _++) {
		dbg(_);
		// cout << "Case #" << _ << ": ";
		solve();
	}
}
