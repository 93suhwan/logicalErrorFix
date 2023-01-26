#include <bits/stdc++.h>
using namespace std;
template <typename T>
bool chkmx(T &x, T y) {
  return x < y ? x = y, true : false;
}
template <typename T>
bool chkmn(T &x, T y) {
  return x > y ? x = y, true : false;
}
const int maxn = 1e5;
const int lg = 20;
const int inf = 2e9;
int n, m, q, u, v, w, mn, ans[maxn + 5];
int root[maxn + 5];
map<array<int, 2>, array<int, 2> > mp;
vector<array<int, 5> > e;
vector<array<int, 3> > ins[maxn * 4 + 5];
vector<int> s;
set<array<int, 2> > f[maxn + 5], all;
struct Segment {
  int nodecnt = 0, siz[maxn * 4 * lg], ls[maxn * 4 * lg], rs[maxn * 4 * lg];
  void update(int &rt, int l, int r, int p, int k) {
    if (!rt) rt = ++nodecnt;
    siz[rt] += k;
    if (l == r) return;
    int mid = l + r >> 1;
    if (p <= mid)
      update(ls[rt], l, mid, p, k);
    else if (p > mid)
      update(rs[rt], mid + 1, r, p, k);
  }
  int query(int rt, int u, int v, int l, int r) {
    if (l == r) return l;
    int res = siz[ls[rt]] - siz[ls[u]] - siz[ls[v]], mid = l + r >> 1;
    if (res)
      return query(ls[rt], ls[u], ls[v], l, mid);
    else
      return query(rs[rt], rs[u], rs[v], mid + 1, r);
  }
} t;
void push(int rt, int l, int r, array<int, 5> p) {
  if (l >= p[1] && r <= p[2]) {
    ins[rt].push_back({p[3], p[4], p[0]});
    return;
  }
  int mid = l + r >> 1;
  if (p[2] <= mid)
    push(rt << 1, l, mid, p);
  else if (p[1] > mid)
    push(rt << 1 | 1, mid + 1, r, p);
  else
    push(rt << 1, l, mid, p), push(rt << 1 | 1, mid + 1, r, p);
}
void solve(int rt, int l, int r) {
  int lst = mn;
  for (auto x : ins[rt]) {
    if (t.siz[root[0]] > t.siz[root[x[0]]] + t.siz[root[x[1]]]) {
      chkmn(mn,
            s[t.query(root[0], root[x[0]], root[x[1]], 0, m + q)] + s[x[2]]);
    }
    t.update(root[x[0]], 0, m + q, x[2], 1);
    t.update(root[x[1]], 0, m + q, x[2], 1);
    t.update(root[0], 0, m + q, x[2], 1);
  }
  if (l == r)
    chkmn(ans[l], mn);
  else {
    int mid = l + r >> 1;
    solve(rt << 1, l, mid), solve(rt << 1 | 1, mid + 1, r);
  }
  for (auto x : ins[rt]) {
    t.update(root[x[0]], 0, m + q, x[2], -1);
    t.update(root[x[1]], 0, m + q, x[2], -1);
    t.update(root[0], 0, m + q, x[2], -1);
  }
  mn = lst;
}
int get(int u) {
  if ((int)(f[u].size()) < 3) return inf;
  int res = 0;
  auto it = f[u].begin();
  for (int i = (0); i <= int(2); i++) res += (*it)[0], it++;
  return res;
}
void add(int u, int v, int w) {
  all.erase({get(u), u});
  f[u].insert({w, v});
  all.insert({get(u), u});
}
void del(int u, int v, int w) {
  all.erase({get(u), u});
  f[u].erase({w, v});
  all.insert({get(u), u});
}
int main() {
  cin >> n >> m;
  for (int i = (1); i <= int(n); i++) all.insert({inf, i});
  for (int i = (1); i <= int(m); i++)
    cin >> u >> v >> w, mp[{min(u, v), max(u, v)}] = {w, 0}, add(u, v, w),
                                              add(v, u, w);
  ans[0] = (*all.begin())[0];
  cin >> q;
  for (int i = (1); i <= int(q); i++) {
    int opt;
    cin >> opt;
    if (opt) {
      cin >> u >> v >> w;
      if (u > v) swap(u, v);
      mp[{u, v}] = {w, i};
      add(u, v, w), add(v, u, w);
    } else {
      cin >> u >> v;
      if (u > v) swap(u, v);
      e.push_back({mp[{u, v}][0], mp[{u, v}][1], i - 1, u, v});
      s.push_back(mp[{u, v}][0]);
      del(u, v, mp[{u, v}][0]), del(v, u, mp[{u, v}][0]);
      mp.erase({u, v});
    }
    ans[i] = (*all.begin())[0];
  }
  for (auto x : mp) {
    e.push_back({x.second[0], x.second[1], q, x.first[0], x.first[1]});
    s.push_back(x.second[0]);
  }
  sort(s.begin(), s.end()), s.erase(unique(s.begin(), s.end()), s.end());
  for (auto x : e) {
    x[0] = lower_bound(s.begin(), s.end(), x[0]) - s.begin();
    push(1, 0, q, x);
  }
  mn = inf, solve(1, 0, q);
  for (int i = (0); i <= int(q); i++) cout << ans[i] << '\n';
  return 0;
}
