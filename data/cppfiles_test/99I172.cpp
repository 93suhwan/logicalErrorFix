#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  for (int k = 0; k < t; k++) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    char result[n][n];
    int count_2 = 0;
    for (int i = 0; i < n; i++)
      if (s[i] == '2') count_2++;
    if (count_2 < 3 && count_2 != 0) {
      cout << "NO" << '\n';
      continue;
    }
    cout << "YES" << '\n';
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        if (i == j)
          result[i][j] = 'X';
        else
          result[i][j] = '-';
    for (int i = 0; i < n; i++)
      if (s[i] == '1')
        for (int j = 0; j < n; j++) {
          if (i != j) {
            result[i][j] = '=';
            result[j][i] = '=';
          }
        }
      else
        for (int j = 0; j < n; j++) {
          if (s[j] == '2' && result[i][j] == '-' && result[j][i] == '-') {
            result[i][j] = '+';
            break;
          }
        }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) cout << result[i][j];
      cout << '\n';
    }
  }
}
