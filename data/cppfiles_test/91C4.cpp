#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
inline long long readll() {
  long long x = 0, f = 1;
  char ch = getchar();
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') f = -1;
  for (; isdigit(ch); ch = getchar()) x = x * 10 + ch - '0';
  return x * f;
}
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') f = -1;
  for (; isdigit(ch); ch = getchar()) x = x * 10 + ch - '0';
  return x * f;
}
const int maxn = 1e5 + 7;
int a[maxn];
vector<int> v[2];
int dp[2][maxn];
void solve() {
  int n;
  cin >> n;
  long long ans = 0;
  for (int i = 1; i <= n; i++) a[i] = read();
  for (int i = n; i >= 1; --i) {
    int k = i & 1;
    v[k].push_back(a[i]);
    dp[k][a[i]] = 1;
    int last = a[i];
    for (auto x : v[k ^ 1]) {
      int t = (a[i] + x - 1) / x;
      int st = a[i] / t;
      dp[k][a[i] / t] += dp[k ^ 1][x];
      ans = ans + (1ll) * i * dp[k ^ 1][x] * (t - 1);
      if (last != st) v[k].push_back(st), last = st;
    }
    ans = ans % mod;
    for (auto x : v[k ^ 1]) dp[k ^ 1][x] = 0;
    v[k ^ 1].clear();
  }
  printf("%d\n", ans);
  for (auto x : v[0]) dp[0][x] = 0;
  for (auto x : v[1]) dp[1][x] = 0;
  v[0].clear();
  v[1].clear();
}
signed main() {
  int t;
  cin >> t;
  while (t--) solve();
}
