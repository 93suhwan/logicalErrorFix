#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target( \
    "fma,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, d;
    cin >> n >> d;
    vector<int> arr(n);
    vector<vector<int>> g(d);
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
      if (arr[i] == 0) g[i % d].emplace_back(i);
    }
    int mn = 0;
    for (int i = 0; i < n; i++) {
      if (arr[i] == 0) continue;
      auto nxt = lower_bound(g[i % d].begin(), g[i % d].end(), i);
      if (nxt != g[i % d].end()) {
        mn = max(mn, (*nxt - i) / d);
        continue;
      }
      int lo = (i + ((n - i - 1 + d - 1) / d) * d) % n;
      nxt = g[lo % d].begin();
      if (nxt != g[lo % d].end()) {
        mn = max(mn, (*nxt + n - i) / d);
        continue;
      }
      cout << -1 << '\n';
      goto fim;
    }
    cout << mn << '\n';
  fim:;
  }
  return 0;
}
