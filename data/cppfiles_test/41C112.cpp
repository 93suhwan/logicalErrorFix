#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
void solve() {
  int n, m;
  string s;
  cin >> n >> m >> s;
  vector<vector<int>> f(6, vector<int>(n));
  string t = "abc";
  for (int turn = 0; turn < 6; ++turn) {
    f[turn][0] = (s[0] != t[0]);
    for (int i = 1; i < n; ++i) {
      f[turn][i] = f[turn][i - 1] + (s[i] != t[i % 3]);
    }
    next_permutation(t.begin(), t.end());
  }
  for (int i = 0, l, r; i < m; ++i) {
    cin >> l >> r;
    l--, r--;
    int res = 1e9;
    if (l) {
      for (int turn = 0; turn < 6; ++turn) {
        res = min(res, f[turn][r] - f[turn][l - 1]);
      }
    } else {
      for (int turn = 0; turn < 6; ++turn) {
        res = min(res, f[turn][r]);
      }
    }
    cout << res << endl;
  }
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int T;
  T = 1;
  while (T--) {
    solve();
  }
}
