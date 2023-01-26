#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int mat = (n * (n - 1)) / 2;
  int c2 = 0;
  for (int i = 0; i < n; i++)
    if (s[i] == '2') c2++;
  int d = (n * n) - n + c2 - (c2 * c2);
  if (c2 == 1 || c2 == 2)
    cout << "NO"
         << "\n";
  else {
    cout << "YES"
         << "\n";
    char m[n][n];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (s[i] == '1' || s[j] == '1')
          m[i][j] = '=';
        else {
          if (i > j)
            m[i][j] = '+';
          else
            m[i][j] = '-';
        }
        if (i == j) m[i][j] = 'X';
      }
    }
    for (int i = n - 1; i >= 0; i--) {
      if (m[0][i] == '-') {
        swap(m[0][i], m[i][0]);
        break;
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cout << m[i][j];
      }
      cout << "\n";
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
