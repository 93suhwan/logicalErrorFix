#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
const int MOD = 998244353;
const int mod = 1e9 + 7;
const long long INF = 8e18;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9')
    x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
  return x * f;
}
long long gcd(long long a, long long b) {
  long long res;
  while (b) {
    res = a % b;
    a = b;
    b = res;
  }
  return a;
}
long long qpow(long long a, long long b, const int mo) {
  long long res = 1;
  while (b) {
    if (b & 1) res = res * a % mo;
    a = a * a % mo;
    b >>= 1;
  }
  return res;
}
long long qpow(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}
long long slow_mul(long long a, long long b, long long k) {
  long long res = 0;
  while (b) {
    if (b & 1) res = (res + a) % k;
    a = a * 2 % k;
    b >>= 1;
  }
  return res;
}
long long lcm(long long a, long long b) { return a * b / gcd(a, b); }
long long ex_gcd(long long a, long long b, long long &x, long long &y) {
  if (!b) {
    x = 1;
    y = 0;
    return a;
  }
  long long res = ex_gcd(b, a % b, y, x);
  y -= a / b * x;
  return res;
}
void init(const int mo = mod) {}
int n;
int a[maxn];
int dp[2][maxn];
vector<int> v[2];
void solve() {
  cin >> n;
  long long ans = 0;
  bool f = 1;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; f && i <= n; ++i) {
    if (a[i] < a[i + 1])
      continue;
    else
      f = 0;
  }
  if (f == 0) {
    int cur = 1;
    for (int i = n; i >= 1; --i, cur ^= 1) {
      v[cur].push_back(a[i]);
      dp[cur][a[i]] = 1;
      int last = a[i];
      for (int &x : v[cur ^ 1]) {
        int y = dp[cur ^ 1][x];
        int res = (a[i] + x - 1) / x;
        int st = a[i] / res;
        ans += (long long)(res - 1) * y * i;
        dp[cur][st] += y;
        if (last != st) {
          v[cur].push_back(st);
          last = st;
        }
      }
      for (int &x : v[cur ^ 1]) dp[cur ^ 1][x] = 0;
      v[cur ^ 1].clear();
      if (ans >= MOD) ans %= MOD;
    }
  }
  cout << ans << '\n';
  for (int &x : v[0]) dp[0][x] = 0;
  for (int &y : v[1]) dp[1][y] = 0;
  v[0].clear();
  v[1].clear();
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int _ = 1;
  cin >> _;
  while (_-- > 0) solve();
  return 0;
}
