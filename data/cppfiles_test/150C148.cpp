#include <bits/stdc++.h>
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
template <typename T>
void _do(T x) {
  cerr << x << "\n";
}
template <typename T, typename... U>
void _do(T x, U... y) {
  cerr << x << ", ";
  _do(y...);
}
const int MOD1 = 1e9 + 7;
const int MOD2 = 998244353;
const long long INF = 3e18;
const long double PI = 3.14159265358979323846;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long fpow(long long a, long long b, long long m) {
  if (!b) return 1;
  long long ans = fpow(a * a % m, b / 2, m);
  return (b % 2 ? ans * a % m : ans);
}
long long inv(long long a, long long m) { return fpow(a, m - 2, m); }
const int N = 5e5 + 1;
long long a[105];
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    long long ans = INF;
    for (int x = 0; x < 4; x++) {
      for (int y = 0; y < 4; y++) {
        bool can = 1;
        long long mx = 0;
        for (int i = 1; i <= n; i++) {
          long long tmp = INF;
          for (int j = 0; j < x + 1; j++) {
            for (int k = 0; k < y + 1; k++) {
              long long b = a[i] - j - k * 2;
              if (b < 0 || b % 3 != 0) continue;
              tmp = min(tmp, b / 3);
            }
          }
          if (tmp == INF) {
            can = 0;
            break;
          }
          mx = max(mx, tmp);
        }
        if (can) ans = min(ans, mx + x + y);
      }
    }
    cout << ans << "\n";
  }
}
