#include <bits/stdc++.h>
using namespace std;
long long cd(long long k, long long n) {
  if (k % n == 0) {
    return k / n;
  }
  return (k / n) + 1;
}
bool isprime(long long n) {
  for (long long i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}
long long power(long long x, long long y) {
  long long res = 1;
  while (y) {
    if (y % 2 == 1) res = (res * x);
    y = y >> 1;
    x = (x * x);
  }
  return res;
}
bool checksorted(long long a[], long long n) {
  for (long long i = 1; i < n; i++) {
    if (a[i - 1] > a[i]) {
      return false;
    }
  }
  return true;
}
const long long M = 1000000007;
long long modpower(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
bool check(vector<long long> v, vector<long long> z, long long m) {
  for (long long i = 0; i < v.size(); i++) {
    if (v[i] + z[i] < m) {
      return false;
    }
  }
  return true;
}
void solve() {
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  };
  long long r = *max_element(a.begin(), a.end()), l = 0;
  long long ans = -1, m;
  while (l <= r) {
    m = l + (r - l) / 2;
    vector<long long> v = a;
    vector<long long> z(n, 0);
    for (long long i = n - 1; i >= 2; i--) {
      long long d = min(v[i], max(v[i] + z[i] - m, 0LL)) / 3;
      v[i] -= 3 * d;
      z[i - 1] += d;
      z[i - 2] += 2 * d;
    }
    if (check(v, z, m)) {
      ans = m;
      l = m + 1;
    } else {
      r = m - 1;
    }
  }
  cout << ans << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long test;
  test = 1;
  cin >> test;
  while (test--) {
    solve();
  }
  return 0;
}
