#include <bits/stdc++.h>
using namespace std;
long long check(long long n, long long m, long long x, long long y) {
  return x >= 0 && x < n && y >= 0 && y < m;
}
void pr() { cout << '\n'; }
template <class A, class... B>
void pr(const A &a, const B &...b) {
  cout << a << (sizeof...(b) ? " " : "");
  pr(b...);
}
template <class A>
void PR(A a, long long n) {
  for (long long i = (long long)(0); i < (long long)(n); i++)
    cout << (i ? " " : "") << a[i];
  cout << '\n';
}
const long long MAX = 1e9 + 7, MAXL = 1LL << 61,
                dx[8] = {-1, 0, 1, 0, -1, -1, 1, 1},
                dy[8] = {0, 1, 0, -1, -1, 1, 1, -1};
void Main() {
  long long T;
  cin >> T;
  while (T--) {
    long long n, m, k;
    cin >> n >> m >> k;
    for (long long nn = (long long)(1); nn < (long long)(n + 1); nn++) {
      if ((n - nn) % 2) continue;
      char c[n][m];
      for (long long i = (long long)(0); i < (long long)(n); i++)
        for (long long j = (long long)(0); j < (long long)(m); j++)
          c[i][j] = '-';
      long long z = k;
      for (long long j = 0; j < m; j += 2) {
        for (long long i = (long long)(0); i < (long long)(nn); i++) {
          if (z == 1 && (n - i) % 2 == 0) break;
          if (z && j + 1 < m) {
            char ch = 'a';
            long long u[26];
            memset(u, 0, sizeof(u));
            for (long long x = (long long)(-3); x < (long long)(4); x++) {
              for (long long y = (long long)(-3); y < (long long)(4); y++) {
                if (check(n, m, x + i, y + j) && isalpha(c[x + i][y + j]))
                  u[c[x + i][y + j] - 'a']++;
              }
            }
            while (u[ch - 'a']) ch++;
            c[i][j] = c[i][j + 1] = ch;
            z--;
          }
        }
      }
      if (z) continue;
      for (long long i = (long long)(0); i < (long long)(n); i++) {
        for (long long j = (long long)(0); j < (long long)(m); j++) {
          if (c[i][j] == '-') {
            long long f = 0;
            if (check(n, m, i + 1, j) && c[i + 1][j] == '-') f = 1;
            if (f) {
              char ch = 'a';
              long long u[26];
              memset(u, 0, sizeof(u));
              for (long long x = (long long)(-3); x < (long long)(4); x++) {
                for (long long y = (long long)(-3); y < (long long)(4); y++) {
                  if (check(n, m, x + i, y + j) && isalpha(c[x + i][y + j]))
                    u[c[x + i][y + j] - 'a']++;
                }
              }
              while (u[ch - 'a']) ch++;
              c[i][j] = c[i + 1][j] = ch;
            } else
              goto next;
          }
        }
      }
      if (!z) {
        pr("YES");
        for (long long i = (long long)(0); i < (long long)(n); i++) {
          for (long long j = (long long)(0); j < (long long)(m); j++)
            cout << c[i][j];
          cout << '\n';
        }
        goto end;
      }
    next:;
    }
    pr("NO");
  end:;
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  Main();
  return 0;
}
