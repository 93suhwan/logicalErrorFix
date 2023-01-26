#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
  int t, n;
  cin >> t;
  vector<int> a;
  vector<int> f[2][2];
  vector<pair<int, int>> trace[2][2];
  while (t--) {
    cin >> n;
    a.resize(n);
    for (auto &u : a) cin >> u;
    for (int i = 0; i < 2; ++i)
      for (int j = 0; j < 2; ++j) {
        f[i][j].assign(n + 1, n + 1);
        trace[i][j].resize(n + 1);
      }
    f[0][0][0] = -n;
    f[0][1][0] = -n;
    for (int i = 0; i < n - 1; ++i) {
      if (f[0][0][i] <= n) {
        if (a[i + 1] > a[i])
          f[0][0][i + 1] = f[0][0][i], trace[0][0][i + 1] = {0, 0};
        else if (a[i + 1] > f[0][0][i])
          f[1][0][i + 1] = a[i], trace[1][0][i + 1] = {0, 0};
        if (-a[i + 1] > f[0][0][i])
          f[1][1][i + 1] = a[i], trace[1][1][i + 1] = {0, 0};
      }
      if (f[0][1][i] <= n) {
        f[0][0][i + 1] = f[0][1][i], trace[0][0][i + 1] = {0, 1};
        if (a[i + 1] < a[i])
          f[0][1][i + 1] = f[0][1][i], trace[0][1][i + 1] = {0, 1};
        else if (-a[i + 1] > f[0][1][i])
          f[1][1][i + 1] = -a[i], trace[1][1][i + 1] = {0, 1};
      }
      if (f[1][0][i] <= n) {
        if (a[i + 1] > f[1][0][i])
          f[0][0][i + 1] = a[i], trace[0][0][i + 1] = {1, 0};
        else if (a[i + 1] > a[i])
          f[1][0][i + 1] = f[1][0][i], trace[1][0][i + 1] = {1, 0};
      }
      if (f[1][1][i] <= n) {
        if (a[i + 1] > f[1][1][i])
          f[0][0][i + 1] = -a[i], trace[0][0][i + 1] = {1, 1};
        else
          f[1][1][i + 1] = f[1][1][i], trace[1][1][i + 1] = {1, 1};
        if (-a[i + 1] > f[1][1][i])
          f[0][1][i + 1] = -a[i], trace[0][1][i + 1] = {1, 1};
        else if (a[i + 1] < a[i])
          f[1][1][i + 1] = f[1][1][i], trace[1][1][i + 1] = {1, 1};
      }
    }
    pair<int, int> res{-1, -1};
    for (int i = 0; i < 2; ++i)
      for (int j = 0; j < 2; ++j)
        if (f[i][j][n - 1] <= n) res = {i, j};
    if (res.first == -1) {
      cout << "NO" << endl;
      continue;
    }
    cout << "YES" << endl;
    vector<int> ans;
    for (int i = n - 1; i >= 0; --i) {
      ans.push_back(res.second ? -a[i] : a[i]);
      res = trace[res.first][res.second][i];
    }
    for (auto it = ans.rbegin(); it != ans.rend(); ++it) cout << *it << " ";
    cout << endl;
  }
  return 0;
}
