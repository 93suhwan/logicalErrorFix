#include <bits/stdc++.h>
using namespace std;
template <class c>
struct rge {
  c b, e;
};
template <class c>
rge<c> range(c i, c j) {
  return rge<c>{i, j};
}
template <class c>
auto dud(c *x) -> decltype(cerr << *x, 0);
template <class c>
char dud(...);
struct debug {
  template <class c>
  debug &operator<<(const c &) {
    return *this;
  }
};
const int MOD = 998244353;
const long long inf = 1e9 + 111000;
const int MX = 1e5 + 5;
const int dx[] = {0, 1, -1, 0};
const int dy[] = {1, 0, 0, -1};
template <class T>
bool ckmin(T &a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template <class T>
bool ckmax(T &a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
int n, x;
long long dp[501][501];
long long C[501][501];
long long Pow(int x, int y) {
  if (y == 0) return 1;
  long long ans = Pow(x, y / 2);
  if (y & 1) return (long long)((ans * ans % MOD) * x) % MOD;
  return (long long)(ans * ans % MOD);
}
int DP(int n, int x) {
  if (n == 0) return 1;
  if (x < 0 || n == 1) return 0;
  long long &res = dp[n][x];
  if (res != -1) return res;
  res = 0;
  int val = min(n - 1, x);
  for (int i = 0; i <= n; ++i) {
    res =
        (res + (C[i][n] * (DP(n - i, x - (n - 1))) % MOD) * Pow(val, i) % MOD) %
        MOD;
    debug() << " ["
            << "res"
               ": "
            << (res) << "] ";
  }
  return res;
}
void Read() {
  cin >> n >> x;
  C[0][0] = 1;
  for (int i = 1; i <= n; ++i) {
    C[0][i] = 1;
    for (int j = 1; j <= i; ++j) {
      C[j][i] = (C[j][i - 1] + C[j - 1][i - 1]) % MOD;
    }
  }
}
void Solve() {
  memset(dp, (-1), sizeof dp);
  cout << DP(n, x) << '\n';
}
int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  int i = 1;
  while (t--) {
    Read();
    Solve();
    i++;
  }
  return 0;
}
