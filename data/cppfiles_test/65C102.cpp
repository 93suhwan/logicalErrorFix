#include <bits/stdc++.h>
using namespace std;
const int N = 50, M = 1e5 + 1, MOD = 998244353;
int l[N], r[N];
long long f[M];
long long g[N + 1][M];
int main() {
  cin.tie(0), cout.tie(0);
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> l[i] >> r[i];
  for (int i = 1; i <= m; i++) {
    int res = m;
    vector<int> cnt;
    for (int j = 0; j < n; j++) {
      int dt = (l[j] + i - 1) / i;
      res -= dt * i;
      if (dt * i > r[j])
        res = -1;
      else
        cnt.push_back((r[j] - dt * i) / i + 1);
    }
    if (res < 0)
      f[i] = 0;
    else {
      int left = res / i;
      for (int j = 0; j <= left; j++) g[0][j] = 1;
      for (int k = 0; k < n; k++) {
        g[k + 1][0] = g[k][0];
        for (int j = 0; j <= left; j++) {
          g[k + 1][j] = g[k + 1][j - 1] + g[k][j];
          if (j - cnt[k] >= 0) g[k + 1][j] -= g[k][j - cnt[k]];
          g[k + 1][j] %= MOD;
        }
      }
      f[i] = g[n][left];
    }
  }
  for (int i = m; i >= 1; i--)
    for (int j = i + i; j <= m; j += i) f[i] = (f[i] - f[j]) % MOD;
  cout << (f[1] + MOD) % MOD << "\n";
}
