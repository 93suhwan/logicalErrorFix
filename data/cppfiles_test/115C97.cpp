#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("popcnt")
using namespace std;
mt19937 bruh(chrono::steady_clock::now().time_since_epoch().count());
const long long N = 2e5 + 100;
const long long mod = 1e9 + 7;
const long long big = 1e17;
long long t, n, h;
long long a[N];
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n >> h;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    long long l = 1, r = 1e18, ans = h;
    while (l <= r) {
      long long m = (l + r) >> 1ll;
      long long sum = 0, rtst = 0;
      for (int i = 1; i <= n; i++) {
        long long l = max(a[i] - 1ll, rtst), r = a[i] + m - 1;
        sum = sum + (r - l);
        rtst = r;
      }
      if (sum >= h)
        r = m - 1ll, ans = m;
      else
        l = m + 1ll;
    }
    cout << ans << '\n';
  }
}
