#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  vector<string> t(6);
  vector<vector<int>> p(6, vector<int>(n));
  t[0] = "abc";
  t[1] = "acb";
  t[2] = "bac";
  t[3] = "bca";
  t[4] = "cab";
  t[5] = "cba";
  for (int k = 0; k < 6; k++) {
    for (int i = 0; i < n; i++)
      if (s[i] != t[k][i % 3]) p[k][i] = 1;
    for (int i = 1; i < n; i++) p[k][i] += p[k][i - 1];
  }
  while (m--) {
    int l, r;
    cin >> l >> r;
    l--, r--;
    int ans = 1e9;
    for (int i = 0; i < 6; i++) {
      int temp = p[i][r];
      if (l) temp -= p[i][l - 1];
      ans = min(ans, temp);
    }
    cout << ans << endl;
  }
  cin >> n;
}
