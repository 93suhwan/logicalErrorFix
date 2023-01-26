#include <bits/stdc++.h>
struct nd {
  nd* ch[2];
  nd* p;
  int sz;
  nd() : ch{0, 0}, p(0), sz(1) {}
};
int size(nd* v) {
  if (!v) return 0;
  return v->sz;
}
void fill_size(nd* v) {
  if (!v) return;
  v->sz = 1 + size(v->ch[0]) + size(v->ch[1]);
}
void zig(nd* v) {
  nd* p = v->p;
  int r = p->ch[1] == v;
  p->ch[r] = v->ch[!r];
  if (p->ch[r]) p->ch[r]->p = p;
  v->ch[!r] = p;
  v->p = p->p;
  if (p->p) p->p->ch[p->p->ch[1] == p] = v;
  p->p = v;
  fill_size(p);
  fill_size(v);
}
void splay(nd* v) {
  while (v->p)
    if (!v->p->p)
      zig(v);
    else if ((v->p->ch[1] == v) == (v->p->p->ch[1] == v->p))
      zig(v->p), zig(v);
    else
      zig(v), zig(v);
}
nd* pow(nd* v, int k) {
  splay(v);
  k += size(v->ch[0]);
  k %= v->sz;
  for (int szl = size(v->ch[0]); k != szl; szl = size(v->ch[0]))
    if (k < szl)
      v = v->ch[0];
    else
      k -= szl + 1, v = v->ch[1];
  splay(v);
  return v;
}
void trans(nd* u, nd* v) {
  splay(u);
  splay(v);
  if (u->p && u->p->p == v) zig(u);
  if (v->ch[0] == u) {
    splay(u);
    std::swap(u, v);
  }
  bool inside = v->ch[1] == u;
  if (inside) {
    v->ch[1] = u->ch[1];
    if (v->ch[1]) v->ch[1]->p = v;
    u->p = 0;
    u->ch[1] = 0;
    fill_size(v);
    fill_size(u);
  } else {
    std::swap(u->ch[1], v->ch[1]);
    if (u->ch[1]) u->ch[1]->p = u;
    if (v->ch[1]) v->ch[1]->p = v;
    fill_size(u);
    fill_size(v);
    nd* rr = v;
    while (rr->ch[1]) rr = rr->ch[1];
    splay(rr);
    rr->ch[1] = u;
    u->p = rr;
    fill_size(rr);
  }
}
void proc() {
  int n, q;
  std::cin >> n >> q;
  std::vector<int> p(n);
  for (int i = 0; i < n; --p[i], i++) std::cin >> p[i];
  std::vector<nd> f(n);
  for (int i = 0; i < n; i++)
    if (!f[i].p && f[i].sz == 1)
      for (int j = i; p[j] != i; j = p[j]) {
        f[j].p = &f[p[j]];
        f[p[j]].ch[0] = &f[j];
        f[p[j]].sz += f[j].sz;
      }
  while (q--) {
    int t, i, k;
    std::cin >> t >> i >> k;
    if (t == 1)
      trans(&f[i - 1], &f[k - 1]);
    else
      std::cout << pow(&f[i - 1], k) - &f[0] + 1 << std::endl;
  }
}
int main() {
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin.sync_with_stdio(false);
  std::cout.sync_with_stdio(false);
  int t = 1;
  while (t--) proc();
  return 0;
}
