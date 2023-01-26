#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int testcase;
  cin >> testcase;
  while (testcase--) {
    int n, m, k, l;
    cin >> n >> m >> k;
    l = k;
    int v = (n * m / 2 - k) - n / 2 * m % 2;
    k -= (n % 2) * m / 2;
    if (k >= 0 && v >= 0 && k % 2 == 0 && v % 2 == 0 &&
        k <= (n / 2) * (m / 2) * 2)
      cout << "YES\n";
    else {
      cout << "NO\n";
      continue;
    }
    vector<vector<char>> a(n, vector<char>(m, '.'));
    char ch = 'a';
    for (int i = 0; i < n && m % 2; i += 2) {
      a[i][m - 1] = a[i + 1][m - 1] = ch++;
      if (ch > 'z') ch = 'a';
    }
    for (int i = 0; i < m && n % 2; i += 2) {
      --l;
      a[n - 1][i] = a[n - 1][i + 1] = ch++;
      if (ch > 'z') ch = 'a';
    }
    int i = 0, j = 0;
    vector<char> c(4);
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        if (a[i][j] == '.') {
          for (auto x : c) x = '.';
          if (i > 0) c[0] = a[i - 1][j];
          if (i < n - 1) c[1] = a[i + 1][j];
          if (j > 0) c[2] = a[i][j - 1];
          if (j < m - 1) c[3] = a[i][j + 1];
          while (1) {
            if (ch != c[0] && ch != c[1] && ch != c[2] && ch != c[3]) break;
            ch++;
            if (ch > 'z') ch = 'a';
          }
          if (l) {
            a[i][j] = a[i][j + 1] = ch++;
            if (ch > 'z') ch = 'a';
            l--;
            if (l && a[i + 1][j] == '.') {
              for (auto x : c) x = '.';
              if (i > 0) c[0] = a[i - 1][j];
              if (i < n - 1) c[1] = a[i + 1][j];
              if (j > 0) c[2] = a[i][j - 1];
              if (j < m - 1) c[3] = a[i][j + 1];
              while (1) {
                if (ch != c[0] && ch != c[1] && ch != c[2] && ch != c[3]) break;
                ch++;
                if (ch > 'z') ch = 'a';
              }
              a[i + 1][j] = a[i + 1][j + 1] = ch++;
              l--;
              if (ch > 'z') ch = 'a';
            }
          } else {
            a[i][j] = a[i + 1][j] = ch++;
            if (ch > 'z') ch = 'a';
          }
        }
    for (auto x : a) {
      for (auto y : x) cout << y;
      cout << "\n";
    }
  }
}
