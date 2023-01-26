#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 2e5 + 5;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-6;
int n, m, l, r;
string s;
string p[] = {" abc", " acb", " bac", " bca", " cab", " cba"};
int ans[6][MAX_N];
void solve() {
  cin >> n >> m >> s;
  for (int i = 0; i < 6; ++i) {
    for (int j = 0; j < s.size(); ++j) {
      ans[i][j + 1] = ans[i][j] + (s[j] != p[i][j % 3 + 1]);
    }
  }
  while (m--) {
    cin >> l >> r;
    int res = INF;
    for (int i = 0; i < 6; ++i) res = min(res, abs(ans[i][r] - ans[i][l - 1]));
    cout << res << '\n';
  }
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int test = 1;
  while (test--) {
    solve();
  }
  return 0;
}
