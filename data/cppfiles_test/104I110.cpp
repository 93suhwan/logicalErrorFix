#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
long long ceel(long long a, long long b) { return ((a + b - 1) / b); }
bool isprime(long long n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (long long i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
long long power(long long x, long long y, long long mod) {
  long long ans = 1;
  x = x % mod;
  while (y) {
    if (y % 2 == 1) ans = (ans * x) % mod;
    y = y >> 1;
    x = (x * x) % mod;
  }
  return ans;
}
void solve() {
  long long n, x;
  cin >> n;
  vector<long long> a(n);
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long fx = 0;
  for (long long i = 0; i < n; i++) {
    fx = fx ^ a[i];
  }
  if (fx == 1) {
    cout << "NmO" << '\n';
    return;
  }
  fx = 0;
  if (n % 2) {
    cout << "YES" << '\n';
    for (long long i = 0; i < n - 2; i += 2) {
      cout << i + 1 << " ";
    }
    for (long long i = n - 4; i > 0; i -= 2) {
      cout << i << " ";
    }
    cout << '\n';
  } else {
    long long j = -1;
    for (long long i = 0; i < n; i++) {
      fx = fx ^ a[i];
      if (fx == 0 && i % 2 == 0) {
        j = i;
        break;
      }
    }
    if (j == -1) {
      cout << "NO" << '\n';
      return;
    }
    cout << "YES" << '\n';
    for (long long i = 0; i < j; i += 2) {
      cout << i + 1 << " ";
    }
    for (long long i = j - 1; i > 0; i -= 2) {
      cout << i << " ";
    }
    for (long long i = j + 1; i < n; i += 2) {
      cout << i + 1 << " ";
    }
    for (long long i = n - 2; i > j; i -= 2) {
      cout << i << " ";
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long t;
  cin >> t;
  for (long long tc = 0; tc < t; tc++) solve();
  return 0;
}
