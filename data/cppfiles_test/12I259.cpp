#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
const long long inf = 1LL << 62;
const long long mx = 100005;
const double eps = 1e-10;
long long dx[10] = {1, 0, -1, 0}, dy[10] = {0, -1, 0, 1};
long long power(long long a, long long b) {
  if (b == 0) return 1;
  long long x = power(a, b / 2);
  x = x * x;
  if (b % 2) x = x * a;
  return x;
}
long long bigmod(long long a, long long b) {
  if (b == 0) return 1;
  long long x = bigmod(a, b / 2) % mod;
  x = (x * x) % mod;
  if (b % 2) x = (x * a) % mod;
  return x;
}
long long Set(long long N, long long pos) { return N = N | (1LL << pos); }
long long reset(long long N, long long pos) { return N = N & ~(1LL << pos); }
bool check(long long N, long long pos) { return (bool)(N & (1LL << pos)); }
int main() {
  long long tst, a, b, c, k, n, m, res = 0, ans = 0, t = 0;
  scanf("%lld", &tst);
  while (tst--) {
    scanf("%lld", &n), scanf("%lld", &m), scanf("%lld", &k);
    a = (n * m) / 2;
    a = a - k;
    if (k > (n / 2) or a > (m / 2)) {
      cout << "YES"
           << "\n";
    } else {
      cout << "NO"
           << "\n";
    }
  }
  return 0;
}
