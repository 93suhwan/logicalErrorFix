#include <bits/stdc++.h>
using namespace std;
int N, a[600001], b[600001], rt, tot, ls[3000001], rs[3000001], pre[3000001],
    dep[3000001];
vector<pair<int, int>> E[3000001];
int get() {
  int x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') c == '-' && (f = -1), c = getchar();
  while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
  return x * f;
}
void build(int& k, int l, int r) {
  if (!k) k = ++tot;
  if (l != r)
    build(ls[k], l, (l + r >> 1)), build(rs[k], (l + r >> 1) + 1, r),
        E[k].push_back({ls[k], 0}), E[k].push_back({rs[k], 0});
  else if (l)
    E[k].push_back({l + N, 0});
  else
    E[k].push_back({l, 0});
}
void upd(int k, int l, int r, int x, int y, int v) {
  return l <= y && r >= x ? l < x || r > y
         ? upd(ls[k], l, (l + r >> 1), x, y, v),
         upd(rs[k], (l + r >> 1) + 1, r, x, y, v)
         : E[v].push_back({k, 1})
         : void(0);
}
void print(int x) {
  if (pre[x]) print(pre[x]);
  if (!x || (x > N && x <= N * 2)) cout << (x ? x - N : x) << ' ';
}
int main() {
  N = get();
  tot = N * 2;
  for (int i = 1; i <= N; i++) a[i] = get();
  for (int i = 1; i <= N; i++) b[i] = get();
  for (int i = 1; i <= N; i++) E[i + N].push_back({i + b[i], 0});
  build(rt, 0, N);
  for (int i = 1; i <= N; i++) upd(rt, 0, N, i - a[i], i - 1, i);
  deque<int> q;
  q.push_back(N);
  for (int i = 0; i <= tot; i++) dep[i] = -1;
  dep[N] = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop_front();
    if (!u) break;
    for (auto v : E[u])
      if (dep[v.first] == -1)
        v.second
            ? pre[v.first] = u,
              dep[v.first] = dep[u] + 1,
              q.push_back(v.first)
            : (pre[v.first] = u, dep[v.first] = dep[u], q.push_front(v.first));
  }
  if (dep[0] == -1) {
    cout << "-1\n";
    return 0;
  }
  cout << dep[0] << '\n';
  print(0);
  return 0;
}
