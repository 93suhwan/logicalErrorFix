#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 5, LMAX = 3e18 + 13, IMAX = 2e9 + 13, mod = 998244353;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  long long T;
  cin >> T;
  while (T--) {
    long long n, m, k;
    cin >> n >> m >> k;
    bool swapped = false;
    if (n & 1) {
      swap(n, m);
      k = ((n * m) / 2) - k;
      swapped = true;
    }
    if (k & 1) {
      cout << "NO\n";
      continue;
    }
    char a[n][m];
    for (long long i = 0; i < n; ++i)
      for (long long j = 0; j < m; ++j) a[i][j] = '\0';
    for (long long i = 0; i < n and i < n - 1 and k; i += 2) {
      long long c = 0;
      for (long long j = 0; j < m and j < m - 1 and k; j += 2) {
        a[i][j] = c + 'a';
        a[i][j + 1] = c + 'a';
        a[i + 1][j] = 'a' + (c + 1) % 2;
        a[i + 1][j + 1] = 'a' + (c + 1) % 2;
        c = (c + 1) % 2;
        k -= 2;
      }
    }
    if (k > 0) {
      cout << "NO\n";
      continue;
    }
    long long p = 0;
    for (long long j = 0; j < m; j += 2) {
      long long c = 0;
      for (long long i = 0; i < n and i < n - 1; i += 2) {
        if (a[i][j] == '\0') {
          a[i][j] = c + 10 * p + 'j';
          a[i + 1][j] = c + 10 * p + 'j';
          c = (c + 1) % 2;
          if (j < m - 1) a[i][j + 1] = c + 10 * p + 'j';
          a[i + 1][j + 1] = c + 10 * p + 'j';
        }
      }
      p++;
      p %= 2;
    }
    cout << "YES\n";
    if (swapped) {
      for (long long i = 0; i < m; ++i) {
        for (long long j = 0; j < n; ++j) cout << a[j][i];
        cout << "\n";
      }
    } else {
      for (long long i = 0; i < n; ++i) {
        for (long long j = 0; j < m; ++j) cout << a[i][j];
        cout << "\n";
      }
    }
  }
}
