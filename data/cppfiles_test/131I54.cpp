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
  vector<int> real(n);
  queue<int> q;
  for (int i = 0; i < n; i++) {
    q.push(a[i]);
    pos[a[i]] = i;
    real[i] = a[i];
  }
  vector<vector<int> > adj(32 * n);
  while (q.size()) {
    int x = q.front();
    q.pop();
    if (x == 0) continue;
    int k = ceil(log2(x));
    int p = (1 << k) - x;
    if (!pos.count(p)) {
      q.push(p);
      pos[p] = pos.size();
    }
    adj[pos[p]].push_back(pos[x]);
    adj[pos[x]].push_back(pos[p]);
  }
  vector<int> d(adj.size());
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
  int u = findFurthest(0, -1, 0);
  int v = findFurthest(u, -1, 0);
  cout << pos[real[u]] + 1 << ' ' << pos[real[v]] + 1 << ' ' << d[v] << '\n';
  return 0;
}
