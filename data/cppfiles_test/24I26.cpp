#include <bits/stdc++.h>
using namespace std;
const int N = 300005;
int n, m, q, fr[N], pk[N], od[N], rt[N << 5], lc[N << 5], rc[N << 5],
    tr[N << 5], c = 1, ps[N], rk[N], zz = 1, st[N];
vector<pair<int, int>> e[N];
unsigned long long dis[N], ans[N], t, a[N], px[N];
priority_queue<pair<unsigned long long, int>> pq;
int ins(int u, int l, int r, int x, int v) {
  int k = ++c;
  lc[k] = lc[u], rc[k] = rc[u], tr[k] = tr[u];
  if (l == r) {
    tr[k] += v;
    return k;
  }
  int mid = l + r >> 1;
  if (x <= mid)
    lc[k] = ins(lc[k], l, mid, x, v);
  else
    rc[k] = ins(rc[k], mid + 1, r, x, v);
  return k;
}
int query(int k, int l, int r, int x) {
  if (!k) return 0;
  if (l == r) return tr[k];
  int mid = l + r >> 1;
  if (x <= mid)
    return query(lc[k], l, mid, x);
  else
    return query(rc[k], mid + 1, r, x);
}
int ask(int l, int r, int x) {
  if (x == -1) return ps[r] - ps[l - 1];
  if (x == 1) return 0;
  if (l > r) return 0;
  if (x > 0)
    return query(rt[r], 1, n, x) - query(rt[l - 1], 1, n, x);
  else
    return ps[r] - ps[l - 1] - query(rt[r], 1, n, -x) +
           query(rt[l - 1], 1, n, -x);
}
struct nd {
  int p, mn, cm;
  bool operator<(const nd k) const {
    if (zz == 1) {
      if (p != k.p) return p < k.p;
      return a[mn] > a[k.mn];
    } else {
      if (mn != k.mn) return a[mn] > a[k.mn];
      return a[cm] > a[k.cm];
    }
  }
};
set<nd> s;
int main() {
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= m; i++) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    e[u].emplace_back(v, w);
    e[v].emplace_back(u, w);
  }
  for (int i = 0; i < q; i++) {
    int k, x;
    scanf("%d%d", &k, &x);
    pk[i] = k, px[i] = a[k];
    a[k] += x;
  }
  for (int i = 1; i <= n; i++) dis[i] = 1e18;
  dis[1] = 0;
  pq.emplace(0, 1);
  while (!pq.empty()) {
    auto k = pq.top();
    pq.pop();
    int u = k.second;
    if (dis[u] != -k.first) continue;
    for (auto [v, w] : e[u]) {
      if (dis[v] > dis[u] + w) {
        dis[v] = dis[u] + w;
        pq.emplace(-dis[v], v);
      }
    }
  }
  for (int u = 1; u <= n; u++) {
    od[u] = u;
    for (auto [v, w] : e[u]) {
      if (dis[u] + w == dis[v]) {
        if (fr[v])
          fr[v] = -1;
        else
          fr[v] = u;
      }
    }
  }
  sort(od + 1, od + n + 1, [&](int x, int y) { return dis[x] < dis[y]; });
  rt[0] = rt[1] = 1;
  for (int i = 2; i <= n; i++) {
    int d = od[i];
    rk[d] = i;
    ps[i] = ps[i - 1];
    if (fr[d] == -1)
      rt[i] = rt[i - 1];
    else
      rt[i] = ins(rt[i - 1], 1, n, fr[d], 1), ps[i]++;
  }
  int mn = 1, cm = 1;
  s.insert({2, mn, cm});
  a[0] = 0, a[n + 1] = 9e18;
  for (int i = 2, j = 2; i <= n + 1; i++) {
    if (dis[od[j]] != dis[od[i]]) {
      for (int k = j; k < i; k++) {
        int d = od[k];
        st[d] = i;
        if (a[d] < a[cm]) {
          if (a[d] < a[mn])
            cm = mn, mn = d;
          else
            cm = d;
          s.insert({i, mn, cm});
        }
      }
      j = i;
    }
  }
  s.insert({n + 1, 0, 0});
  for (auto i = s.begin();; i++) {
    auto j = i;
    j++;
    if (j == s.end()) break;
    t += a[(i->cm)] * ask(i->p, (j->p) - 1, i->mn);
    t += a[(i->mn)] * ask(i->p, (j->p) - 1, -(i->mn));
  }
  ans[q] = t;
  for (int i = q - 1; i >= 0; i--) {
    int u = pk[i];
    unsigned long long dt = a[u] - px[i], v = px[i];
    auto it = s.lower_bound({st[u], n + 1, 0}), bg = it;
    vector<nd> ins;
    if (it->mn == u) {
      zz = 2;
      auto ed = s.lower_bound({0, u, 0});
      zz = 1;
      t -= dt * ask(it->p, (ed->p) - 1, -u);
      bg = ed;
    } else if ((bg->p) > st[u]) {
      int r = (bg->p) - 1;
      bg--;
      auto nx = *bg;
      if (v < a[nx.mn]) {
        nx.cm = nx.mn;
        nx.mn = u;
      } else if (v < a[nx.cm])
        nx.cm = u;
      else {
        ans[i] = ans[i + 1];
        continue;
      }
      t -= a[bg->cm] * ask(st[u], r, bg->mn);
      t -= a[bg->mn] * ask(st[u], r, -(bg->mn));
      nx.p = st[u];
      t += (nx.cm == u ? v : a[nx.cm]) * ask(st[u], r, nx.mn);
      t += (nx.mn == u ? v : a[nx.mn]) * ask(st[u], r, -nx.mn);
      ins.push_back(nx);
      bg++;
    }
    while (1) {
      auto nx = bg;
      nx++;
      if (nx == s.end()) break;
      if (v < a[bg->cm] || (v == a[bg->cm] && rk[u] <= (bg->cm))) {
        auto dl = bg;
        auto x = *bg;
        t -= a[bg->cm] * ask(bg->p, (nx->p) - 1, bg->mn);
        t -= a[bg->mn] * ask(bg->p, (nx->p) - 1, -(bg->mn));
        if (v < a[bg->mn] || (v == a[bg->mn] && rk[u] < (bg->mn))) {
          x.cm = bg->mn;
          x.mn = u;
        } else
          x.cm = u;
        t += (x.cm == u ? v : a[x.cm]) * ask(bg->p, (nx->p) - 1, x.mn);
        t += (x.mn == u ? v : a[x.mn]) * ask(bg->p, (nx->p) - 1, -x.mn);
        ins.push_back(x);
        bg = nx;
        s.erase(dl);
      } else
        break;
    }
    a[u] = v;
    for (int j = 0; j < ins.size(); j++)
      if (!j || ins[j].mn != ins[j - 1].mn || ins[j].cm != ins[j - 1].cm)
        s.insert(ins[j]);
    ans[i] = t;
  }
  for (int i = 0; i <= q; i++) printf("%llu\n", ans[i]);
  return 0;
}
