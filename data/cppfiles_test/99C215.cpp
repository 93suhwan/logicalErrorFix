#include <bits/stdc++.h>
using namespace std;
int n;
char s[1000];
char ans[100][100];
bool st[100];
bool check(int x, int y) {
  if (ans[x][y] == '*' && ans[y][x] == '*') return true;
  return false;
}
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> s[i];
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) ans[i][j] = '*';
  for (int i = 1; i <= n; i++) ans[i][i] = 'X';
  for (int i = 1; i <= n; i++) {
    if (s[i] == '1') {
      for (int j = 1; j <= n; j++) {
        if (i != j) {
          ans[i][j] = '=';
          ans[j][i] = '=';
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    if (s[i] == '2') {
      bool flag = false;
      for (int j = 1; j <= n; j++) {
        if (check(i, j) && i != j) {
          ans[i][j] = '+';
          ans[j][i] = '-';
          flag = true;
          break;
        }
      }
      if (!flag) {
        cout << "No" << endl;
        return;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (ans[i][j] == '*') ans[i][j] = '=';
    }
  }
  cout << "Yes" << endl;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cout << ans[i][j];
    }
    cout << endl;
  }
}
int main() {
  int T = 1;
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
