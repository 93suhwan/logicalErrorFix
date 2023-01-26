#include <bits/stdc++.h>
#pragma GCC optimize("Ofast", "inline", "-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
using namespace std;
void fast_stream() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
const long long INF = 0x7fffffffffffffff;
const long long MAXN = 2e5 + 9;
void solve() {
  long long n, m, rb, cb, rd, cd, ans = 0, dr = 1, dc = 1;
  cin >> n >> m >> rb >> cb >> rd >> cd;
  while (rb != rd && cb != cd) {
    if (rb + dr > n || rb + dr <= 0) dr = -dr;
    if (cb + dc > m || cb + dc <= 0) dc = -dc;
    rb += dr;
    cb += dc;
    ans++;
  }
  cout << ans << "\n";
}
signed main() {
  fast_stream();
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
}
