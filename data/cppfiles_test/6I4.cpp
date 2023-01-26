#include <bits/stdc++.h>
using namespace std;
int n;
int a[100005];
int tmp[100005];
int sl = 0;
int dp[100005];
int zs = 0;
int sz[1200005];
long long dd[100005];
int sol() {
  zs = 0;
  for (int i = 1; i <= sl; ++i) {
    int u = tmp[i];
    for (int j = 1; j * j <= u; ++j)
      if (u % j == 0) {
        sz[++zs] = j;
        if (j * j != u) sz[++zs] = u / j;
      }
  }
  sort(sz + 1, sz + zs + 1);
  int cnt = 0;
  sz[zs + 1] = 0;
  for (int i = 1; i <= zs; ++i) {
    cnt++;
    if (sz[i] != sz[i + 1]) {
      dd[sz[i]] = 1ll * cnt * (cnt - 1) / 2;
      dd[sz[i]] %= 1000000007;
      cnt = 0;
      for (int j = 1; j * j <= sz[i]; ++j)
        if (sz[i] % j == 0) {
          if (j != sz[i]) dd[j] = (dd[j] - dd[sz[i]] + 1000000007) % 1000000007;
          if (n / j != j && j != 1)
            dd[n / j] = (dd[n / j] - dd[sz[i]] + 1000000007) % 1000000007;
        }
    }
  }
  int res = 0;
  for (int i = 1; i <= zs; ++i)
    if (sz[i] != sz[i + 1]) {
      res = (res + (1ll * dd[sz[i]] * sz[i]) % 1000000007) % 1000000007;
      dd[sz[i]] = 0;
    }
  return res;
}
int main() {
  ios ::sync_with_stdio(false);
  cin >> n;
  int ans = 0;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= n; ++i) {
    sl = 0;
    for (int j = 1; i * j <= n; ++j) tmp[++sl] = a[i * j];
    dp[i] = sol();
  }
  for (int i = 1; i <= n; ++i)
    for (int j = 2; i * j <= n; ++j)
      dp[i] = (dp[i] - dp[i * j] + 1000000007) % 1000000007;
  for (int i = 1; i <= n; ++i)
    ans = (ans + (1ll * i * dp[i]) % 1000000007) % 1000000007;
  ans = (2ll * ans) % 1000000007;
  for (int i = 1; i <= n; ++i)
    ans = (ans + (1ll * a[i] * i) % 1000000007) % 1000000007;
  cout << ans;
}
