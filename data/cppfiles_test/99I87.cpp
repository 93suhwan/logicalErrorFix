#include <bits/stdc++.h>
using namespace std;
void rev(char **a, int x, int y, int n, string s) {}
void solve() {
  int n, cnt = 0;
  cin >> n;
  string s;
  cin >> s;
  for (int i = 0; i < n; i++)
    if (s[i] == '2') cnt++;
  if (cnt == 0) {
    cout << "YES" << '\n';
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (i == j)
          cout << "X";
        else
          cout << "=";
      }
      cout << '\n';
    }
  } else if (cnt == 1)
    cout << "NO" << '\n';
  else {
    char a[n][n];
    cout << "YES" << '\n';
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) a[i][j] = '0';
    }
    for (int i = 0; i < n; i++) {
      bool win = 1;
      for (int j = 0; j < n; j++) {
        if (i == j)
          a[i][j] = 'X';
        else {
          if (s[j] == '1')
            a[i][j] = '=', a[j][i] = '=';
          else {
            if (a[i][j] == '0' and a[j][i] == '0') {
              if (win)
                a[i][j] = '+', a[j][i] = '-', win = 0;
              else
                a[i][j] = '-', a[j][i] = '+';
            }
          }
        }
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) cout << a[i][j];
      cout << '\n';
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  while (n--) solve();
  return 0;
}
