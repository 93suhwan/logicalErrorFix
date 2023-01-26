#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
using namespace std;
const long long N = 1e3 + 100;
long long long long e3(long long long long n) {
  return n * (n - 1) * (n - 2) / 3 / 2;
}
long long long long e2(long long long long n) { return n * (n - 1) / 2; }
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long long long n;
  long double p;
  cin >> n >> p;
  if (p == 0) return cout << 0 << '\n', 0;
  ;
  for (long long i = 1; i <= n; i++) {
    long double kol = e3(n);
    long double t3 = e3(i);
    long double t2 = e2(i) * (n - i);
    long double t1 = i * e2(n - i);
    long double t0 = e3(n - i);
    long double ans = 0;
    ans += t3 / kol;
    ans += t2 / kol;
    ans += (long double)2 / (long double)3 * t1 / kol;
    if (ans >= p) {
      return cout << i << '\n', 0;
      ;
    }
  }
}
