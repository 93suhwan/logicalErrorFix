#include <bits/stdc++.h>
using namespace std;
const double pi = 3.141592653;
const long long infi = 1000000001;
const string no = "NO\n", yes = "YES\n", nl = "\n";
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  cin >> t;
  long long n, m, i, length, bank, k, j, x, y, ans, q;
  string s;
  while (t--) {
    ans = 0;
    cin >> n >> m >> k;
    char ch[n][m];
    x = (n * m) / 2 - k;
    int a[4];
    a[0] = n % 2;
    a[2] = m % 2;
    a[1] = k % 2;
    a[3] = x % 2;
    if (a[0] == a[2]) {
      if (a[1] == 0) ans = 1;
    } else if (a[0]) {
      y = m / 2;
      if (k >= y) {
        k -= y;
        if (k % 2 == 0) {
          ans = 2;
          s = "yyzz";
          for (i = 0; i < m; i++) {
            ch[n - 1][i] = s[i % 4];
          }
        }
      }
    } else {
      y = n / 2;
      if (x >= y) {
        x -= y;
        if (x % 2 == 0) {
          ans = 3;
          s = "yyzz";
          for (i = 0; i < n; i++) {
            ch[i][m - 1] = s[i % 4];
          }
        }
      }
    }
    if (ans) {
      if (n % 2) n--;
      if (m % 2) m--;
      string sh[2], sv[2];
      sh[0] = "aa";
      sh[1] = "bb";
      sv[0] = "cd";
      sv[1] = "cd";
      int cnt1 = 0, cnt2 = 0;
      for (i = 0; i < n; i += 2) {
        cnt1 = 0;
        for (j = 0; j < m; j += 2) {
          if (k) {
            k -= 2;
            if (cnt1) {
              ch[i][j] = 'b';
              ch[i][j + 1] = 'b';
              ch[i + 1][j] = 'a';
              ch[i + 1][j + 1] = 'a';
            } else {
              ch[i][j] = 'a';
              ch[i][j + 1] = 'a';
              ch[i + 1][j] = 'b';
              ch[i + 1][j + 1] = 'b';
            }
            cnt1 ^= 1;
          } else {
            if (cnt2) {
              ch[i][j] = 'c';
              ch[i][j + 1] = 'd';
              ch[i + 1][j] = 'c';
              ch[i + 1][j + 1] = 'd';
            } else {
              ch[i][j] = 'e';
              ch[i][j + 1] = 'f';
              ch[i + 1][j] = 'e';
              ch[i + 1][j + 1] = 'f';
            }
            x -= 2;
          }
        }
        cnt2 ^= 1;
      }
      cout << yes;
      for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
          cout << ch[i][j];
        }
        cout << nl;
      }
    } else
      cout << no;
  }
  return 0;
}
