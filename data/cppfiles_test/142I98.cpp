#include<bits/stdc++.h>
//#define double long double
//T.erase(unique(T.begin(),T.end()),T.end());
//written by djs100201
#define all(v) v.begin(),v.end()

using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using PP = pair<ll, P>;
const ll n_ = 1e5+ 100, inf = (ll)2e9 * (ll)1e9 + 7, mod = 1e9 + 7, sqrtN = 320;

ll dy[4] = { -1,0,1,0 }, dx[4] = { 0,1,0,-1 };
ll n, m, k, tc = 1, a, b, c, d, sum, x, y, z, w, base, ans, q;
ll gcd(ll x, ll y) {
	if (!y)return x;
	return gcd(y, x % y);
}
vector<ll>v[n_];
void solve() {
	cin >> n >> m;
	priority_queue<P, vector<P>, greater<>>pq;
	vector<vector<ll>>A(n + 1);
	for (int i = 1; i <= n; i++)A[i].resize(m + 1);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)cin >> A[i][j];
	//A[i][j]는 i번째 가게에서 j번째 친구 선물 만족도
	//가게를 최대 n-1개 골라서 
	vector<ll>ANS;
	vector<P>idx;
	map<ll, ll>mp;
	for (int j=1; j<=m; j++) {
		x = -inf, y = 0;
		for (int i = 1; i <= n; i++) {
			if (A[i][j] > x) {
				x = A[i][j];
				y = i;
			}
		}
		mp[j] = y;
		ANS.push_back(x);
		idx.push_back({ y,j });
	}
	sort(all(idx));
	sort(all(ANS));
	bool ok = false;
	for (int i = 1; i < idx.size(); i++)if (idx[i - 1].first == idx[i].first)ok = true;
	if (ok) {
		cout << ANS[0];
	}
	else {
		ans = 0;
		for (int i = 1; i <=m; i++) {
			x = 0, y = mp[i];
			for (auto nxt : idx) {
				if (nxt.second == y)continue;
				x = max(x, A[nxt.second][i]);
			}
			ans = max(ans, min(x, ANS[0]));
		}
		cout << ans;
	}
	cout << '\n';
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> tc;
	while (tc--)solve();
}