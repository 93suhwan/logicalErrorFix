#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
bool isPrime(long long n) {
  static long long i = 2;
  if (n == 0 || n == 1) {
    return false;
  }
  if (n == i) return true;
  if (n % i == 0) {
    return false;
  }
  i++;
  return isPrime(n);
}
long long power(long long x, long long y) { return (long long)pow(x, y); }
void solve() {
  long long n, h;
  cin >> n >> h;
  vector<long long> arr(n);
  for (long long &x : arr) cin >> x;
  long long l = 1;
  long long r = h;
  long long ans = 0;
  while (l <= r) {
    long long m = (l + r) / 2;
    long long sum = m;
    for (long long i = 0; i < n - 1; i++) {
      sum += min(m, arr[i + 1] - arr[i]);
    }
    if (sum >= h) {
      ans = m;
      r = m - 1;
    } else {
      l = m + 1;
    }
  }
  cout << ans << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) solve();
}
