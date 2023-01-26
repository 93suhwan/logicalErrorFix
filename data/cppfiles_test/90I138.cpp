#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vec vector
#define sz(a) ((int) a.size())
#define rep(i, a, b) for (int i = (a); i < (b); ++i)

const ll INF = 1e16;

int a[200005];
pair<int, int> iv[200005];
array<array<ll, 4>, 200005> dp;
/*
	left - no return
	left - return
	right - no return
	righ - return
*/

void solve(int case_id) {
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 1; i <= m; ++i) {
		cin >> iv[i].first >> iv[i].second;
	}
	sort(iv + 1, iv + 1 + m, [](auto lhs, auto rhs) {
		return lhs.first != rhs.first ?
					lhs.first < rhs.first :
					lhs.second > rhs.second;
	});
	sort(a + 1, a + 1 + n);
	int tail = 0, j = 1;

	// visited
	for (int i = 1; i <= m; ++i) {
		while (j <= n && a[j] < iv[i].first) j++;
		if (j > n || a[j] > iv[i].second) {
			iv[++tail] = iv[i];
		}
	}
	m = tail;

	tail = 0;
	deque<int> stk;
	for (int i = 1; i <= m; ++i) {
		while (!stk.empty() && iv[stk.back()].second >= iv[i].second) stk.pop_back();
		stk.push_back(i);
	}
	while (!stk.empty()) {
		int u = stk.front(); stk.pop_front();
		iv[++tail] = iv[u];
	}
	m = tail;
	int pj = -1, pk = -1;
	for (int i = 1; i <= m; ++i) {
		int j = lower_bound(a + 1, a + 1 + n, iv[i].second) - a;
		int k = lower_bound(a + 1, a + 1 + n, iv[i].first) - a - 1;
		dp[i].fill(INF);
		if (j <= n) { // right
			int nxt = iv[i+1].second;
			if (i == m || (i < m && nxt > a[j])) {
				dp[i][2] = min({dp[i-1][0], dp[i-1][1], dp[i-1][2], pj == j ? INF : dp[i-1][3]}) + abs(a[j] - iv[i].second);
				dp[i][3] = min({dp[i-1][0], dp[i-1][1], pj == j ? INF : dp[i-1][2], dp[i-1][3]}) + 2 * abs(a[j] - iv[i].second);
			} else {
				dp[i][2] = min({dp[i-1][0], dp[i-1][1], dp[i-1][2], pj == j ? INF : dp[i-1][3]}) + abs(nxt - iv[i].second);
				dp[i][3] = min({dp[i-1][0], dp[i-1][2], pj == j ? INF : dp[i-1][2], dp[i-1][3]}) + 2 * abs(nxt - iv[i].second);
			}
		}

		if (k >= 1) { // left
			int pr = iv[i-1].first;
			if (i == 1 || (i > 1 && pr < a[k])) {
				dp[i][0] = min({(pj == k ? INF : dp[i-1][2]), dp[i-1][3], dp[i-1][0], dp[i-1][1]}) + abs(a[k] - iv[i].first);
				dp[i][1] = min({dp[i-1][2], dp[i-1][3], dp[i-1][0], dp[i-1][1]}) + 2 * abs(a[k] - iv[i].first);
			} else {
				dp[i][0] = min({dp[i-1][0]}) + abs(pr - iv[i].first);
				dp[i][1] = min({dp[i-1][1]}) + 2 * abs(pr - iv[i].first);
			}
		}
		pj = j, pk = k;
		// cout << dp[i][0] << ' ' << dp[i][1] << ' ' << dp[i][2] << ' ' << dp[i][3] << endl;
	}

	cout << min({dp[m][0], dp[m][1], dp[m][2], dp[m][3]}) << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; ++i) solve(i);
}