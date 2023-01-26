#include <bits/stdc++.h>
using namespace std;
inline long long rd() {
  int x = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') ch = getchar();
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x;
}
const int MOD = 998244353;
inline void add(int &a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
}
inline int mul(int a, int b) { return (long long)a * b % MOD; }
inline int ksm(int a, int b = MOD - 2, int m = MOD) {
  int ans = 1;
  int base = a;
  while (b) {
    if (b & 1) ans = mul(ans, base);
    base = mul(base, base);
    b >>= 1;
  }
  return ans;
}
const int maxn = 1e5 + 5;
int dp[2][maxn];
inline void solve() {
  int n = rd();
  vector<int> a(n + 1);
  vector<int> v[2];
  for (int i = 1; i <= n; i++) a[i] = rd();
  int ans = 0;
  for (int i = n; i >= 1; i--) {
    int k = i & 1;
    v[k].push_back(a[i]);
    dp[k][a[i]] = 1;
    int lst = a[i];
    for (auto it : v[k ^ 1]) {
      int y = dp[k ^ 1][it];
      int cnt = (a[i] + it - 1) / it;
      add(dp[k][a[i] / cnt], y);
      add(ans, mul(y, mul(i, cnt - 1)));
      if (lst != a[i] / cnt) {
        v[k].push_back(a[i] / cnt);
        lst = a[i] / cnt;
      }
    }
    for (auto it : v[k ^ 1]) dp[k ^ 1][it] = 0;
    v[k ^ 1].clear();
  }
  for (auto it : v[0]) dp[0][it] = 0;
  for (auto it : v[1]) dp[1][it] = 0;
  printf("%d\n", ans);
}
int main() {
  int T = rd();
  while (T--) solve();
}
