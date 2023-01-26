#include <bits/stdc++.h>
using namespace std;
int func(int a, int b) { return min(a, b); }
int minm(int a, int b, int n, vector<int> &tree) {
  a += n;
  b += n;
  int s = 1e9;
  while (a <= b) {
    if (a % 2 == 1) s = func(s, tree[a++]);
    if (b % 2 == 0) s = func(s, tree[b--]);
    a /= 2;
    b /= 2;
  }
  return s;
}
void add(int k, int x, int n, vector<int> &tree) {
  k += n;
  tree[k] = x;
  for (k /= 2; k >= 1; k /= 2) {
    tree[k] = func(tree[2 * k], tree[2 * k + 1]);
  }
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<vector<bool>> v;
    vector<vector<int>> val;
    for (int i = 0; i < n; i++) {
      val.push_back({});
      v.push_back({});
      for (int j = 0; j < m; j++) {
        val[i].push_back(0);
      }
      string s;
      cin >> s;
      for (int j = 0; j < m; j++) {
        if (s[j] == '0') {
          v[i].push_back(0);
        } else {
          v[i].push_back(1);
        }
      }
    }
    int sz = 4;
    int ans = 1e9;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j + sz - 1 < m; j++) {
        val[i][j] += (!v[i][j]);
        for (int k = 1; k < sz - 1; k++) {
          val[i][j] += v[i][j + k];
        }
        val[i][j] += (!v[i][j + sz - 1]);
      }
    }
    vector<int> suffm(n, 0);
    vector<int> pref(n, 0);
    auto modif = [&](int i, int j) -> int {
      return val[i][j] - !(v[i][j]) - !(v[i][j + sz - 1]);
    };
    while (sz <= m) {
      if (sz > 4) {
        for (int i = 0; i < n; i++) {
          for (int j = 0; j + sz - 1 < m; j++) {
            if (v[i][j + sz - 2]) {
              val[i][j]++;
            } else {
              val[i][j]--;
            }
            val[i][j] += (!v[i][j + sz - 1]);
          }
        }
      }
      for (int j = 0; j + sz - 1 < m; j++) {
        pref[0] = val[0][j];
        for (int i = 1; i < n; i++) {
          pref[i] = pref[i - 1] + val[i][j];
          suffm[i] = pref[i - 1] + sz - 2 - modif(i, j);
        }
        for (int i = n - 2; i >= 0; i--) {
          suffm[i] = min(suffm[i + 1], suffm[i]);
        }
        for (int i = 0; i + 4 < n; i++) {
          int ths = suffm[i + 4] + sz - 2 - modif(i, j) - pref[i];
          ans = min(ans, ths);
        }
      }
      ++sz;
    }
    cout << ans << '\n';
  }
  return 0;
}
