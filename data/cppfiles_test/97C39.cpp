#include <bits/stdc++.h>
std::priority_queue<std::pair<long long, int>,
                    std::vector<std::pair<long long, int>>,
                    std::greater<std::pair<long long, int>>>
    pq, del;
struct node {
  long long a, b;
  node(long long x = 0, long long y = 0) : a(y), b(x) {}
  node operator+(node const &y) const { return node(b + y.b, a + y.a); }
  node operator-(node const &y) const { return node(b - y.b, a - y.a); }
  node operator-() const { return node(-b, -a); }
  long long operator()(long long x) const { return a * x + b; }
  long long zero() const { return std::ceil((1. - b) / (a + 1.)); }
};
std::vector<int> v[200010];
node a[200010], c[200010];
int bg[200010], f[200010], ct, cnt, ed[200010], q[200010], n, m, fa[200010];
long long ans[1000010];
void upd(int i, node p) {
  if (i)
    for (; i <= n; i += i & -i) c[i] = c[i] + p;
}
node que(int i) {
  node ans;
  for (; i; i &= i - 1) ans = ans + c[i];
  return ans;
}
node query(int x) { return que(ed[x]) - que(bg[x] - 1); }
void update(int x, int y, node v) { upd(bg[fa[x]], -v), upd(bg[fa[y]], v); }
void dfs(int x, int f) {
  fa[x] = f;
  ::f[x] = x;
  bg[x] = ++cnt;
  for (auto u : v[x])
    if (u != f) ++a[x].b, dfs(u, x);
  ed[x] = cnt;
  upd(bg[fa[x]], node(1)), upd(bg[fa[fa[x]]], node(-1));
}
auto find = [](int x) {
  while (x != f[x]) x = f[x] = f[f[x]];
  return x;
};
auto clr = []() {
  while (del.size() && pq.top() == del.top()) pq.pop(), del.pop();
};
auto top = []() {
  clr();
  return pq.top();
};
auto pop = []() {
  clr();
  pq.pop();
};
int main() {
  scanf("%d", &n);
  for (int i = 2, x, y; i <= n; i++)
    scanf("%d%d", &x, &y), v[x].push_back(y), v[y].push_back(x);
  dfs(1, 0);
  for (int i = 2; i <= n; i++)
    if (a[i].b) pq.emplace(a[i].zero(), -i);
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) {
    long long b;
    scanf("%d%lld", q + i, &b);
    pq.emplace(-b, i);
  }
  while (ct < m) {
    auto [x, id] = top();
    pop();
    if (id < 0) {
      id = -id;
      if (id == 1) continue;
      int u = find(fa[id]);
      f[id] = u;
      if (u != 1) del.emplace(query(u).zero(), -u);
      update(u, id, query(id) + node(-1, 1));
      if (u != 1) pq.emplace(query(u).zero(), -u);
    } else {
      ans[id] = query(q[id])(x);
      ++ct;
    }
  }
  for (int i = 1; i <= m; i++) printf("%lld\n", ans[i]);
  return 0;
}
