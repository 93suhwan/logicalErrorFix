#include <bits/stdc++.h>
using namespace std;
int a[6][200005];
string str[6] = {"abc", "bca", "cab", "acb", "cba", "bac"};
int main() {
  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  for (int i = 0; i < 6; i++) {
    a[i][0] = 0;
    for (int j = 1; j <= n; j++) {
      a[i][j] = a[i][j - 1];
      if (str[i][(j - 1) % 3] != s[j - 1]) a[i][j]++;
    }
  }
  while (m--) {
    int l, r;
    cin >> l >> r;
    int ans = 1e9;
    for (int i = 0; i < 6; i++) {
      ans = min(ans, a[i][r] - a[i][l - 1]);
    }
    cout << ans << endl;
  }
}
