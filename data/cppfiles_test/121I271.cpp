#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int x, int y) { return (rng() % (y - x + 1)) + x; };
const long long mod = (long long)1e9 + 7;
const long long MOD = (long long)998244353;
const long long INF = (long long)1e9;
inline long long add(long long a, long long b) {
  return (a + b >= mod ? a + b - mod : a + b);
}
inline long long mul(long long a, long long b) {
  return (long long)a * b % mod;
}
void solve() {
  long long n;
  cin >> n;
  string a, b;
  cin >> a >> b;
  long long cnt[4] = {};
  for (__typeof(n) i = (0) - ((0) > (n)); i != (n) - ((0) > (n));
       i += 1 - 2 * ((0) > (n))) {
    if (a[i] == '1' && a[i] == b[i]) ++cnt[0];
    if (a[i] == '1' && a[i] != b[i]) ++cnt[1];
    if (a[i] == '0' && a[i] == b[i]) ++cnt[2];
    if (a[i] == '0' && a[i] != b[i]) ++cnt[3];
  }
  if (cnt[1] + cnt[3] == 0) {
    cout << 0 << "\n";
    return;
  }
  if (cnt[1] == 1 && cnt[3] == 1) {
    cout << 2 << "\n";
    return;
  }
  if (cnt[1] == 2 && cnt[3] == 2) {
    long long ans = 4;
    if (cnt[2] == 1 && cnt[0] == 2) ans = 3;
    if (cnt[0] == 1 && cnt[2] == 0) ans = 1;
    cout << ans << "\n";
    return;
  }
  long long ans = -1;
  if (cnt[2] == 1 && cnt[0] == 2) ans = 3;
  if (cnt[0] == 1 && cnt[2] == 0) ans = 1;
  cout << ans << "\n";
}
int32_t main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  ;
  long long t;
  cin >> t;
  for (__typeof(t) i = (0) - ((0) > (t)); i != (t) - ((0) > (t));
       i += 1 - 2 * ((0) > (t)))
    solve();
  return 0;
}
