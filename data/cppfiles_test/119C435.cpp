#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("sse4.2")
using namespace std;
void solve() {
  long long n;
  cin >> n;
  long long s = 0;
  for (long long i = 0; i < n; ++i) {
    long long first;
    cin >> first;
    s += first;
  }
  if (s % n == 0)
    cout << 0 << '\n';
  else
    cout << 1 << '\n';
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
