#include <bits/stdc++.h>
using namespace std;
char nextChar(char a, char b) {
  for (char c = 'a'; c <= 'z'; c++) {
    if (c != a && c != b) return c;
  }
}
char next(char a, char b) {
  for (char c = 'x'; c <= 'z'; c++) {
    if (c != a && c != b) {
      return c;
    }
  }
}
void test_case() {
  long long n, m, k;
  cin >> n >> m >> k;
  char x[n][m];
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      if (i == 0 && j == 0) {
        x[i][j] = nextChar('\0', '\0');
      } else if (i == 0) {
        x[i][j] = nextChar('\0', x[i][j - 1]);
      } else if (j == 0) {
        x[i][j] = nextChar(x[i - 1][j], '\0');
      } else {
        x[i][j] = nextChar(x[i - 1][j], x[i][j - 1]);
      }
    }
  }
  if (n % 2 == 0 && m % 2 == 0) {
    if (k % 2 == 0) {
      cout << "YES" << '\n';
      for (long long j = 0; j < m; j += 2) {
        for (long long i = 0; i < n; i++) {
          if (k != 0) {
            char a = (i - 1) >= 0 ? x[i - 1][j] : '\0';
            char b = (j - 1) >= 0 ? x[i][j - 1] : '\0';
            x[i][j] = x[i][j + 1] = next(a, b);
            k--;
          }
        }
      }
      for (auto &i : x) {
        for (auto j : i) {
          cout << j;
        }
        cout << '\n';
      }
    } else
      cout << "NO" << '\n';
  } else if (n % 2 == 1) {
    if (k >= (m / 2)) {
      for (long long j = 0; j < m; j += 2) {
        x[0][j] = x[0][j + 1] =
            (j == 0) ? next('\0', '\0') : next('\0', x[0][j - 1]);
      }
      k -= m / 2;
      if (k % 2 == 0) {
        cout << "YES" << '\n';
        for (long long j = 0; j < m; j += 2) {
          for (long long i = 1; i < n; i++) {
            if (k != 0) {
              char a = (i - 1) >= 0 ? x[i - 1][j] : '\0';
              char b = (j - 1) >= 0 ? x[i][j - 1] : '\0';
              x[i][j] = x[i][j + 1] = next(a, b);
              k--;
            }
          }
        }
        for (auto &i : x) {
          for (auto j : i) {
            cout << j;
          }
          cout << '\n';
        }
      } else
        cout << "NO" << '\n';
    } else
      cout << "NO" << '\n';
  } else {
    k = ((n * m) / 2) - k;
    if (k >= (n / 2)) {
      k -= n / 2;
      if (k % 2 == 0) {
        k += n / 2;
        k = ((n * m) / 2) - k;
        for (long long j = 0; j < m; j += 2) {
          for (long long i = 0; i < n; i++) {
            if (k != 0) {
              char a = (i - 1) >= 0 ? x[i - 1][j] : '\0';
              char b = (j - 1) >= 0 ? x[i][j - 1] : '\0';
              x[i][j] = x[i][j + 1] = next(a, b);
              k--;
            }
          }
        }
        cout << "YES" << '\n';
        for (auto &i : x) {
          for (auto j : i) {
            cout << j;
          }
          cout << '\n';
        }
      } else
        cout << "NO" << '\n';
    } else
      cout << "NO" << '\n';
  }
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  long long t = 1;
  cin >> t;
  while (t--) test_case();
  return 0;
}
