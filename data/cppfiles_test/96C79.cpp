#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
using namespace std;
const int N = 500 + 10;
const int M = 1000010;
const int INF = 0x3f3f3f3f;
const int mod = 998244353;
int dp[N][N], c[N][N], p[N][N];
int qmi(int a, int b) {
  int res = 1;
  while (b) {
    if (b & 1) res = (long long)res * a % mod;
    b >>= 1;
    a = (long long)a * a % mod;
  }
  return res;
}
void solve() {
  int n, first;
  cin >> n >> first;
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= i; j++)
      if (!i || !j)
        c[i][j] = 1;
      else
        c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
  for (int i = 0; i <= 500; i++)
    for (int j = 0; j <= 500; j++) p[i][j] = qmi(i, j);
  for (int i = 0; i <= first; i++) dp[0][i] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= first; j++) {
      for (int k = 0; k <= i; k++) {
        int t = max(j - i + 1, 0);
        int d = min(j, i - 1);
        dp[i][j] = (dp[i][j] + (long long)dp[k][t] * c[i][i - k] % mod *
                                   p[d][i - k] % mod) %
                   mod;
      }
    }
  }
  cout << dp[n][first] << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  cout << fixed << setprecision(10);
  int T(1);
  for (int o = 1; o <= T; o++) {
    solve();
  }
  return 0;
}
