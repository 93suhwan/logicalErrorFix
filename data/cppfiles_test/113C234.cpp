#include <bits/stdc++.h>
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
long long exp(long long x, long long y) {
  x %= 1000000007;
  long long res = 1;
  while (y) {
    if (y & 1) res = res * x % 1000000007;
    x = x * x % 1000000007;
    y >>= 1;
  }
  return res;
}
long long fact(long long n) {
  long long res = 1;
  for (long long i = 2; i <= n; ++i) (res *= i) %= 1000000007;
  return res;
}
bool isprime(long long n) {
  if (n <= 1) return 0;
  for (long long i = 2; i * i <= n; ++i)
    if (n % i == 0) return 0;
  return 1;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  sort(a.begin(), a.end());
  long long sum = accumulate(a.begin(), a.end(), 0ll);
  int m;
  cin >> m;
  while (m--) {
    long long x, y;
    cin >> x >> y;
    long long mn = LONG_LONG_MAX;
    auto it1 = upper_bound(a.begin(), a.end(), x), it2 = it1;
    if (it1 != a.end()) {
      mn = min(mn, max(0ll, y - (sum - *it1)));
    }
    if (it2 != a.begin()) {
      --it2;
      mn = min(mn, x - *it2 + max(0ll, y - (sum - *it2)));
    }
    cout << mn << '\n';
  }
  return 0;
}
