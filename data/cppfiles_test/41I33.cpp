#include <bits/stdc++.h>
using namespace std;
long long n, m, k;
int ans[1010][1010];
int cnt = 0;
void dfs(int l, int r, int c) {
  if (l == r) return;
  int m = r - l + 1;
  if (m <= k) {
    for (int i = l; i < r; i++) {
      for (int j = i + 1; j <= r; j++) {
        ans[i][j] = ans[j][i] = c;
      }
    }
    cnt = max(cnt, c);
    return;
  }
  int mid = (l + r) / 2;
  for (int i = l; i <= mid; i++) {
    for (int j = mid + 1; j <= r; j++) {
      ans[i][j] = ans[j][i] = c;
    }
  }
  c++;
  dfs(l, mid, c);
  dfs(mid + 1, r, c);
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
