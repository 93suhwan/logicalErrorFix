#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, flag;
  string s;
  cin >> n;
  cin >> s;
  multiset<char> m;
  for (int i = 0; i < n; i++) m.insert(s[i]);
  if (m.count('2') == 1 || m.count('2') == '2') {
    cout << "NO" << endl;
    return;
  }
  cout << "YES" << endl;
  char c[50][50];
  for (int i = 0; i < n; i++) {
    flag = 0;
    for (int j = i; j < n; j++) {
      if (i == j) {
        c[i][j] = 'X';
        continue;
      }
      if (s[i] == '1')
        c[i][j] = '=';
      else if (s[i] == '2') {
        if (s[j] == '2') {
          if (flag == 0) {
            c[i][j] = '+';
            flag = 1;
          } else
            c[i][j] = '-';
        }
      }
    }
  }
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++) {
      if (i == j) continue;
      if (c[i][j] == '+')
        c[j][i] = '-';
      else if (c[i][j] == '-')
        c[j][i] = '+';
      else if (c[i][j] == '=')
        c[j][i] = '=';
    }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) cout << c[i][j];
    cout << endl;
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
