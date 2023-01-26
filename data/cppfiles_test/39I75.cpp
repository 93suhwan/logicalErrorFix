#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#endif

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

#define endl "\n"
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef std::vector<vector<int> > vvi;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<pi> vpi;
typedef vector<pll> vpll;
typedef vector<vll> vvll;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<vector<double>> vvd;
typedef vector<ld> vld;
typedef vector<vld> vvld;
typedef vector<bool> vb;
typedef vector<vb> vvb;


#define rep(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define repi(i, a, b) for (int i = (int)(a); i >= (int)(b); i--)
#define pb push_back
#define fi first
#define se second
#define all(a) a.begin(), a.end()
#define sz(a) (int)(a.size())
#define umin(a, x) a = min(a, x)
#define umax(a, x) a = max(a, x)

ll nxt() {
	ll x; cin >> x; return x;
}

void setIO(string s) {
	#ifndef LOCAL
	ios_base::sync_with_stdio(0); cin.tie(0); 
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
	#endif
}

void yes() {
	cout << "YES\n";
}

void no() {
	cout << "NO\n";
}


const ll mod = 1e9 + 7;
const ll INF = 2e9;

int x1, y1, x2, y2; 
int W, H;
int w, h;
int go(int X1, int X2, int Y1, int Y2) {
	int left = max(x1, X1);
	int right = min(x2, X2);
	int down = max(y1, Y1);
	int up = min(y2, Y2);
	int dx = (w + x2 - x1 > W ? INF : max(0, right - left));
	int dy = (h + y2 - y1 > H ? INF : max(0, up - down));
	return min(dx, dy);
}

void solve() {
	cin >> W >> H;
	cin >> x1 >> y1 >> x2 >> y2;
	cin >> w >> h;

	if (w + x2 - x1 > W and h + y2 - y1 > H) {
		cout << -1 << endl;
		return;
	}

	int ans = min({go(0, w, 0, h), go(0, w, H - h, H), go(W - w, W, 0, h), go(W - w, W, H - h, H)});
	cout << double(ans) << endl;
}	

	
int32_t main(){
	// setIO("trapped");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cout << fixed << setprecision(10);

	int T = 1;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		// cout << "Case #" << tc << ": ";
		solve();
	}
}
