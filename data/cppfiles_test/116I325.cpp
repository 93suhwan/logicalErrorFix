#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const long long inf = 1e18;
const long long MAXN = 2e5 + 1;
const long long R = 1 << 20;
const long long mod = 998244353;
const long long LOGN = 21;
void solve() {
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (auto &x : a) cin >> x;
  vector<long long> cnt(n + 5), prev_unused(n + 5);
  long long ans = 0;
  for (long long i = 0; i < n; ++i) {
    if (a[i] == 0) {
      (cnt[0] += cnt[0] + 1) %= mod;
      (ans += prev_unused[2]) %= mod;
      continue;
    }
    if (a[i] == 1) {
      (cnt[1] += cnt[1] + cnt[0]) %= mod;
      (ans += prev_unused[1] + 1 + prev_unused[3]) %= mod;
      (prev_unused[1] += prev_unused[1] + 1) %= mod;
      continue;
    }
    long long x = a[i];
    (cnt[x] += cnt[x] + cnt[x - 1]) %= mod;
    (ans += cnt[x - 2] + prev_unused[x] + prev_unused[x + 2]) %= mod;
    (prev_unused[x] += prev_unused[x] + cnt[x - 2]) %= mod;
  }
  for (long long i = 0; i <= n; ++i) {
    (ans += cnt[i]) %= mod;
  }
  cout << ans << "\n";
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long _ = 1;
  cin >> _;
  while (_--) solve();
  return 0;
}
