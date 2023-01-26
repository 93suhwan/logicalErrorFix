#include <bits/stdc++.h>
using namespace std;
using cd = complex<double>;
mt19937 rnd(chrono::system_clock::now().time_since_epoch().count());
const long long mod = 1e9 + 7, N = 2e3 + 5;
long long d[N][2 * N], p[N][2 * N];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long q;
  cin >> q;
  while (q--) {
    long long n, ans = 0;
    cin >> n;
    string s, t;
    cin >> s >> t;
    s = " " + s;
    t = " " + t;
    for (long long i = 2; i <= n; i += 2) {
      if (s[i] == '0')
        s[i] = '1';
      else if (s[i] == '1')
        s[i] = '0';
      if (t[i] == '0')
        t[i] = '1';
      else if (t[i] == '1')
        t[i] = '0';
    }
    for (long long i = 0; i <= n + 1; i++) {
      for (long long j = -n + 1; j <= n + 1; j++) {
        d[i][j + N] = p[i][j + N] = 0;
      }
    }
    d[0][0 + N] = 1;
    for (long long i = 0; i < n; i++) {
      for (long long j = -n; j <= n; j++) {
        for (long long x = 0; x < 2; x++) {
          for (long long y = 0; y < 2; y++) {
            if (x == 0 && s[i + 1] == '1') continue;
            if (x == 1 && s[i + 1] == '0') continue;
            if (y == 0 && t[i + 1] == '1') continue;
            if (y == 1 && t[i + 1] == '0') continue;
            d[i + 1][j + x - y + N] += d[i][j + N];
            d[i + 1][j + x - y + N] %= mod;
          }
        }
      }
    }
    p[n + 1][0 + N] = 1;
    for (long long i = n + 1; i > 1; i--) {
      for (long long j = -n; j <= n; j++) {
        for (long long x = 0; x < 2; x++) {
          for (long long y = 0; y < 2; y++) {
            if (x == 0 && s[i - 1] == '1') continue;
            if (x == 1 && s[i - 1] == '0') continue;
            if (y == 0 && t[i - 1] == '1') continue;
            if (y == 1 && t[i - 1] == '0') continue;
            p[i - 1][j + x - y + N] += p[i][j + N];
            p[i - 1][j + x - y + N] %= mod;
          }
        }
      }
    }
    for (long long i = 1; i < n; i++) {
      for (long long j = -n; j <= n; j++) {
        ans += d[i][j + N] % mod * p[i + 1][-j + N] % mod * abs(j) % mod;
        ans %= mod;
      }
    }
    cout << ans << endl;
  }
}
