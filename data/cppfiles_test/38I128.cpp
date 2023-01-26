#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
  int t;
  t = 1;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    vector<int> v(m, 0);
    set<pair<int, int> > unblocked;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
      if (a[i][0] == '.') unblocked.insert({i, 0});
    }
    for (int i = 1; i < m; ++i) {
      if (a[0][i] == '.') unblocked.insert({0, i});
    }
    for (int j = 1; j < m; ++j) {
      for (int i = 1; i < n; ++i) {
        if (a[i][j] == '.') {
          if (unblocked.count({i, j - 1}) || unblocked.count({i - 1, j})) {
            unblocked.insert({i, j});
          } else
            v[j] = 1;
        } else {
          if (unblocked.find({i, j - 1}) == unblocked.end() &&
              unblocked.find({i - 1, j}) == unblocked.end()) {
            v[j] = 1;
          }
        }
      }
      v[j] += v[j - 1];
    }
    int q;
    cin >> q;
    while (q--) {
      int l, r;
      cin >> l >> r;
      l--;
      r--;
      if (v[r] - v[l])
        cout << "NO" << '\n';
      else
        cout << "YES" << '\n';
    }
  }
  return 0;
}
