#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long q;
  cin >> q;
  for (long long d = 0; d < q; d++) {
    long long n, m, k;
    cin >> n >> m >> k;
    char a[n][m];
    for (long long i = 0; i < n; i++)
      for (long long j = 0; j < m; j++) a[i][j] = 'z';
    bool ans = 0;
    if ((n % 2) == 0 && (m % 2) == 0) {
      if ((k % 2) == 0) {
        long long kol = k;
        char c1 = 'a';
        char c2 = 'b';
        for (long long i = 0; (i + 1) < n; i += 2)
          for (long long j = 0; (j + 2) <= m; j += 2)
            if (a[i][j] == 'z' && kol > 0) {
              a[i][j] = c1;
              a[i][j + 1] = c1;
              a[i + 1][j] = c2;
              a[i + 1][j + 1] = c2;
              kol -= 2;
              swap(c1, c2);
            }
        c1 = 'c';
        c2 = 'd';
        for (long long i = 0; (i + 1) < n; i += 2) {
          for (long long j = 0; j < m; j += 2)
            if (a[i][j] == 'z') {
              a[i][j] = c1;
              a[i + 1][j] = c1;
              a[i][j + 1] = c2;
              a[i + 1][j + 1] = c2;
            }
          swap(c1, c2);
        }
        ans = 1;
      }
    } else if ((n % 2) == 0 && 2 * k <= (n * (m - 1))) {
      if ((k % 2) == 0) {
        ans = 1;
        long long kol = k;
        char c1 = 'a';
        char c2 = 'b';
        for (long long i = 0; (i + 1) < n; i += 2)
          for (long long j = 0; (j + 2) <= m; j += 2)
            if (a[i][j] == 'z' && kol > 0) {
              if ((i - 1) >= 0 && c1 == a[i - 1][j]) swap(c1, c2);
              a[i][j] = c1;
              a[i][j + 1] = c1;
              a[i + 1][j] = c2;
              a[i + 1][j + 1] = c2;
              kol -= 2;
              swap(c1, c2);
            }
        c1 = 'c';
        c2 = 'd';
        for (long long i = 0; (i + 1) < n; i += 2) {
          for (long long j = 0; j < m; j += 2)
            if (a[i][j] == 'z') {
              a[i][j] = c1;
              a[i + 1][j] = c1;
              if ((j + 1) < m) {
                a[i][j + 1] = c2;
                a[i + 1][j + 1] = c2;
              }
            }
          swap(c1, c2);
        }
      }
    } else if ((m % 2) == 0 && 2 * k >= m) {
      k -= (m / 2);
      if ((k % 2) == 0) {
        long long kol = k;
        ans = 1;
        char c1 = 'a';
        char c2 = 'b';
        for (long long j = 0; j < m; j += 2) {
          a[0][j] = c1;
          a[0][j + 1] = c1;
          swap(c1, c2);
        }
        for (long long i = 1; (i + 1) < n; i += 2)
          for (long long j = 0; (j + 2) <= m; j += 2)
            if (a[i][j] == 'z' && kol > 0) {
              a[i][j] = c1;
              a[i][j + 1] = c1;
              a[i + 1][j] = c2;
              a[i + 1][j + 1] = c2;
              kol -= 2;
              swap(c1, c2);
            }
        c1 = 'c';
        c2 = 'd';
        for (long long i = 0; (i + 1) < n; i += 2) {
          for (long long j = 0; j < m; j += 2)
            if (a[i][j] == 'z') {
              a[i][j] = c1;
              a[i + 1][j] = c1;
              a[i][j + 1] = c2;
              a[i + 1][j + 1] = c2;
            }
          swap(c1, c2);
        }
      }
    }
    if (ans)
      cout << "YES\n";
    else
      cout << "NO\n";
    if (ans) {
      for (long long i = 0; i < n; i++) {
        for (long long j = 0; j < m; j++) cout << a[i][j];
        cout << '\n';
      }
    }
  }
  return 0;
}
