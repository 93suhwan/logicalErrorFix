#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
const int N = 'z' - 'a' + 1, M = 10000000;
const int oo = 0x3f3f3f3f, mod = (119 << 23) + 1;
int n, m, t;
ll res;
string s;
array<ll, M> ans;
array<array<int, N>, N> a, cnt;
array<ll, M> dp;
void dfs(int x, const int fa) {
  if (x == n) {
    dp[fa] = 1;
    for (int i = 0; i < N; i++) {
      dp[fa] = dp[fa] * a[n][i] % mod;
    }
    return;
  }
  for (int i = 0; i < N; i++) {
    a[x + 1][i] = a[x][i];
  }
  dfs(x + 1, fa);
  for (int i = 0; i < N; i++) {
    a[x + 1][i] = min(a[x][i], cnt[x][i] + 1);
  }
  dfs(x + 1, fa ^ (1 << x));
}
auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n;
  m = 1 << n;
  dp.fill(oo);
  for (int i = 0; i < n; i++) {
    cin >> s;
    for (char j : s) {
      cnt[i][j - 'a']++;
    }
  }
  for (int i = 0; i < N; i++) {
    a[0][i] = oo;
  }
  dfs(0, 0);
  for (int i = 0; i + i < m; i++) {
    swap(dp[i], dp[m - 1 - i]);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if ((j & (1 << i)) != 0) {
        dp[j] = (dp[j] - dp[j ^ (1 << i)] + mod) % mod;
      }
    }
  }
  for (int i = 0; i + i < m; i++) {
    swap(dp[i], dp[m - 1 - i]);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if ((j & (1 << i)) != 0) {
        dp[j] = (dp[j] + dp[j ^ (1 << i)]) % mod;
      }
    }
  }
  for (int i = 0; i < m; i++) {
    ans[i] = (dp[m - 1] - dp[(m - 1) ^ i] + mod) % mod;
  }
  for (int i = 0; i < m; i++) {
    int x = 0;
    int y = 0;
    for (int j = 0; j < n; j++) {
      if ((i & (1 << j)) != 0) {
        x++;
        y += (j + 1);
      }
    }
    res ^= ans[i] * x * y;
  }
  cout << res << endl;
  return 0;
}
