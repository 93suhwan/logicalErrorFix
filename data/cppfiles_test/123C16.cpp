#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
const long long INF = 1e18;
const long long Mod = 998244353;
int n, k;
vector<int> g[200010];
priority_queue<int> pq[200010];
void dfs(int x, int p = 0) {
  int cnt = 0;
  for (auto i : g[x]) {
    if (i == p) continue;
    cnt++;
    dfs(i, x);
    if (pq[x].size() < pq[i].size()) swap(pq[x], pq[i]);
    while (pq[i].size()) {
      pq[x].emplace(pq[i].top());
      pq[i].pop();
    }
  }
  if (cnt == 0) pq[x].emplace(0);
  int y = pq[x].top();
  pq[x].pop();
  pq[x].emplace(y + 1);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ;
  cin >> n >> k;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }
  dfs(1);
  int sum = 0;
  long long ans = -INF;
  for (int i = 1; i <= k; i++) {
    if (pq[1].size()) {
      sum += pq[1].top();
      pq[1].pop();
    }
    long long b = min(n - sum, n / 2);
    ans = max(ans, (n - i - b) * (i - b));
  }
  cout << ans;
}
