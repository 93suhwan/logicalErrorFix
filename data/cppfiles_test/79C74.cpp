#include <bits/stdc++.h>
const int Maxn = 3e5 + 5;
int dis[Maxn], n, a[Maxn], b[Maxn], pre[Maxn], pre2[Maxn], tr[Maxn];
std::queue<int> q;
std::set<int, std::greater<int> > s;
void relax(int u, int v) {
  if (dis[u] + 1 < dis[v]) {
    dis[v] = dis[u] + 1;
    pre[v] = u;
  }
}
void printans(int u) {
  if (u == n) return;
  printans(pre[pre2[u]]);
  printf("%d ", pre2[u]);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  for (int i = 1; i <= n; ++i) scanf("%d", &b[i]);
  for (int i = 1; i <= n; ++i) tr[i] = std::min(n, i + b[i]);
  int inf;
  memset(dis, 67, sizeof dis);
  inf = dis[0];
  q.push(n);
  dis[n] = 0;
  for (int i = 1; i < n; ++i) s.insert(i);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    auto it1 = s.lower_bound(u), it2 = s.upper_bound(u - a[u]);
    if (u - a[u] <= 0) relax(u, 0);
    while (it1 != it2) {
      int v = *it1 + b[*it1];
      if (dis[u] + 1 < dis[v]) {
        dis[v] = dis[u] + 1;
        pre2[v] = *it1;
        pre[*it1] = u;
        q.push(v);
      }
      s.erase(it1++);
    }
  }
  if (dis[0] == inf)
    printf("-1");
  else
    printf("%d\n", dis[0]), printans(0);
  return 0;
}
