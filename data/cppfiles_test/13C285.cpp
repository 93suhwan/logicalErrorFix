#include <bits/stdc++.h>
using namespace std;
long long T(long long n) { return n * (n + 1) >> 1; }
long long MOD(long long a, long long mod) { return (a % mod + mod) % mod; }
long long gcd(long long a, long long b) { return (b == 0 ? a : gcd(b, a % b)); }
long long fpow(long long a, long long b, long long mod) {
  if (b == 0) return 1;
  if (b == 1) return a;
  if (b & 1) return fpow(a, b ^ 1, mod) * a % mod;
  long long res = fpow(a, b >> 1, mod);
  return res * res % mod;
}
long long fpow(long long a, long long b) {
  if (b == 0) return 1;
  if (b == 1) return a;
  if (b & 1) return fpow(a, b ^ 1) * a;
  long long res = fpow(a, b >> 1);
  return res * res;
}
const int INF32 = 2e9;
const long long INF64 = 4e18;
const int SZ = (1 << 30);
const int mod = 1e9 + 7;
const int lg = 20;
const long double eps = 1e-9;
void Solve() {
  long long n, m, k;
  cin >> n >> m >> k;
  if (n & 1) k -= (m >> 1);
  if (k >= 0 && !(k & 1) && k <= n * (m >> 1)) {
    cout << "YES\n";
    vector<vector<char>> a(n, vector<char>(m));
    if (n & 1) {
      char last = 'b';
      for (long long i = 0; i < m; i += 2) {
        a[n - 1][i] = a[n - 1][i + 1] = (last == 'b' ? 'a' : 'b');
        last = (last == 'b' ? 'a' : 'b');
      }
    }
    for (long long i = 0; i < n - (n & 1); i++) {
      for (long long j = 0; j < m; j++) {
        if (i % 4 == 2 || i % 4 == 3) {
          if (j % 4 == 0) a[i][j] = 'y';
          if (j % 4 == 1) a[i][j] = 'q';
          if (j % 4 == 2) a[i][j] = 'd';
          if (j % 4 == 3) a[i][j] = 'f';
        } else {
          if (j % 4 == 0) a[i][j] = 'x';
          if (j % 4 == 1) a[i][j] = 'p';
          if (j % 4 == 2) a[i][j] = 'c';
          if (j % 4 == 3) a[i][j] = 'e';
        }
      }
    }
    for (long long i = 0; (i + 1 < n - (n & 1)) && k > 0; i += 2) {
      for (long long j = 0; (j + 1 < m - (m & 1)) && k > 0; j += 2) {
        swap(a[i + 1][j], a[i][j + 1]);
        k -= 2;
      }
    }
    for (long long i = 0; i < n; i++) {
      for (long long j = 0; j < m; j++) cout << a[i][j];
      cout << '\n';
    }
  } else {
    cout << "NO\n";
  }
}
signed main() {
  ios_base::sync_with_stdio(NULL);
  cin.tie(NULL);
  cout.tie(NULL);
  srand(time(NULL));
  cout << fixed << setprecision(10);
  long long test = 1;
  cin >> test;
  for (long long i = 1; i <= test; i++) {
    Solve();
  }
}
