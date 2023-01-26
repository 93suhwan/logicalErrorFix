#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  string a[6] = {"abc", "acb", "bac", "bca", "cab", "cba"};
  int ans[6][n + 1];
  for (int i = 0; i < 6; i++) {
    ans[i][0] = 0;
  }
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < n; j++) {
      if (a[i][j % 3] != s[j]) {
        ans[i][j + 1] = 1 + ans[i][j];
      } else {
        ans[i][j + 1] = ans[i][j];
      }
    }
  }
  while (q--) {
    int l, r;
    cin >> l >> r;
    int res = INT_MAX;
    for (int i = 0; i < 6; i++) {
      res = min(res, ans[i][r] - ans[i][l - 1]);
    }
    cout << res << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
}
