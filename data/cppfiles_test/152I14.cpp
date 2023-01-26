#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
int main() {
  std::ios_base::sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    vector<vector<int>> f(n + 1, vector<int>(4, inf));
    vector<vector<int>> pre(n + 1, vector<int>(4, -1));
    f[1][0] = f[1][1] = -inf;
    for (int i = 2; i <= n; i++) {
      f[i] = vector<int>(4, inf);
      vector<tuple<int, int, int>> b;
      for (int j = 0; j < 4; j++) {
        int x = (j % 2 ? -1 : 1) * a[i - 1];
        if (f[i - 1][j] != inf) {
          int y = f[i - 1][j];
          if (x < y) {
            swap(x, y);
          }
          b.emplace_back(j, x, y);
        }
      }
      for (int j = 0; j < 4; j++) {
        int u = (j % 2 ? -1 : 1) * a[i];
        for (auto [p, x, y] : b) {
          if (j < 2 && u > x) {
            if (y < f[i][j]) {
              f[i][j] = y;
              pre[i][j] = p;
            }
          }
          if (j >= 2 && u > y && u < x) {
            if (x < f[i][j]) {
              f[i][j] = x;
              pre[i][j] = p;
            }
          }
        }
      }
    }
    bool ok = false;
    vector<int> ans(n + 1);
    for (int j = 0; j < 4; j++) {
      if (f[n][j] < inf) {
        int p = j;
        for (int i = n; i >= 1; i--) {
          ans[i] = (p % 2 ? -1 : 1) * a[i];
          p = pre[i][p];
        }
        break;
      }
    }
    cout << (ok ? "YES" : "NO") << endl;
    if (ok) {
      for (auto x : ans) {
        cout << x << " ";
      }
      cout << endl;
    }
  }
  return 0;
}
