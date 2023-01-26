#include <bits/stdc++.h>
using namespace std;
int msb(int n) { return 32 - __builtin_clz(n); }
map<int, int> ind;
map<int, vector<int>> adj;
int n;
void build(int x) {
  cout << x << " ";
  while (x > 0) {
    int m = msb(x);
    int nxt = (1 << m) - x;
    if (x == nxt) nxt = 0;
    if (adj[nxt].size()) {
      adj[nxt].push_back(x);
      break;
    }
    adj[nxt].push_back(x);
    x = nxt;
  }
}
pair<int, int> par = {-1, -1};
int val = 0;
pair<int, int> dfs(int v) {
  vector<pair<int, int>> first;
  first.push_back({0, v});
  for (auto x : adj[v]) {
    pair<int, int> p = dfs(x);
    p.first++;
    first.push_back(p);
  }
  sort(begin(first), end(first),
       [&](pair<int, int> a, pair<int, int> b) { return a.first > b.first; });
  if (first.size() == 1) return first[0];
  if (first[0].first + first[1].first > val) {
    par = {first[0].second, first[1].second};
    val = first[0].first + first[1].first;
  }
  return first[0];
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    build(x);
    ind[x] = i;
  }
  dfs(0);
  cout << ind[par.first] << " " << ind[par.second] << " " << val << endl;
}
