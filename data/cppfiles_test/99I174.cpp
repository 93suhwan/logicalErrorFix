#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    string x;
    cin >> n >> x;
    vector<int> win;
    for (int i = 0; i < n; i++) {
      if (x[i] == '2') win.push_back(i + 1);
    }
    if (!win.size()) {
      cout << "YES\n";
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
          if (i == j)
            cout << "X";
          else
            cout << "=";
        }
        cout << "\n";
      }
    } else if (int(win.size()) <= 2)
      cout << "NO\n";
    else {
      cout << "YES\n";
      char grid[n + 1][n + 1];
      win.push_back(win[0]);
      for (int i = 1; i < int(win.size()); i++) {
        grid[win[i]][win[i - 1]] = '+';
        grid[win[i - 1]][win[i]] = '-';
      }
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
          if (i == j)
            cout << "X";
          else if (grid[i][j] == '+' || grid[i][j] == '-')
            cout << grid[i][j];
          else
            cout << "=";
        }
        cout << "\n";
      }
    }
  }
  return 0;
}
