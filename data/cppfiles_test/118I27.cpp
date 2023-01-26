#include <bits/stdc++.h>
using namespace std;

#define EDEBUG
#if defined(LOCAL) && defined(EDEBUG)
#include "includes/debug.cpp"
#else
#define debug(...)
#define dbgarr(...)
#define dbgline
#endif

/*input
5
1 2
3 2
4 2
2 5
*/
/*input
5
1 2
2 3
3 4
4 5
*/
/*input
20
20 19
20 4
12 4
5 8
1 2
20 7
3 10
7 18
11 8
9 10
17 10
1 15
11 16
14 11
18 10
10 1
14 2
13 17
20 6
*/
const long long mod = 998244353;
const int maxn = 250010;
vector<int> gra[maxn];
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;

	for (int i = 1; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		gra[a].push_back(b);
		gra[b].push_back(a);
	}

	long long d[n][n+1] = {};

	d[0][0] = 1;
	d[0][1] = gra[0].size();

	for (int i = 1; i < n; ++i) {
		long long ch = gra[i].size() - 1;

		for (int j = 0; j <= n; ++j) {
			d[i][j] = ((j > 0 ? d[i - 1][j - 1] * ch : 0) +  d[i - 1][j]) % mod;
		}
	}

	long long ans = 0;
	long long fakt[n + 1];
	fakt[0] = 1;

	for (int i = 1; i <= n; ++i) {
		fakt[i] = (fakt[i - 1] * i) % mod;
	}

	for (int i = 0; i <= n; ++i) {
		ans += (i % 2 == 0 ? 1 : -1) * fakt[n - i] * d[n - 1][i];
		ans %= mod;
	}

	cout << ans % mod;
}