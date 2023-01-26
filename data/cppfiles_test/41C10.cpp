#include <bits/stdc++.h>
using namespace std;
int ans[1001][1001];
int n, k, mx;
void solve(int l, int r, int c) {
  int s = r - l + 1;
  mx = max(mx, c);
  if (s <= k) {
    for (int i = l; i < r; i++) {
      for (int j = i + 1; j <= r; j++) {
        ans[i][j] = c;
      }
    }
    return;
  }
  int x = s % k;
  vector<int> a(k, s / k), p(k + 1, 0);
  for (int i = 0; i < x; i++) a[i]++;
  int i = l;
  for (int x : a) {
    solve(i, i + x - 1, c + 1);
    i += x;
  }
  p[0] = l;
  for (int i = 1; i <= k; i++) {
    p[i] = a[i - 1] + p[i - 1];
  }
  for (int i = 0; i < k; i++) {
    for (int j = i + 1; j < k; j++) {
      for (int ii = p[i]; ii <= p[i + 1] - 1; ii++) {
        for (int jj = p[j]; jj <= p[j + 1] - 1; jj++) {
          ans[ii][jj] = c;
        }
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  solve(1, n, 1);
  cout << mx << '\n';
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++) cout << ans[i][j] << " ";
}
