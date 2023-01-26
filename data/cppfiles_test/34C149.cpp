#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int maxn = 1e5 + 10;
const long long mod = 1e9 + 7;
long long pw(long long a, long long b, long long md = mod) {
  long long res = 1;
  while (b) {
    if (b & 1) {
      res = (a * res) % md;
    }
    a = (a * a) % md;
    b >>= 1;
  }
  return (res);
}
int q;
int n, k;
int a[maxn];
int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> q;
  while (q--) {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    long long ans = -1e15;
    for (int i = 1; i <= n; i++)
      for (long long j = i - 1; j >= 1 and i - j <= k + 1000; j--)
        ans = max(ans, i * j - k * (a[i] | a[j]));
    cout << ans << '\n';
  }
  return (0);
}
