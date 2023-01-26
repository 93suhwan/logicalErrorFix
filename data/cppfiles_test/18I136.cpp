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
    const int INF = 1e9;
    auto doit = [&](int x, int i, int c) {
      if (g[x].empty()) return INF;
      auto nxt = g[x].begin();
      if (*nxt < i || c) return (*nxt + n - i) / d;
      return (*nxt - i) / d;
    };
    for (int i = 0; i < n; i++) {
      if (arr[i] == 0) continue;
      int w1 = ((i + d) % n) % d;
      int w2 = ((i - d + n) % n) % d;
      int best_way = min(doit(w1, i, 0), doit(w2, i, 1));
      if (best_way == INF) {
        cout << -1 << '\n';
        goto fim;
      }
      mn = max(mn, best_way);
    }
    cout << mn << '\n';
  fim:;
  }
  return 0;
}
