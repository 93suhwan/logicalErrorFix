#include <bits/stdc++.h>
using namespace std;
void DS1() {}
void DS2() { ios_base::sync_with_stdio(false), cin.tie(nullptr); }
long long mini(long long a, long long b, long long c) {
  return min(a, min(b, c));
}
void fill(long long* a, long long n, long long x) {
  for (long long i = 0; i < n; i++) {
    a[i] = x;
  }
}
long long M = 1000 * 1000 * 1000 + 7;
const long long N = 10005;
void solve() {
  long long n, i = 0, j = 0, k = 0, x, y, z, q, w;
  long long sum = 0, cnt = 0, ans = 0, flag = 0, mx = INT_MIN, mn = INT_MAX;
  cin >> n;
  if (n % 2) n++;
  if (n > 6)
    ans = (n / 2) * 5;
  else
    ans = 15;
  cout << ans << endl;
}
int32_t main() {
  DS1();
  DS2();
  long long t = 1, i = 1;
  cin >> t;
  while (t--) {
    solve();
    ++i;
  }
  return 0;
}
