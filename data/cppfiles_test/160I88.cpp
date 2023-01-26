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
long long n, m, rb, cb, rd, cd;
bool is_ok() { return rb == rd || cb == cd; }
void solve() {
  long long dr = 1, dc = 1;
  cin >> n >> m >> rb >> cb >> rd >> cd;
  long long ans = 0;
  while (!is_ok()) {
    ans++;
    if (rb + dr > n || rb + dr <= 0) dr = -dr;
    if (cb + dc > m || cb + dc <= 0) dc = -dr;
    rb += dr;
    cb += dc;
  }
  cout << ans << endl;
}
signed main() {
  fast_stream();
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
}
