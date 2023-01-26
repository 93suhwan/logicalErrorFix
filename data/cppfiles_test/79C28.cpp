#include <bits/stdc++.h>
using namespace std;
const int offset = 300001;
int a[300005];
int b[300005];
int c[300005];
struct edge {
  int v;
  long long w;
};
vector<edge> G[1000005];
int pre[1000005];
int vis[1000005];
long long dist[1000005];
void add(int u, int v, int w) { G[u].push_back({v, w}); }
struct node {
  int v;
  long long w;
  friend bool operator<(node a, node b) { return a.w > b.w; }
} fa, son;
void dijkstra(int s) {
  memset(vis, 0, sizeof(vis));
  memset(dist, 0x3f, sizeof(dist));
  priority_queue<node> q;
  dist[s] = 0;
  q.push({s, 0});
  while (!q.empty()) {
    fa = q.top();
    q.pop();
    if (vis[fa.v]) continue;
    vis[fa.v] = 1;
    for (edge e : G[fa.v]) {
      if (fa.w + e.w < dist[e.v]) {
        dist[e.v] = fa.w + e.w;
        pre[e.v] = fa.v;
        q.push({e.v, dist[e.v]});
      }
    }
  }
}
int main() {
  memset(pre, 0xff, sizeof(pre));
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &b[i]);
    c[i] = i + b[i];
  }
  add(offset, 0, 0);
  for (int i = 1; i <= n; ++i) {
    add(i - 1 + offset, i + offset, 0);
    add(i, i - a[i] + offset, 1);
    add(i + offset, c[i], 0);
  }
  dijkstra(n);
  vector<int> path;
  int cur = 0;
  while (cur != -1) {
    path.push_back(cur);
    cur = pre[cur];
  }
  if (dist[0] > 1e9) {
    puts("-1");
    return 0;
  }
  printf("%lld\n", dist[0]);
  reverse(path.begin(), path.end());
  for (int i = 0; i < path.size() - 1; ++i) {
    if (path[i] > offset && path[i + 1] < offset) {
      printf("%d ", path[i] - offset);
    }
  }
  puts("0");
  return 0;
}
