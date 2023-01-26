#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int cntw = 0;
  vector<int> w(n, -1);
  int fir = -1;
  int previous = -1;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == '2') {
      if (fir == -1)
        fir = i;
      else
        w[previous] = i;
      previous = i;
      ++cntw;
    }
  }
  if (previous != -1) w[previous] = fir;
  vector<vector<char>> ans(n, vector<char>(n, 'o'));
  if (cntw > 0 && cntw <= 2)
    cout << "NO\n";
  else {
    cout << "YES\n";
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i == j)
          ans[i][j] = 'X';
        else if (w[i] == j) {
          ans[i][j] = '+';
          ans[j][i] = '-';
        } else if (ans[i][j] == 'o')
          ans[i][j] = '=';
      }
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        cout << ans[i][j] << ' ';
      }
      cout << "\n";
    }
    cout << "++++++++++++++++++\n";
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
