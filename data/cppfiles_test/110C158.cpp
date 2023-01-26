#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200010;
const int INF = 1e9;
int n, in[MAXN], dist[MAXN];
vector<int> graph[MAXN];
void solve() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    graph[i].clear();
    in[i] = 0;
    dist[i] = INF;
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", &in[i]);
    for (int j = 0, a; j < in[i]; j++) {
      scanf("%d", &a);
      graph[a].push_back(i);
    }
  }
  set<pair<int, int> > s;
  for (int i = 1; i <= n; i++)
    if (!in[i]) s.insert({0, i}), dist[i] = 0;
  int ans = 0, cnt = 0;
  while (!s.empty()) {
    int v = s.begin()->second;
    s.erase(s.begin());
    cnt++;
    ans = max(ans, dist[v]);
    for (int i = 0; i < (int)graph[v].size(); i++) {
      int u = graph[v][i];
      in[u]--;
      if (!in[u]) {
        dist[u] = dist[v] + (u < v);
        s.insert({dist[u], u});
      }
    }
  }
  printf("%d\n", (cnt == n) ? ans + 1 : -1);
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) solve();
}
