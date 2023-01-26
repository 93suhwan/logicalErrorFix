#include <bits/stdc++.h>
using namespace std;
const long long mxlli = 1e18;
const int mxint = 1e9 + 7;
int solv() {
  int n, m, k;
  cin >> n >> m >> k;
  int z = ((n * m) / 2) - k;
  char c[n][m];
  int i, j;
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++) c[i][j] = '*';
  if ((n % 2 == 1 and m % 2 == 1)) {
    cout << "NO\n";
    return 0;
  }
  char ch, chh;
  if (m % 2) {
    if (k % 2) {
      cout << "NO\n";
      return 0;
    }
    if (k <= ((m - 1) * n) / 2) {
      cout << "YES\n";
      for (j = 0; j < m; j++) {
        for (i = 0; i < n; i++) {
          if (k && c[i][j] == '*') {
            if (i % 2 == (j / 2) % 2)
              chh = 'a';
            else
              chh = 'b';
            c[i][j] = chh;
            c[i][j + 1] = chh;
            k--;
          } else if (k == 0 && c[i][j] == '*') {
            if (j % 2 == (i / 2) % 2)
              chh = 'c';
            else
              chh = 'd';
            c[i][j] = chh;
            c[i + 1][j] = chh;
          }
        }
      }
      for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) cout << c[i][j];
        cout << "\n";
      }
    } else
      cout << "NO\n";
    return 0;
  }
  if (n % 2) {
    if (z % 2) {
      cout << "NO\n";
      return 0;
    }
    if (z <= ((n - 1) * m) / 2) {
      cout << "YES\n";
      for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
          if (z == 0 && c[i][j] == '*') {
            if (i % 2 == (j / 2) % 2)
              chh = 'a';
            else
              chh = 'b';
            c[i][j] = chh;
            c[i][j + 1] = chh;
          } else if (z && c[i][j] == '*') {
            if (j % 2 == (i / 2) % 2)
              chh = 'c';
            else
              chh = 'd';
            c[i][j] = chh;
            c[i + 1][j] = chh;
            z--;
          }
        }
      }
      for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) cout << c[i][j];
        cout << "\n";
      }
    } else
      cout << "NO\n";
    return 0;
  }
  if (k % 2) {
    cout << "NO\n";
    return 0;
  }
  cout << "YES\n";
  for (j = 0; j < m; j++) {
    for (i = 0; i < n; i++) {
      if (c[i][j] == '*') {
        if (i % 2 == (j / 2) % 2)
          chh = 'a';
        else
          chh = 'b';
        c[i][j] = chh;
        c[i][j + 1] = chh;
      }
    }
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) cout << c[i][j];
    cout << "\n";
  }
  return 0;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int testcases = 1;
  cin >> testcases;
  while (testcases--) {
    solv();
  }
}
