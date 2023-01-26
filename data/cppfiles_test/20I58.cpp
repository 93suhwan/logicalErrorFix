#include <bits/stdc++.h>
using namespace std;
string s[404];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    int ans = 0;
    for (int i = 0; i < n; i++) {
      cin >> s[i];
    }
    for (int i = 1; i < n - 1; i++) {
      ans += (s[i][0] == '0');
      ans += (s[i][m - 1] == '0');
    }
    for (int i = 1; i < m - 1; i++) {
      ans += (s[0][i] == '0');
      ans += (s[n - 1][0] == '0');
    }
    for (int i = 1; i < n - 1; i++) {
      for (int j = 1; j < m - 1; j++) ans += (s[i][j] == '1');
    }
    cout << ans << "\n";
  }
}
