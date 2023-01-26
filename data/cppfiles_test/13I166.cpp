#include <bits/stdc++.h>
using namespace std;
const int N = 101;
int a[N][N];
int c[N][N];
void clears(int n, int m) {
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) {
      a[i][j] = 0;
      c[i][j] = -1;
    }
  return;
}
int n, m;
bool good(int x, int y, int id) {
  return (x >= 0 && y >= 0 && x < n && y < m && c[x][y] == id);
}
bool g(int x, int y) { return (x >= 0 && y >= 0 && x < n && y < m); }
bool badaround(int i, int j, int id) {
  if (good(i + 1, j, id) && a[i + 1][j] != a[i][j]) return true;
  if (good(i - 1, j, id) && a[i - 1][j] != a[i][j]) return true;
  if (good(i, j + 1, id) && a[i][j + 1] != a[i][j]) return true;
  if (good(i, j - 1, id) && a[i][j - 1] != a[i][j]) return true;
  if (g(i + 1, j) && a[i + 1][j] == a[i][j]) c[i + 1][j] = c[i][j] = id;
  if (g(i - 1, j) && a[i - 1][j] == a[i][j]) c[i - 1][j] = c[i][j] = id;
  if (g(i, j + 1) && a[i][j + 1] == a[i][j]) c[i][j + 1] = c[i][j] = id;
  if (g(i, j - 1) && a[i][j - 1] == a[i][j]) c[i][j - 1] = c[i][j] = id;
  return false;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int k;
    cin >> n >> m >> k;
    int b = (m + 1) / 2 * n;
    int w = n * m - b;
    b -= k;
    w -= k;
    int b1 = (n + 1) / 2 * m;
    int w1 = n * m - b1;
    int k1 = n * m / 2 - k;
    b1 -= k1;
    w1 -= k1;
    bool f0 = (b >= 0 && w >= 0 && b % 2 == 0 && w % 2 == 0);
    bool f1 = (b1 >= 0 && w1 >= 0 && b1 % 2 == 0 && w1 % 2 == 0);
    if (!(f0 && f1))
      cout << "NO\n";
    else {
      cout << "YES\n";
      clears(n, m);
      int cn = 1;
      int i = 0, j = 0;
      while (b > 0) {
        if (i + 1 >= n) {
          i = 0;
          j += 2;
          continue;
        }
        a[i][j] = a[i + 1][j] = cn++;
        i += 2;
        b -= 2;
      }
      i = 0;
      j = 1;
      while (w > 0) {
        if (i + 1 >= n) {
          i = 0;
          j += 2;
          continue;
        }
        a[i][j] = a[i + 1][j] = cn++;
        i += 2;
        w -= 2;
      }
      for (int i = 0; i < n; ++i)
        for (int j = 0; j < m - 1; ++j)
          if (a[i][j] == 0 && a[i][j + 1] == 0) a[i][j] = a[i][j + 1] = cn++;
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
          int id = 0;
          if (c[i][j] == -1)
            while (badaround(i, j, id)) {
              id %= 26;
              id++;
            }
          cout << (char)(c[i][j] + 'a');
        }
        cout << endl;
      }
    }
  }
  return 0;
}
