#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int P(int a, int b) {
  if (!b) return 1;
  if (b & 1) return 1ll * P(a, b - 1) * a % mod;
  int c = P(a, b >> 1);
  return 1ll * c * c % mod;
}
unordered_map<int, int> ma;
int D(int a, int b) {
  if (!ma[b]) {
    ma[b] = P(b, mod - 2);
  }
  return 1ll * a * ma[b] % mod;
}
vector<int> _F(1, 1);
int F(int a) {
  while (_F.size() <= a) _F.push_back(1ll * _F.back() * _F.size() % mod);
  return _F[a];
}
int C(int a, int b) {
  return (a < b ? 0 : D(F(a), 1ll * F(a - b) * F(b) % mod));
}
const int N = 502;
int Px[N][N];
int d(int k, int n) { return 1ll * C(n, k) * Px[n - 1][k] % mod; }
int n, x, dp[N][N];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      Px[i][j] = P(i, j);
    }
  }
  cin >> n >> x;
  for (int i = 2; i <= n; ++i) {
    for (int j = 1; j <= x; ++j) {
      if (j < i) {
        dp[i][j] = P(j, i);
      } else {
        for (int k = 0; k < i; ++k) {
          (dp[i][j] += 1ll * dp[i - k][j - i + 1] * d(k, i) % mod) %= mod;
        }
        (dp[i][j] += d(i, i)) %= mod;
      }
    }
  }
  cout << dp[n][x] << endl;
  return 0;
}
