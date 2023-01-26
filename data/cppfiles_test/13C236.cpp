#include <bits/stdc++.h>
using namespace std;
vector<vector<char>> a(100, vector<char>(100, '.'));
int n, m;
vector<char> c(25);
char sol(int i, int j, char ch) {
  for (auto &x : c) x = '.';
  int t = 0;
  for (int p = max(0, i - 2); p <= min(n - 1, i + 2); p++)
    for (int q = max(0, j - 2); q <= min(m - 1, j + 2); q++) c[t++] = a[p][q];
  while (t) {
    t = 0;
    for (auto x : c)
      if (x == ch) {
        ch++;
        if (ch > 'z') ch = 'a';
        t = 1;
        break;
      }
  }
  return ch;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int testcase;
  cin >> testcase;
  while (testcase--) {
    int k, l;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) a[i][j] = '.';
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
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        if (a[i][j] == '.') {
          ch = sol(i, j, ch);
          if (l) {
            a[i][j] = a[i][j + 1] = ch++;
            if (ch > 'z') ch = 'a';
            l--;
            if (l && a[i + 1][j] == '.') {
              ch = sol(i + 1, j, ch);
              a[i + 1][j] = a[i + 1][j + 1] = ch++;
              l--;
              if (ch > 'z') ch = 'a';
            }
          } else {
            a[i][j] = a[i + 1][j] = ch++;
            if (ch > 'z') ch = 'a';
          }
        }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) cout << a[i][j];
      cout << "\n";
    }
  }
}
