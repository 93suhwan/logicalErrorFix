#include <bits/stdc++.h>
using namespace std;
template <typename T>
const T& minimum(const T& n) {
  return n;
}
template <typename T>
const T& maximum(const T& n) {
  return n;
}
template <typename T, typename... Args>
const T& minimum(const T& n, const Args&... args) {
  return std::min(n, minimum(args...));
}
template <typename T, typename... Args>
const T& maximum(const T& n, const Args&... args) {
  return std::max(n, maximum(args...));
}
string s[402];
int a[402][402];
int s1[402][402];
int h[402], hh[402];
void solve() {
  int n, m;
  int i, i1, i2, i3;
  cin >> n >> m;
  for (i = 0; i < n; i++) cin >> s[i];
  for (i = 1; i <= n; i++) {
    for (i1 = 1; i1 <= m; i1++) {
      a[i][i1] = int(s[i - 1][i1 - 1] == '1');
      s1[i][i1] = s1[i - 1][i1] + a[i][i1];
    }
  }
  int ans = n * m;
  for (i = 1; i <= n - 4; i++) {
    for (i1 = i + 4; i1 <= n; i1++) {
      int add = 0, ls = n * m;
      for (int b = 1; b <= m; b++) {
        h[b] = (i1 - i - 1) - (s1[i1 - 1][b] - s1[i][b]);
        if (b >= 4) {
          ls = min(ls, h[b - 3] - add + hh[b - 1] + hh[b - 2]);
          ans = min(ans, ls + add + h[b]);
        }
        hh[b] = (s1[i1 - 1][b] - s1[i][b]) + (2 - a[i1][b] - a[i][b]);
        add += hh[b];
      }
    }
  }
  cout << ans << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
