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
  long long n;
  cin >> n;
  if (n % 2 == 1)
    cout << n / 2 << ' ' << n / 2 + 1 << endl;
  else
    cout << -n + 1 << ' ' << n << endl;
}
signed main() {
  fast_stream();
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
}
