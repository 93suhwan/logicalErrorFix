#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
long double pie = 3.14159265358979323846264338327950;
long double eps = 0.0000001;
long long mul(long long x, long long y) { return (x * 1ll * y) % mod; }
long long add(long long x, long long y) {
  x += y;
  while (x >= mod) x -= mod;
  while (x < 0) x += mod;
  return x;
}
long long power(long long a, long long b, long long m) {
  a %= m;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a) % m;
    a = (a * a) % m;
    b >>= 1;
  }
  return res % m;
}
void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  char a[n + 1][m + 1];
  int count = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
      if (a[i][j] == '*') count++;
    }
  }
  int t = k * 2;
  set<pair<int, int>> s;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i][j] == '*') {
        int x = 0;
        for (int p = j + t; p <= m; p += 2) {
          if (a[i][p] == '*') {
            if (i + (p - j) / 2 > n) break;
            int f = 1, e = 1;
            for (int q = i + 1; q <= (i + k); q++) {
              if (a[q][j + e] == '*' && a[q][p - e] == '*')
                e++;
              else {
                f = 0;
                break;
              }
            }
            if (f == 1) {
              e = 0, x = 1;
              for (int q = i; q <= (i + k); q++) {
                s.insert(make_pair(q, j + e));
                s.insert(make_pair(q, p - e));
                e++;
              }
            }
          }
        }
      }
    }
  }
  if (s.size() == count)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
