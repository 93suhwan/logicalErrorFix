#include <bits/stdc++.h>
using namespace std;
constexpr int seed = 131;
constexpr long long LLMAX = 2e18;
constexpr int MOD = 1e9 + 7;
constexpr double eps = 1e-8;
constexpr int MAXN = 1e6 + 10;
constexpr int hmod1 = 0x48E2DCE7;
constexpr int hmod2 = 0x60000005;
inline long long sqr(long long x) { return x * x; }
inline int sqr(int x) { return x * x; }
inline double sqr(double x) { return x * x; }
inline int mul(int x, int y) { return 1ll * x * y % MOD; }
inline int sub(int x, int y) { return x >= y ? x - y : MOD + x - y; }
inline int add(int x, int y) { return x + y >= MOD ? x + y - MOD : x + y; }
inline int dcmp(double x) {
  if (fabs(x) < eps) return 0;
  return (x > 0 ? 1 : -1);
}
inline long long qpow(long long a, long long n) {
  long long sum = 1;
  while (n) {
    if (n & 1) sum = sum * a % MOD;
    a = a * a % MOD;
    n >>= 1;
  }
  return sum;
}
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long exgcd(long long a, long long b, long long &x, long long &y) {
  long long d;
  (b == 0 ? (x = 1, y = 0, d = a)
          : (d = exgcd(b, a % b, y, x), y -= a / b * x));
  return d;
}
int a[MAXN];
int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    for (int i = 0; i < n / 2; i++) cout << a[n - 1 - i] << ' ' << a[0] << endl;
  }
  return 0;
}
