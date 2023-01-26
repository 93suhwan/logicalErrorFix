#include <bits/stdc++.h>
using namespace std;
const double PI = 2 * acos(0.0);
void solve(void) {
  int n;
  cin >> n;
  string str;
  cin >> str;
  char board[n][n];
  memset(board, '.', sizeof(board));
  for (int i = 0; i < str.length(); i++) {
    if (str[i] == '1') {
      for (int j = 0; j < n; j++) {
        board[i][j] = '=';
        board[j][i] = '=';
      }
    }
    board[i][i] = 'X';
  }
  for (int i = 0; i < str.length(); i++) {
    if (str[i] == '2') {
      int found = 0;
      for (int j = 0; j < n; j++) {
        if (board[i][j] == '.' && board[j][i] == '.') {
          board[i][j] = '+';
          board[j][i] = '-';
          found = 1;
        }
        if (found) break;
      }
      if (!found) {
        cout << "NO" << '\n';
        return;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (board[i][j] == '.') board[i][j] = '=';
    }
  }
  cout << "YES" << '\n';
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << board[i][j];
    }
    cout << '\n';
  }
}
int main(void) {
  ios::sync_with_stdio(0), cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
