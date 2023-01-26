#include <bits/stdc++.h>
using namespace std;
long long n, m, k;
int ans[1010][1010];
int cnt = 0;
void dfs(int l, int r, int c) {
  if (l == r) return;
  int m = r - l + 1;
  if (r - l + 1 <= k) {
    for (int i = l; i < r; i++) {
      for (int j = i + 1; j <= r; j++) {
        ans[i][j] = ans[j][i] = c;
      }
    }
    cnt = max(cnt, c);
    return;
  }
  int d = m / k;
  int lf = m % k;
  for (int i = 0; i < lf; i++) {
    dfs(l + i * (d + 1), l + i * (d + 1) + d, c + 1);
    for (int j = l + i * (d + 1); j <= l + i * (d + 1) + d; j++) {
      for (int p = l + i * (d + 1) + d + 1; p <= r; p++) {
        ans[j][p] = ans[p][j] = c;
      }
    }
  }
  for (int i = 0; i < k - lf; i++) {
    dfs(lf * (d + 1) + l + i * d, lf * (d + 1) + l + (i + 1) * d - 1, c + 1);
    for (int j = lf * (d + 1) + l + i * d; j < lf * (d + 1) + l + (i + 1) * d;
         j++) {
      for (int p = lf * (d + 1) + l + (i + 1) * d; p <= r; p++) {
        ans[j][p] = ans[p][j] = c;
      }
    }
  }
}
void solve() {
  cin >> n >> k;
  dfs(1, n, 1);
  cout << cnt << "\n";
  for (int i = 1; i < n; i++) {
    for (int j = i + 1; j <= n; j++) {
      cout << ans[i][j] << " ";
    }
  }
  cout << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T = 1;
  while (T--) solve();
}
