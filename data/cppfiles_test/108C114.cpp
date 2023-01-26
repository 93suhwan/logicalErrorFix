#include <bits/stdc++.h>
using namespace std;
struct SCC {
  vector<vector<int>> adj, scc;
  vector<int> num, low, stack, vs, sccIdx;
  int time, n;
  SCC(int n) : n(n) {
    adj.resize(n + 1);
    num.resize(n + 1);
    low.resize(n + 1);
    vs.resize(n + 1);
    sccIdx.resize(n + 1);
    time = 0;
  }
  void addEdge(int u, int v) { adj[u].push_back(v); }
  void setup() {
    for (int i = 1; i <= n; i++) {
      if (!num[i]) dfs(i);
    }
  }
  void dfs(int a) {
    low[a] = num[a] = ++time;
    stack.push_back(a);
    for (auto i : adj[a]) {
      if (!num[i]) dfs(i);
      if (!vs[i]) low[a] = min(low[a], low[i]);
    }
    if (num[a] == low[a]) {
      vector<int> curSCC;
      while (stack.size()) {
        int b = stack.back();
        curSCC.push_back(b);
        stack.pop_back();
        vs[b] = 1;
        if (b == a) break;
      }
      scc.push_back(curSCC);
      for (auto i : curSCC) {
        sccIdx[i] = scc.size();
      }
    }
  }
};
struct Player {
  int x, y, idx;
};
bool cmp1(Player &a, Player &b) { return a.x < b.x; }
bool cmp2(Player &a, Player &b) { return a.y < b.y; }
Player a[100005];
int res[100005];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  int t;
  cin >> t;
  for (int z = 1; z <= t; z++) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i].x;
    }
    for (int i = 1; i <= n; i++) {
      cin >> a[i].y;
      a[i].idx = i;
    }
    SCC scc(n);
    sort(a + 1, a + n + 1, cmp1);
    int root1 = a[n].idx;
    res[root1] = 1;
    for (int i = 1; i < n; i++) {
      int u = a[i].idx;
      int v = a[i + 1].idx;
      scc.addEdge(u, v);
    }
    sort(a + 1, a + n + 1, cmp2);
    int root2 = a[n].idx;
    res[root2] = 1;
    for (int i = 1; i < n; i++) {
      int u = a[i].idx;
      int v = a[i + 1].idx;
      scc.addEdge(u, v);
    }
    scc.setup();
    int r1 = scc.sccIdx[root1];
    for (auto i : scc.scc[r1 - 1]) {
      res[i] = 1;
    }
    int r2 = scc.sccIdx[root2];
    for (auto i : scc.scc[r2 - 1]) {
      res[i] = 1;
    }
    for (int i = 1; i <= n; i++) {
      cout << res[i];
    }
    cout << "\n";
    for (int i = 1; i <= n; i++) res[i] = 0;
  }
  return 0;
}
