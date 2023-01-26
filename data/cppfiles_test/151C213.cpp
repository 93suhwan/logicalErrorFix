#include <bits/stdc++.h>
#pragma gcc optimize("Ofast,no-stack-protector,tune=native")
#pragma gcc optimize("sse,sse2,sse3,sse4,ssse3")
#pragma gcc optimize("O2")
#pragma gcc optimize("abm,mmx,avx,avx2,unroll-loops,fast-math,section-anchors")
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int MAXN = 5e5 + 5;
set<int> val[MAXN];
void solve() {
  int q, r, x, y;
  cin >> q;
  int sz = 0;
  while (q--) {
    cin >> r;
    if (r == 1) {
      cin >> x;
      val[x].insert(sz++);
    } else {
      cin >> x >> y;
      if (x == y) continue;
      if (val[x].size() > val[y].size()) swap(val[x], val[y]);
      for (auto c : val[x]) {
        val[y].insert(c);
      }
      val[x].clear();
    }
  }
  vector<int> ans(sz);
  for (int i = 0; i < MAXN; i++) {
    for (auto c : val[i]) {
      ans[c] = i;
    }
  }
  for (auto c : ans) cout << c << ' ';
  cout << '\n';
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
}
