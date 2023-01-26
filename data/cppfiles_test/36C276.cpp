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
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<long long> a(n + 1);
    long long sum = 0;
    for (long long i = 1; i <= n; i++) {
      cin >> a[i];
      sum += a[i];
    }
    long long k = sum;
    bool can = 0;
    for (long long i = 2; i <= sqrt(k); i++) {
      if (k % i == 0) can = 1;
    }
    if (can) {
      cout << n << "\n";
      for (long long i = 1; i <= n; i++) cout << i << " ";
      cout << "\n";
    } else {
      long long pos = -1;
      for (long long i = 1; i <= n; i++) {
        if (a[i] % 2) pos = i;
      }
      cout << n - 1 << "\n";
      for (long long i = 1; i <= n; i++)
        if (i != pos) cout << i << " ";
      cout << "\n";
    }
  }
}
