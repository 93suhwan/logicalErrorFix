#include <bits/stdc++.h>
using namespace std;
long n, m;
bool valid(long i, long k, long l) {
  if (i >= 0 && k >= 0 && l < m) return 1;
  return 0;
}
int main() {
  long T = 1;
  cin >> T;
  while (T--) {
    long k, i, j, d;
    cin >> n >> m >> d;
    long a[n][m];
    for (i = 0; i < n; i++) {
      for (j = 0; j < m; j++) {
        char c11;
        cin >> c11;
        if (c11 == '.')
          a[i][j] = 0;
        else
          a[i][j] = 1;
      }
    }
    for (i = 0; i < n; i++) {
      for (j = 0; j < m; j++) {
        if (a[i][j]) {
          long c = 0, k = j - 1, l = j + 1, f = i - 1;
          while (valid(f, k, l) && a[f][k] && a[f][l]) c++, l++, k--, f--;
          if (c >= d) {
            a[i][j] = 2;
            k = j - 1, l = j + 1, f = i - 1;
            while (valid(f, k, l) && a[f][k] && a[f][l])
              a[f][k] = 2, a[f][l] = 2, l++, k--, f--;
          }
        }
      }
    }
    k = 0;
    for (i = 0; i < n; i++) {
      for (j = 0; j < m; j++) {
        if (a[i][j] == 1) k++;
      }
    }
    if (k)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }
  return 0;
}
