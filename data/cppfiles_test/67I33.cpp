#include <bits/stdc++.h>
using namespace std;
template <class c>
struct rge {
  c b, e;
};
template <class c>
rge<c> range(c i, c j) {
  return rge<c>{i, j};
}
template <class c>
auto dud(c *x) -> decltype(cerr << *x, 0);
template <class c>
char dud(...);
struct debug {
  template <class c>
  debug &operator<<(const c &) {
    return *this;
  }
};
long long __pow(long long x, long long y, long long M) {
  long long res = 1;
  while (y > 0) {
    if (y & 1) res = (res * x) % M;
    y >>= 1;
    x = (x * x) % M;
  }
  return res % M;
}
long long __pow(long long x, long long y) {
  long long res = 1;
  while (y > 0) {
    if (y & 1) res = (res * x);
    y >>= 1;
    x = (x * x);
  }
  return res;
}
long long mi(long long x, long long M) { return __pow(x, M - 2, M); }
long long mul(long long a, long long b, long long M) { return (a * b) % M; }
void umax(long long &a, long long b) { a = max(a, b); }
void umin(long long &a, long long b) { a = min(a, b); }
const long long N = 2e5 + 2, inf = 1e18, M = 1e9 + 7, LN = 20;
long long Test, n, m, k;
bool ok = 1;
double esp = 1e-9;
double nc2(long long n) { return (n * (n - 1)) / 2; }
double nc3(long long n) { return (n * (n - 1) * (n - 2)) / 6; }
void test_case() {
  cin >> n;
  double p;
  cin >> p;
  long long x;
  for (x = 0; x <= n; x++) {
    double _p = nc3(x) + nc2(x) * (n - x) + (x * nc2(n - x) * 3) / 4;
    if (abs(_p - p * nc3(n)) < esp) break;
  }
  cout << x << '\n';
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  Test = 1;
  for (long long t = 1; t <= Test; t++) {
    test_case();
  }
  return 0;
}
