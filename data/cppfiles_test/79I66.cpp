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
  vector<int> dis(n + 1, INT_MAX);
  dis[n] = 0;
  vector<int> sl(n + 1, 0), sc(n + 1, 0);
  queue<int> q;
  q.push(n);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = u - a[u]; i <= u; ++i) {
      if (i <= 0) {
        dis[0] = dis[u] + 1;
        sc[0] = u;
        break;
      }
      int v = min(n, i + b[i]);
      if (v >= top) continue;
      top = min(top, v);
      dis[v] = dis[u] + 1;
      sl[v] = i;
      sc[v] = u;
      q.push(v);
    }
  }
  if (dis[0] == INT_MAX) {
    cout << -1 << '\n';
    return 0;
  }
  vector<int> ans;
  for (int i = 0; i != n; i = sc[i]) ans.emplace_back(sl[i]);
  reverse(begin(ans), end(ans));
  cout << dis[0] << '\n';
  for (int i : ans) cout << i << ' ';
  return 0;
}
