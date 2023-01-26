#include <bits/stdc++.h>
using namespace std;
int ans[1005][1005];
void dfs(int l, int r, int k, int q) {
  if (l == r) return;
  int sz = (r - l + 1) / k;
  if (r - l + 1 < k) {
    for (int i = l; i <= r; i++) {
      for (int j = i + 1; j <= r; j++) ans[i][j] = q;
    }
    return;
  }
  for (int c = 1; c <= k; c++) {
    int i = l + sz * c - 1, j = i - sz + 1;
    if (c == k) i = r;
    dfs(j, i, k, q - 1);
    for (int p = j; p <= i; p++) {
      for (int s = i + 1; s <= r; s++) {
        ans[p][s] = q;
      }
    }
  }
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int n, k;
  cin >> n >> k;
  int r = ceil(log(n) / log(k));
  dfs(1, n, k, r);
  cout << r << '\n';
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++) cout << ans[i][j] << ' ';
  return 0;
}
