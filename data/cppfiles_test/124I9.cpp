#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 998244353;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	for (cin >> t; t; t -= 1) {
		int n;
		string a, b;
		cin >> n >> a >> b;
		vector C(2 * n + 1, vector<LL>(2 * n + 1));
		for (int i = 0; i <= 2 * n; i += 1)
			for (int j = 0; j <= i; j += 1)
				C[i][j] = j ? (C[i - 1][j - 1] + C[i - 1][j]) % mod : 1;
		vector p(6, vector<int>(n));
		for (int i = 0; i < n; i += 1) {
			if (i & 1) {
				if (a[i] != '?') a[i] ^= 1;
				if (b[i] != '?') b[i] ^= 1;
			}
			p[0][i] = a[i] == '0';
			p[1][i] = a[i] == '1';
			p[2][i] = a[i] == '?';
			p[3][i] = b[i] == '0';
			p[4][i] = b[i] == '1';
			p[5][i] = b[i] == '?';
			if (i) for (int j = 0; j < 6; j += 1) p[j][i] += p[j][i - 1];
		}
		LL ans = 0;
		auto c = [&](int n, int m) {
			if (n < m) return 0LL;
			if (m < 0) return 0LL;
			return C[n][m];
		};
		auto f = [&](int a0, int a1, int aq, int b0, int b1, int bq) {
			//cout << a0 << " " << a1 << " " << aq << " " << b0 << " " << b1 << " " << bq << " " << c(aq + bq, b1 + bq - a1) << endl;
			return c(aq + bq, b1 + bq - a1);
		};
		for (int i = 0; i < n; i += 1)
			for (int j = 0; j < n; j += 1)
				if (a[i] != '0' and b[j] != '0') {
					ans += abs(i - j)
						* f(i ? p[0][i - 1] : 0, i ? p[1][i - 1] : 0, i ? p[2][i - 1] : 0,
							j ? p[3][j - 1] : 0, j ? p[4][j - 1] : 0, j ? p[5][j - 1] : 0) % mod
						* f(p[0].back() - p[0][i], p[1].back() - p[1][i], p[2].back() - p[2][i],
							p[3].back() - p[3][j], p[4].back() - p[4][j], p[5].back() - p[5][j]) % mod;
				}
		cout << ans % mod << "\n";
	}
	return 0;
}
