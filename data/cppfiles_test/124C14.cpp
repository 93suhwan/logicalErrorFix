#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
void _debug() { std::cerr << std::endl; }
template <typename T, typename... U>
void _debug(T t, U... args) {
  std::cerr << " " << t;
  _debug(args...);
}
const int maxn = 2000 + 10;
const int mod = 1e9 + 7;
void add(int &x, int v) {
  x += v;
  if (x >= mod) x -= mod;
}
char s[maxn], t[maxn];
int dp1[maxn][maxn * 2], dp2[maxn][maxn * 2], n;
void solve() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    memset(dp1[i], 0, sizeof(dp1[i]));
    memset(dp2[i], 0, sizeof(dp2[i]));
  }
  scanf("%s%s", s + 1, t + 1);
  for (int i = 1; i <= n; i++) s[i] = s[i] - '0', t[i] = t[i] - '0';
  for (int i = 2; i <= n; i += 2) {
    s[i] ^= 1;
    t[i] ^= 1;
  }
  for (int i = 1; i <= n; i++) {
    if (s[i] != 0 && s[i] != 1) s[i] = '?';
    if (t[i] != 0 && t[i] != 1) t[i] = '?';
  }
  dp1[0][0 + maxn] = 1;
  for (int i = 1; i <= n; i++) {
    for (int b = 0; b < 4; b++) {
      int x = b >> 1, y = b & 1;
      if (s[i] != '?' && s[i] != x) continue;
      if (t[i] != '?' && t[i] != y) continue;
      int d = x - y;
      for (int diff = -i; diff <= i; diff++) {
        add(dp1[i][diff + maxn], dp1[i - 1][diff + maxn - d]);
      }
    }
  }
  reverse(s + 1, s + n + 1);
  reverse(t + 1, t + n + 1);
  dp2[0][0 + maxn] = 1;
  for (int i = 1; i <= n; i++) {
    for (int b = 0; b < 4; b++) {
      int x = b >> 1, y = b & 1;
      if (s[i] != '?' && s[i] != x) continue;
      if (t[i] != '?' && t[i] != y) continue;
      int d = x - y;
      for (int diff = -i; diff <= i; diff++) {
        add(dp2[i][diff + maxn], dp2[i - 1][diff + maxn - d]);
      }
    }
  }
  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int diff = -i; diff <= i; diff++) {
      ans += 1ll * dp1[i][diff + maxn] * dp2[n - i][-diff + maxn] % mod *
             abs(diff) % mod;
    }
  }
  for (int i = 1; i <= n; i++)
    for (int j = -i; j <= i; j++) 42;
  for (int i = 1; i <= n; i++)
    for (int j = -i; j <= i; j++) 42;
  printf("%lld\n", ans % mod);
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
}
