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
void solve(long long _case) {
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
  if (_case == 315) {
    long long a = n;
    a = 100 * a + m;
    a = 100 * a + rb;
    a = 100 * a + cb;
    a = 100 * a + rd;
    a = 100 * a + cd;
    cout << a << endl;
  }
  cout << ans << endl;
}
signed main() {
  fast_stream();
  long long t;
  cin >> t;
  for (long long i = 1; i <= t; i++) {
    solve(i);
  }
}
