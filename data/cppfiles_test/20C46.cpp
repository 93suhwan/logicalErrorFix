#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
const long long int maxn = 4e2 + 16, md = 1e9 + 7, inf = 2e16;
long long int gcd(long long int a, long long int b) {
  if (a < b) swap(a, b);
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long int tav(long long int n, long long int k) {
  long long int res = 1;
  while (k > 0) {
    if (k & 1) {
      res *= n;
      res %= md;
    }
    n *= n;
    n %= md;
    k >>= 1;
  }
  return res;
}
long long int a[maxn][maxn], ps[maxn][maxn], pr[maxn];
long long int cal(long long int l1, long long int r1, long long int l2,
                  long long int r2, bool c) {
  long long int res = ps[l1][r1];
  if (l2) {
    res -= ps[l2 - 1][r1];
  }
  if (r2) {
    res -= ps[l1][r2 - 1];
  }
  if (l2 && r2) {
    res += ps[l2 - 1][r2 - 1];
  }
  if (!c) {
    long long int h = (r1 - r2 + 1) * (l1 - l2 + 1) - res;
    res = h;
  }
  if (r1 < r2 || l1 < l2) return 0;
  return res;
}
void solve() {
  long long int n, m;
  cin >> n >> m;
  for (long long int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (long long int j = 0; j < m; j++) {
      a[i][j] = (s[j] - '0');
    }
  }
  for (long long int i = 0; i < n; i++) {
    for (long long int j = 0; j < m; j++) {
      ps[i][j] = a[i][j];
      if (i) {
        ps[i][j] += ps[i - 1][j];
      }
      if (j) {
        ps[i][j] += ps[i][j - 1];
      }
      if (i && j) {
        ps[i][j] -= ps[i - 1][j - 1];
      }
    }
  }
  long long int ans = inf;
  for (long long int i = 1; i < n; i++) {
    for (long long int k = i + 2; k < n - 1; k++) {
      long long int d = cal(k, 0, i, 0, 0) + cal(k, m - 1, i, m - 1, 0) +
                        cal(i - 1, m - 2, i - 1, 1, 0) +
                        cal(k + 1, m - 2, k + 1, 1, 0);
      d += cal(k, m - 2, i, 1, 1);
      pr[m - 1] = 0;
      for (long long int j = m - 2; j >= 0; j--) {
        long long int h =
            cal(k, m - 2, i, j, 1) + cal(k + 1, m - 2, k + 1, j, 0) +
            cal(i - 1, m - 2, i - 1, j, 0) + cal(k, m - 1, i, m - 1, 0);
        h -= cal(k, j, i, j, 0);
        pr[j] = max(pr[j + 1], h);
      }
      ans = min(ans, d - pr[3]);
      for (long long int j = 1; j < m - 3; j++) {
        long long int h = cal(k, j, i, 1, 1) + cal(k, 0, i, 0, 0) +
                          cal(i - 1, j, i - 1, 1, 0) +
                          cal(k + 1, j, k + 1, 1, 0);
        h -= cal(k, j, i, j, 0);
        ans = min(ans, d - h - pr[j + 3]);
      }
    }
  }
  cout << ans << '\n';
  return;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int T;
  cin >> T;
  while (T--) solve();
  return 0;
}
