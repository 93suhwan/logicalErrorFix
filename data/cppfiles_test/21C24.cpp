#include <bits/stdc++.h>
using namespace std;
struct custHash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};
int fact[110], C[110][110];
int n, m, k, p;
long long dp[110][110][110];
long long f(int n, int k, int m) {
  long long &res = dp[k][n][m];
  if (res != -1) return res;
  res = 0;
  if (k > n) return 0;
  if (!n) return res = 1;
  if (m == 1) {
    return res = (k == 1 ? fact[n] : 0);
  }
  for (int i = 0, _i = (n); i < _i; ++i) {
    int r = n - i - 1;
    long long tmp = 0;
    for (int j = (max(0, k + i + 1 - n)), _j = (min(i + 1, k + 1)); j < _j;
         ++j) {
      tmp = (tmp + 1LL * f(i, j, m - 1) * f(r, k - j, m - 1)) % p;
    }
    res = (res + tmp * C[n - 1][i]) % p;
  }
  return res;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m >> k >> p;
  fact[0] = 1;
  for (int i = 0, _i = (n); i < _i; ++i) C[i][0] = 1, C[i][i] = 1;
  for (int i = (1), _i = (n + 1); i < _i; ++i) {
    fact[i] = 1LL * fact[i - 1] * i % p;
    for (int j = (1), _j = (i); j < _j; ++j)
      C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % p;
  }
  memset(dp, -1, sizeof dp);
  cout << f(n, k, m) << endl;
  return 0;
}
