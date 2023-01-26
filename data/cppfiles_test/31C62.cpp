#include <bits/stdc++.h>
using namespace std;
vector<array<int, 3>> f(int k, vector<int> &a, int l, int r, int s) {
  if (k == 0) {
    return vector<array<int, 3>>(1);
  }
  int kk = 1 << (k - 1);
  int m;
  for (m = l; m < r; ++m)
    if (a[m] >= s + kk) break;
  vector<array<int, 3>> res(2 * kk);
  vector<array<int, 3>> u = f(k - 1, a, l, m, s);
  vector<array<int, 3>> v = f(k - 1, a, m, r, s + kk);
  for (int i = 0; i < kk; ++i) {
    int x = int(1e9);
    if (m - l > 1) x = min(x, u[i][0]);
    if (r - m > 1) x = min(x, v[i][0]);
    if (m - l > 0 && r - m > 0) x = min(x, v[i][1] + kk - u[i][2]);
    int y = int(1e9);
    int z = -1;
    if (m - l > 0) {
      y = min(y, u[i][1]);
      z = max(z, u[i][2]);
    }
    if (r - m > 0) {
      y = min(y, v[i][1] + kk);
      z = max(z, v[i][2] + kk);
    }
    res[i][0] = x;
    res[i][1] = y;
    res[i][2] = z;
  }
  for (int i = 0; i < kk; ++i) {
    int x = int(1e9);
    if (m - l > 1) x = min(x, u[i][0]);
    if (r - m > 1) x = min(x, v[i][0]);
    if (m - l > 0 && r - m > 0) x = min(x, u[i][1] + kk - v[i][2]);
    int y = int(1e9);
    int z = -1;
    if (m - l > 0) {
      y = min(y, u[i][1] + kk);
      z = max(z, u[i][2] + kk);
    }
    if (r - m > 0) {
      y = min(y, v[i][1]);
      z = max(z, v[i][2]);
    }
    res[i + kk][0] = x;
    res[i + kk][1] = y;
    res[i + kk][2] = z;
  }
  return res;
}
void solve() {
  int n, k;
  scanf("%d%d", &n, &k);
  vector<int> a(n);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
  sort(a.begin(), a.end());
  vector<array<int, 3>> ans = f(k, a, 0, a.size(), 0);
  for (int i = 0; i < (1 << k); ++i) printf("%d ", ans[i][0]);
  printf("\n");
}
int main() {
  solve();
  return 0;
}
