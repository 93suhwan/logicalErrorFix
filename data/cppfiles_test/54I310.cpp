#include <bits/stdc++.h>
namespace FastRead {
char __buff[5000];
long long __lg = 0, __p = 0;
char nc() {
  if (__lg == __p) {
    __lg = fread(__buff, 1, 5000, stdin);
    __p = 0;
    if (!__lg) return EOF;
  }
  return __buff[__p++];
}
template <class T>
void read(T& __x) {
  T __sgn = 1;
  char __c;
  while (!isdigit(__c = nc()))
    if (__c == '-') __sgn = -1;
  __x = __c - '0';
  while (isdigit(__c = nc())) __x = __x * 10 + __c - '0';
  __x *= __sgn;
}
}  // namespace FastRead
using namespace FastRead;
using namespace std;
const long long N = 1e5 + 10;
const long long M = 1e9 + 7;
const long double PI = acos(-1);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long n, k;
long long pw(long long n, long long p) {
  long long ans = 1;
  for (; p; p >>= 1, n = n * n % M)
    if (p & 1) ans = ans * n % M;
  return ans;
}
void Test() {
  cin >> n >> k;
  if (n & 1) return cout << pw((pw(2, n - 1) + 1), k) << '\n', void();
  long long ans = 1;
  for (long long c = 1; c <= k; c++)
    ans = (ans + pw(pw(2, n - 1) - 1, c - 1) * pw(2, k - c) % M) % M;
  cout << ans << '\n';
}
signed main() {
  long long q;
  cin >> q;
  while (q--) Test();
  return 0;
}
