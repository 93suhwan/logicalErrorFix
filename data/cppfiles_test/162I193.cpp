#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize(2, 3)
const long long mod = 1000000007;
inline long long pw(long long x, long long y) {
  long long r = 1;
  while (y) {
    if (y & 1) r = r * x % mod;
    x = x * x % mod;
    y >>= 1;
  }
  return r;
}
inline void mad(long long &a, long long b) {
  a = (a + b) % mod;
  while (a < 0) a += mod;
}
inline void mmu(long long &a, long long b) {
  a = a * b % mod;
  while (a < 0) a += mod;
}
long long n;
long long a[200010], b[200010];
bool check(long long x) {
  for (register long long i = 1; i <= n; i++) b[i] = a[i];
  long long tmp;
  for (register long long i = n; i >= 3; i--) {
    if (b[i] < x) return false;
    tmp = (b[i] - x) / 3;
    b[i - 1] += tmp;
    b[i - 2] += 2 * tmp;
  }
  if (b[1] < x || b[2] < x) return false;
  return true;
}
void work() {
  cin >> n;
  for (register long long i = 1; i <= n; i++) cin >> a[i];
  long long l = 0, r = a[n], mid, res;
  while (l <= r) {
    mid = (l + r) >> 1;
    if (check(mid)) {
      l = mid + 1;
      res = mid;
    } else {
      r = mid - 1;
    }
  }
  cout << res << endl;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long T;
  cin >> T;
  while (T--) work();
  return 0;
}
