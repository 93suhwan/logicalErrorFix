#include <bits/stdc++.h>
using namespace std;
const int N = 110;
char a[N][N];
int n, m, k;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int t = 0;
int id(int x, int y) {
  x %= 5;
  y %= 5;
  return x * 5 + y;
}
void solve() {
  memset(a, 0, sizeof a);
  bool res;
  cin >> n >> m >> k;
  if ((n % 2 == 1) and (m % 2 == 0)) {
    res = (((k - m / 2) % 2) == 0) and k >= m / 2;
    if (res) {
      for (int i = 0; i < m; i += 2) a[0][i] = a[0][i + 1] = 'a' + id(0, i);
      k -= m / 2;
      for (int i = 0; i < m and k; i += 2)
        for (int j = 1; j < n and k; j++)
          a[j][i] = a[j][i + 1] = 'a' + id(j, i), k--;
      for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
          if (!a[i][j]) a[i][j] = a[i + 1][j] = 'a' + id(i, j);
    }
  } else if ((n % 2 == 0) and (m % 2 == 1)) {
    res = (((m * n / 2 - k - n / 2) % 2) == 0) and (m * n / 2 - k) >= n / 2;
    if (res) {
      for (int i = 0; i < n; i += 2) a[i][0] = a[i + 1][0] = 'a' + id(i, 0);
      k = m * n / 2 - k;
      k -= n / 2;
      for (int i = 0; k; i += 2)
        for (int j = 1; j < m and k; j++)
          a[i][j] = a[i + 1][j] = 'a' + id(i, j), k--;
      for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
          if (!a[i][j]) a[i][j] = a[i][j + 1] = 'a' + id(i, j);
    }
  } else {
    res = k % 2 == 0;
    if (res) {
      for (int i = 0; i < n and k; i++)
        for (int j = 0; j < m and k; j++)
          if (!a[i][j]) {
            a[i][j] = a[i][j + 1] = 'a' + id(i, j);
            a[i + 1][j] = a[i + 1][j + 1] = 'a' + id(i + 1, j);
            k -= 2;
          }
      for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
          if (!a[i][j]) a[i][j] = a[i + 1][j] = 'a' + id(i, j);
    }
  }
  cout << (res ? "YES" : "NO") << endl;
  if (res)
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) cout << a[i][j];
      cout << endl;
    }
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
