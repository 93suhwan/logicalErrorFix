#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  string str;
  cin >> str;
  vector<vector<int> > summ(6, vector<int>(n));
  vector<string> stri = {"abc", "cba", "bac", "acb", "bca", "cab"};
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < n; j++) {
      if (j != 0) summ[i][j] = summ[i][j - 1];
      if (str[j] != stri[i][j % 3]) summ[i][j]++;
    }
  }
  while (m--) {
    int l, r;
    cin >> l >> r;
    l--;
    r--;
    int ans = n;
    for (int i = 0; i < 6; i++) {
      if (l == 0)
        ans = min(ans, summ[i][r]);
      else
        ans = min(ans, summ[i][r] - summ[i][l - 1]);
    }
    cout << ans << endl;
  }
  cin >> str;
  return 0;
}
