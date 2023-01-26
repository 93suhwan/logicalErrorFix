#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  vector<string> variant = {"abc", "acb", "bac", "bca", "cab", "cba"};
  vector<vector<long long> > a(variant.size(), vector<long long>(n + 1));
  for (int i = 0; i < a.size(); ++i) {
    for (int j = 1; j <= n; ++j) {
      int ind = j - 1;
      a[i][j] = a[i][j - 1];
      if (s[ind] != variant[i][ind % 3]) {
        a[i][j]++;
      }
    }
  }
  for (int i = 0; i < m; ++i) {
    long long l, r;
    cin >> l >> r;
    l--;
    long long res = a[0][r] - a[0][l];
    for (int i = 1; i < a.size(); ++i) {
      res = min(res, a[i][r] - a[i][l]);
    }
    cout << res << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
