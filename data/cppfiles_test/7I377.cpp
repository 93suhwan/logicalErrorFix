#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define FOR(i, a, b) for (int i = a; i <= (b); i++)
#define ROF(i, a, b) for (int i = a; i >= (b); i--)
#define y1 awefakhlrv

using pii = pair<int, int>; using vpii = vector<pii>;
using vi = vector<int>; using vvi = vector<vi>;
using ll = long long;
using pll = pair<ll, ll>; using vpll = vector<pll>;
using vll = vector<ll>; using vvll = vector<vll>;

const int N = 200005;
ll gd[N * 4], d[N  * 4], tag[N * 4];
 
void push(int p) {
	if (tag[p] == 0) return;
	gd[p << 1] = d[p], d[p << 1] = d[p];
	gd[p << 1 | 1] = d[p], d[p << 1 | 1] = d[p];
	d[p] = 0, tag[p] = 0;
}
 
void upt(int p, int l, int r, int tl, int tr, ll val) {
	if (tl <= l && r <= tr) {
		gd[p] = val, d[p] = val;
		return;
	}
	int mid = (l + r) / 2;
	push(p);
	if (tl <= mid)
		upt(p << 1, l, mid, tl, tr, val);
	if (tr > mid)
		upt(p << 1 | 1, mid + 1, r, tl, tr, val);
	gd[p] = __gcd(gd[p << 1], gd[p << 1 | 1]);
}

ll qry(int p, int l, int r, int tl, int tr) {
	if (tl <= l && r <= tr) {
        return gd[p];
	}
	ll mid = (l + r) / 2, rt = 0;
	push(p);
	if (tl <= mid)
		rt = qry(p << 1, l, mid, tl, tr);
	if (tr > mid) {
        if (rt == 0) rt = qry(p << 1 | 1, mid + 1, r, tl, tr);
		else rt = __gcd(rt, qry(p << 1 | 1, mid + 1, r, tl, tr));
    }
    return rt;
}

void solve() {
    int n; cin >> n;
    upt(1, 1, n - 1, 1, n - 1, 0);
    vll a(n + 1);
    FOR(i, 1, n)
        cin >> a[i];
    vll dif(n);
    FOR(i, 2, n) {
        dif[i - 1] = abs(a[i] - a[i - 1]);
        upt(1, 1, n - 1, i - 1, i - 1, dif[i - 1]);
    }
    int l = 1, ans = 1;
    FOR(r, 1, n - 1) {
        while (l < r && qry(1, 1, n - 1, l, r) == 1)
            l++;
        // cout << l << ' ' << r << ' ' << qry(1, 1, n - 1, l, r) << endl;
        ans = max(ans, r - l + 2);
    }
    cout << ans << endl;
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}