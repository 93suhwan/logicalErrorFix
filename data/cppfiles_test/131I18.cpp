#include <bits/stdc++.h>
using namespace std;
int main() {
  ios ::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  if (fopen("main.in", "r"))
    freopen("main.in", "r", stdin), freopen("main.out", "w", stdout);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &x : a) cin >> x;
  unordered_map<int, int> pos;
  unordered_map<int, vector<int>> adj;
  queue<int> q;
  for (int i = 0; i < n; i++) {
    q.push(a[i]);
    pos[a[i]] = i;
  }
  while (q.size()) {
    int x = q.front();
    q.pop();
    if (x == 0) continue;
    int k = ceil(log2(x));
    int p = (1 << k) - x;
    if (!adj.count(p)) q.push(p);
    adj[p].push_back(x);
    adj[x].push_back(p);
  }
  unordered_map<int, int> d;
  function<int(int, int, int)> findFurthest = [&adj, &d, &findFurthest](
                                                  int u, int pu, int dep) {
    d[u] = dep;
    int ans = u;
    for (int v : adj[u]) {
      if (v == pu) continue;
      int x = findFurthest(v, u, dep + 1);
      if (d[ans] < d[x]) ans = x;
    }
    return ans;
  };
  int u = findFurthest(a[0], -1, 0);
  int v = findFurthest(u, -1, 0);
  cout << pos[u] << ' ' << pos[v] << ' ' << d[v] << '\n';
  return 0;
}
