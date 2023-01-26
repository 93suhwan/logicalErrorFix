#include <bits/stdc++.h>
using namespace std;
char al[20][20];
char moban[20][20];
int n, m, k, t;
bool p(int x, int y) {
  for (int i = 1; i <= k; i++) {
    if (x - i < 1 || y - i < 1 || al[x - i][y - i] != '*') {
      return false;
    }
  }
  for (int i = 1; i <= k; i++) {
    if (x - i < 1 || y + i > m || al[x - i][y + i] != '*') {
      return false;
    }
  }
  return true;
}
void r(int x, int y) {
  moban[x][y] = '*';
  for (int i = 1; i <= k; i++) {
    moban[x - i][y - i] = '*';
  }
  for (int i = 1; i <= k; i++) {
    moban[x - i][y + i] = '*';
  }
  int ans = 1;
  while (al[x - k - ans][y - k - ans] == '*' &&
         al[x - k - ans][y + k + ans] == '*' && x - k - ans >= 1 &&
         y - k - ans >= 1 && y + k + ans <= m) {
    moban[x - k - ans][y - k - ans] = '*';
    moban[x - k - ans][y + k + ans] = '*';
    ans++;
  }
}
bool pp() {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (moban[i][j] != al[i][j]) return false;
    }
  }
  return true;
}
int main() {
  cin >> t;
  while (t--) {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        cin >> al[i][j];
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (al[i][j] == '.') {
          moban[i][j] = al[i][j];
        } else if (al[i][j] == '*') {
          if (p(i, j))
            r(i, j);
          else
            moban[i][j] = '.';
        }
      }
    }
    if (pp())
      cout << "YES" << endl;
    else {
      cout << "NO" << endl;
    }
  }
}
