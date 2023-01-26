#include <bits/stdc++.h>
using namespace std;
const long long maxn = 124;
long long n, h, a[maxn];
bool check(long long x) {
  long long sum = x;
  for (long long i = 1; i <= n - 1; i++) {
    sum += min(x, a[i + 1] - a[i]);
  }
  if (sum >= h) return true;
  return false;
}
void Solve() {
  cin >> n >> h;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
  }
  long long l = 1, r = 1e18, ans = 0;
  while (l <= r) {
    long long mid = l + (r - l) / 2;
    if (check(mid)) {
      ans = mid;
      r = mid - 1;
    } else
      l = mid + 1;
  }
  cout << ans << endl;
}
int32_t main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long t;
  cin >> t;
  while (t--) Solve();
  return 0;
}
