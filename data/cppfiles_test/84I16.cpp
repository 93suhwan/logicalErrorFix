//Challenge: Accepted
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <stack>
#include <set>
#include <assert.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
using namespace __gnu_pbds;
void debug() {cout << endl;}
template <class T, class ...U> void debug(T a, U ... b) { cout << a << " "; debug(b...);}
template <class T> void pary(T l, T r) {
	while (l != r) {cout << *l << " ";l++;}
	cout << endl;
}
#define ll long long
#define maxn 100005
#define mod 1000000007
#define pii pair<int, int>
#define ff first
#define ss second
#define io ios_base::sync_with_stdio(0);cin.tie(0);
const int inf = 1<<30;
int dp[maxn][19];
vector<int> di[maxn], pnt[maxn];

int phi[maxn], mark[maxn]; //phi[i]: sum of euler phi(j) for j <= i
int brute(int l, int r) {
	int ret = 0;
	for (int i = l;i <= r;i++) ret += phi[r/i];
	return ret;
}
int calc(int l, int r) { //c(l, r);
	int prv = r + 1, ret = 0;
	for (int i:pnt[r]) {
		ret += phi[r/i] * (prv - max(i, l));
		prv = i;
		if (i <= l) break;
	}	
	return ret;
}

void solve(int j, int l, int r, int ql, int qr) { //[l, r), [ql, qr)
	if (r <= l || qr <= ql) return;
	int m = (l + r) / 2, st = min(m - 1, qr - 1);	
	int cur = calc(st + 1, m), ind = st;
	dp[m][j] = inf;
	for (int k = st;k >= ql;k--) {
		if (cur + dp[k][j-1] < dp[m][j]) {
			dp[m][j] = cur + dp[k][j-1];
			ind = k;
		}
		if (k) cur += phi[m/k];
	}
	solve(j, l, m, ql, ind + 1), solve(j, m + 1, r, ind, qr);
}
int main() {
	io
	for (int i = 1;i < maxn;i++) {
		for (int j = i;j < maxn;j += i) di[j].push_back(i);
		phi[i] = 1;
	}	
	for (int i = 2;i < maxn;i++) {
		if (!mark[i]) {
			phi[i] = i - 1;
			for (int j = 2 * i;j < maxn;j += i) {
				int tmp = j / i;
				phi[j] *= i - 1;
				while (tmp % i == 0) {
					phi[j] *= i;	
					tmp /= i;
				}
				mark[j] = 1;
			}
		}	
	}	
	for (int i = 2;i < maxn;i++) phi[i] += phi[i-1];
	for (int i = 1;i < maxn;i++) {
		int prv = 0;
		for (int j = 1;j <= i;j++) {
			int cur = i / j;
			if (cur != prv) {
				pnt[i].push_back(i / (cur + 1) + 1);			
			} else {
				for (int k = prv - 1;k > 0;k--) pnt[i].push_back(i / (k + 1) + 1); 
				break;
			}
			prv = cur;
		}
		reverse(pnt[i].begin(), pnt[i].end());
	}
	for (int i = 1;i < maxn;i++) dp[i][0] = calc(1, i);
	for (int i = 1;i < 19;i++) solve(i, 1, maxn, 0, maxn);
	/*
	for (int i = 1;i < maxn;i++) {
		for (int j = i + 1;j < maxn;j++) {
			if (calc(i, j) != brute(i, j)) {
				debug(i, j, calc(i, j), brute(i, j));
				pary(pnt[j].begin(), pnt[j].end());
				return 0;
			}
		}
		debug(i);
	}	
	*/	
	/*
	for (int i = 1;i < maxn;i++) {
		for (int j:di[i]) b.modify(j, phi[i/j]);
		ll tot = b.query(i);
		dp[i][0] = tot;
		for (int j = 1;j < 21;j++) {
			ll cur = dp[from[j]][j-1] - b.query(from[j]);	
			while (from[j] < i - 1) {
				ll nxt = dp[from[j]+1][j-1] - b.query(from[j]+1);
				if (nxt <= cur) from[j]++, cur = nxt;
				else {
					break;
				}
			}
			dp[i][j] = cur + tot;
			for (int k = -50;k < 50;k++) {
				if (from[j] + k >= i || from[j] + k < j) continue;
				ll tmp = tot + dp[from[j]+k][j-1] - b.query(from[j]+k);
				dp[i][j] = min(dp[i][j], tmp);
			}
			//debug(i, j, from[j]);
		}
	}
	*/
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		k--;
		if (k > 18) cout << n << "\n";
		else {
			cout << dp[n][k] << "\n";
		}
	}
}
