#include <bits/stdc++.h>
using namespace std;
int max(int a, int b) {
  if (a < b) return b;
  return a;
}
int min(int a, int b) {
  if (a < b) return a;
  return b;
}
signed main() {
  int a, b, c, op = 998244353, n, m, yap, x = 300001, d, t, p, r, k = 26, e;
  cin >> yap;
  while (yap > 0) {
    yap--;
    cin >> n >> m >> k;
    a = m / 2 * n;
    b = n / 2 * m;
    if (k > a || k % 2 != a % 2 || n * m / 2 - k > b)
      cout << "NO\n";
    else {
      cout << "YES\n";
      vector<string> s(n);
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m / 2; j++) {
          if (i % 4 == 0) {
            if (j % 2 == 0)
              s[i] += "aa";
            else
              s[i] += "bb";
          }
          if (i % 4 == 1) {
            if (j % 2 == 0)
              s[i] += "cc";
            else
              s[i] += "dd";
          }
          if (i % 4 == 2) {
            if (j % 2 == 0)
              s[i] += "ee";
            else
              s[i] += "ff";
          }
          if (i % 4 == 3) {
            if (j % 2 == 0)
              s[i] += "gg";
            else
              s[i] += "hh";
          }
        }
        if (i % 4 < 2)
          s[i] += 'i';
        else
          s[i] += 'j';
      }
      a -= k;
      for (int i = 0; i < n / 2; i++) {
        for (int j = 0; j < m / 2; j++) {
          if (a > 0) {
            swap(s[2 * i][2 * j], s[2 * i + 1][2 * j + 1]);
            a -= 2;
          }
        }
      }
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cout << s[i][j];
        cout << "\n";
      }
    }
  }
  return 0;
}
