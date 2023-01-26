#include <bits/stdc++.h>
using namespace std;
template <class T>
void chmax(T& a, const T& b) {
  a = max(a, b);
}
template <class T>
void chmin(T& a, const T& b) {
  a = min(a, b);
}
using ll = long long;
using P = pair<int, int>;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    VVI d(n + 1, VI(m + 1));
    for (int i = 0; i < int(n); ++i)
      for (int j = 0; j < int(m); ++j) {
        char c;
        cin >> c;
        d[i + 1][j + 1] = c - '0';
      }
    VVI d_orig = d;
    for (int i = 0; i < int(n + 1); ++i)
      for (int j = 0; j < int(m); ++j) d[i][j + 1] += d[i][j];
    for (int i = 0; i < int(n); ++i)
      for (int j = 0; j < int(m + 1); ++j) d[i + 1][j] += d[i][j];
    int ans = 20;
    auto get = [&](int i, int j, int x, int y) {
      return d[x][y] + d[i][j] - d[x][j] - d[i][y];
    };
    for (int i = 0; i < int(n - 5 + 1); ++i)
      for (int j = 0; j < int(m - 4 + 1); ++j) {
        int c1 = get(i + 1, j + 1, i + 4, j + 3);
        int c2 = get(i, j, i + 5, j + 4) - c1;
        for (int k = 0; k <= 4; k += 4)
          for (int l = 0; l <= 3; l += 3) c2 -= d_orig[i + k + 1][j + l + 1];
        chmin(ans, c1 + 10 - c2);
      }
    cout << ans << '\n';
  }
}
