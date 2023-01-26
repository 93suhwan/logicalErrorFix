#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 12;
const int M = 1e5 + 12;
const long long Mod = 998244353;
const long long oo = 1e18;
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
int n, m;
long long ans = 0;
long long dp[N], mu[N], f[51][N], Sum[51][N], cnt[N];
pair<int, int> a[N], b[N];
void Init() {
  mu[1] = 1;
  for (int _ = 1, __ = M, i = _; i <= __; i++)
    for (int j = 2 * i; j <= M; j += i) mu[j] -= mu[i];
}
int main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);
  cin >> n >> m;
  for (int _ = 1, __ = n, i = _; i <= __; i++) cin >> a[i].first >> a[i].second;
  Init();
  for (int _ = m, __ = 1, x = _; x >= __; x--) {
    int s = m / x;
    long long temp = 0;
    for (int _ = 1, __ = n, i = _; i <= __; i++) {
      if (temp == -1) break;
      b[i] = {(a[i].first / x) + 1, a[i].second / x};
      if (a[i].first % x == 0) b[i].first--;
      if (b[i].first > b[i].second) temp = -1;
    }
    if (temp == -1)
      cnt[x] = 0;
    else {
      for (int _ = 1, __ = s, i = _; i <= __; i++) {
        if (i >= b[1].first && i <= b[1].second)
          f[1][i] = 1;
        else
          f[1][i] = 0;
        Sum[1][i] = Sum[1][i - 1] + f[1][i];
      }
      for (int _ = 2, __ = n, i = _; i <= __; i++) {
        for (int _ = 1, __ = s, k = _; k <= __; k++) {
          int l = max(k - b[i].second, 1), r = k - b[i].first;
          if (l > r)
            f[i][k] = 0;
          else
            f[i][k] = (Sum[i - 1][r] - Sum[i - 1][l - 1] + Mod) % Mod;
          Sum[i][k] = (Sum[i][k - 1] + f[i][k]) % Mod;
        }
      }
      cnt[x] = Sum[n][s] % Mod;
    }
    ans = (ans + cnt[x] * mu[x] + Mod * 2) % Mod;
  }
  cout << ans;
}
