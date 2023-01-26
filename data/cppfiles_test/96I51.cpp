#include <bits/stdc++.h>
using namespace std;
const long long N = 1000006, INF = 1e18, P = 998244353;
long long q = 1, n, m, x, y, z, l, r, k, a[N], dp[550][550], po[505][505], b[N],
          f[N], ans, o, u, Ans[N];
vector<pair<int, int> > v[N], V;
string s, t;
long long fac[N], inv[N];
inline long long C(int n, int m) {
  if (n < 0 || m > n) return 0;
  return fac[n] * inv[m] % P * inv[n - m] % P;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);
  inv[0] = fac[0] = inv[1] = fac[1] = 1;
  for (int i = 2; i <= 550; i++) inv[i] = (P - P / i) * inv[P % i] % P;
  for (int i = 2; i <= 550; i++)
    fac[i] = fac[i - 1] * i % P, inv[i] = inv[i - 1] * inv[i] % P;
  for (int i = 1; i <= 500; i++) {
    po[i][0] = 1;
    for (int j = 1; j <= 500; j++) po[i][j] = (po[i][j - 1] * i) % P;
  }
  for (int i = 1; i <= 500; i++) dp[1][i] = 1;
  for (int i = 2; i <= 500; i++) {
    for (int j = i; j <= 500; j++) {
      for (int k = 1; k <= i; k++) {
        dp[i][j] += dp[k][j - i + 1] * po[i - 1][i - k] * C(i, i - k);
      }
      dp[i][j] %= P;
    }
  }
  cin >> n >> x;
  for (int i = 1; i <= x; i++) ans += dp[n][i];
  ans %= P;
  cout << (po[x][n] - ans + P) % P;
}
