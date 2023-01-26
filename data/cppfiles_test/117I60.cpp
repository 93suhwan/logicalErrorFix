#include <bits/stdc++.h>
using namespace std;
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.second < b.second);
}
int power(int a) {
  int ans = 0;
  while (a > 1) {
    a /= 2;
    ans++;
  }
  return ans;
}
void solve(int n, int m, int x, int y, vector<vector<bool>> &check,
           vector<vector<char>> &a) {
  int x1 = 0, x2 = 0, x3 = 0, x4 = 0;
  int count = 0;
  if (x > 0) {
    if (a[x - 1][y] == '.' || a[x - 1][y] == 'L') {
      x1 = 1;
      count++;
    }
  }
  if (x < (n - 1)) {
    if (a[x + 1][y] == '.' || a[x + 1][y] == 'L') {
      x2 = 1;
      count++;
    }
  }
  if (y > 0) {
    if (a[x][y - 1] == '.' || a[x][y - 1] == 'L') {
      x3 = 1;
      count++;
    }
  }
  if (y < (m - 1)) {
    if (a[x][y + 1] == '.' || a[x][y + 1] == 'L') {
      x4 = 1;
      count++;
    }
  }
  if (count == 1) {
    check[x][y] = true;
    return;
  }
  if (count == 2) {
    check[x][y] = true;
    if (x1 == 1) {
      if (!check[x - 1][y] && a[x - 1][y] != 'L')
        return solve(n, m, x - 1, y, check, a);
    }
    if (x2 == 1) {
      if (!check[x + 1][y] && a[x + 1][y] != 'L')
        return solve(n, m, x + 1, y, check, a);
    }
    if (x3 == 1) {
      if (!check[x][y - 1] && a[x][y - 1] != 'L')
        return solve(n, m, x, y - 1, check, a);
    }
    if (x4 == 1) {
      if (!check[x][y + 1] && a[x][y + 1] != 'L')
        return solve(n, m, x, y + 1, check, a);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int cases;
  cin >> cases;
  while (cases--) {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> a(n, vector<char>(m));
    vector<vector<bool>> check(n, vector<bool>(m));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        check[i][j] = false;
        cin >> a[i][j];
      }
    }
    int x, y;
    int it = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (a[i][j] == 'L') {
          x = i;
          y = j;
          it = 1;
          break;
        }
      }
      if (it == 1) break;
    }
    if (x > 0) {
      if (a[x - 1][y] == '.') solve(n, m, x - 1, y, check, a);
    }
    if (x < (n - 1)) {
      if (a[x + 1][y] == '.') solve(n, m, x + 1, y, check, a);
    }
    if (y > 0) {
      if (a[x][y - 1] == '.') solve(n, m, x, y - 1, check, a);
    }
    if (y < (m - 1)) {
      if (a[x][y + 1] == '.') solve(n, m, x, y + 1, check, a);
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (a[i][j] == '.') {
          if (check[i][j])
            cout << "+";
          else
            cout << a[i][j];
        } else
          cout << a[i][j];
      }
      cout << "\n";
    }
  }
  return 0;
}
