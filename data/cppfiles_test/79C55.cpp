#include <bits/stdc++.h>
using namespace std;
template <class I>
bool chmax(I& a, I b) {
  return a < b ? (a = b, true) : false;
}
template <class I>
bool chmin(I& a, I b) {
  return b < a ? (a = b, true) : false;
}
#pragma GCC optimize("Ofast")
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<int> a(n + 1), b(n + 1);
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= n; ++i) cin >> b[i];
  int top = n;
  queue<int> q;
  q.push(n);
  vector<int> sc(n + 1, -1), sl(n + 1, -1);
  sl[n] = n;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    if (u - a[u] == 0) {
      sc[0] = u;
      break;
    }
    for (int i = u - a[u]; i < top; ++i) {
      int v = i + b[i];
      if (sl[v] != -1) continue;
      sc[i] = u;
      sl[v] = i;
      q.push(v);
    }
    top = min(top, u - a[u]);
  }
  if (sc[0] == -1) {
    cout << -1 << '\n';
    return 0;
  }
  vector<int> ans;
  for (int i = 0; i != n;) {
    ans.emplace_back(i);
    i = sl[sc[i]];
  }
  reverse(begin(ans), end(ans));
  cout << ans.size() << '\n';
  for (int i : ans) cout << i << ' ';
  return 0;
}
