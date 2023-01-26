#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int d4x[4] = {1, 0, -1, 0};
int d4y[4] = {0, 1, 0, -1};
int d8x[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int d8y[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const long long oo = 1e18;
const long long maxN = 1e6;
const int N = 105;
long long a[N];
void solve() {
  int n;
  long long h;
  cin >> n >> h;
  for (int i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + 1 + n);
  auto ok = [&](long long x) -> bool {
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
      if (i < n)
        ans += min(a[i + 1] - a[i], x);
      else
        ans += x;
      if (ans >= h) return true;
    }
    return false;
  };
  long long L = 1, R = h, ans = 0;
  while (L <= R) {
    long long mid = (L + R) >> 1;
    if (ok(mid)) {
      ans = mid;
      R = mid - 1;
    } else
      L = mid + 1;
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc = 1, ddd = 0;
  cin >> tc;
  while (tc--) {
    solve();
  }
}
