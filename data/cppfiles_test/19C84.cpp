#include <bits/stdc++.h>
const int N = 1e4 + 2;
const long long MOD = 998244353;
const int oo = 1e9;
using namespace std;
int T, n, a[N], F[N][2001];
void solve() {
  cin >> n;
  for (int i = 0; i <= n; i++) {
    if (i) cin >> a[i];
    for (int j = 0; j <= 2000; j++) F[i][j] = oo;
  }
  F[0][0] = 0;
  for (int i = 0; i <= n - 1; i++) {
    for (int j = 0; j <= 2000; j++) {
      if (F[i][j] == oo) continue;
      F[i + 1][max(0, j - a[i + 1])] =
          min(F[i + 1][max(0, j - a[i + 1])], F[i][j] + max(0, a[i + 1] - j));
      F[i + 1][j + a[i + 1]] =
          min(F[i + 1][j + a[i + 1]],
              (a[i + 1] <= F[i][j] - j ? F[i][j] : a[i + 1] + j));
    }
  }
  int res = oo;
  for (int j = 0; j <= 2000; j++) res = min(res, F[n][j]);
  cout << res << '\n';
}
int main() {
  cin >> T;
  while (T--) {
    solve();
  }
}
