#include <bits/stdc++.h>
using namespace std;
const long long N = 2000010;
long long n, h, T, x;
long long q[110];
bool check(long long x) {
  long long cnt = 0;
  for (long long i = 1; i < n; i++) {
    long long a = q[i], b = q[i + 1];
    a = min(a + x, b);
    cnt += a - q[i];
  }
  cnt += x;
  return cnt >= h;
}
void solve() {
  cin >> n >> h;
  for (long long i = 1; i <= n; i++) cin >> q[i];
  long long l = 1, r = h;
  while (l < r) {
    long long mid = l + r >> 1;
    if (check(mid))
      r = mid;
    else
      l = mid + 1;
  }
  cout << l << endl;
}
signed main() {
  cin >> T;
  while (T--) solve();
  return 0;
}
