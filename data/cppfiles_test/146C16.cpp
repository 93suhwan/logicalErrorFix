#include <bits/stdc++.h>
using namespace std;
void solve();
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
}
const long long N = 1e5 + 100, INF = 2e18, MOD = 1e9 + 7;
mt19937_64 rnd(time(0));
struct node {
  node* l = nullptr;
  node* r = nullptr;
  node* p = nullptr;
  long long x, y, sz;
  node(long long x) : x(x), y(rnd()), sz(1) {}
};
long long size(node* t) {
  if (t == nullptr) return 0;
  return t->sz;
}
void update(node* t) { t->sz = size(t->l) + size(t->r) + 1; }
pair<node*, node*> split(node* t, long long k) {
  if (t == nullptr) return {nullptr, nullptr};
  if (k >= size(t->l) + 1) {
    pair<node*, node*> z = split(t->r, k - size(t->l) - 1);
    if (z.first != nullptr) z.first->p = t;
    if (z.second != nullptr) z.second->p = nullptr;
    t->r = z.first;
    update(t);
    return {t, z.second};
  } else {
    pair<node*, node*> z = split(t->l, k);
    if (z.first != nullptr) z.first->p = nullptr;
    if (z.second != nullptr) z.second->p = t;
    t->l = z.second;
    update(t);
    return {z.first, t};
  }
}
node* merge(node* a, node* b) {
  if (a == nullptr) return b;
  if (b == nullptr) return a;
  if (a->y > b->y) {
    a->r = merge(a->r, b);
    if (a->r != nullptr) a->r->p = a;
    update(a);
    return a;
  } else {
    b->l = merge(a, b->l);
    if (b->l != nullptr) b->l->p = b;
    update(b);
    return b;
  }
}
pair<node*, long long> find(node* t) {
  long long pos = size(t->l);
  while (t->p != nullptr) {
    node* z = t;
    t = t->p;
    if (t->r == z) {
      pos += size(t->l) + 1;
    }
  }
  return {t, pos};
}
void pri(node* t) {
  if (t->l != nullptr) pri(t->l);
  cout << t->x + 1 << " ";
  if (t->r != nullptr) pri(t->r);
}
void print(node* t) {
  pri(find(t).first);
  cout << endl;
}
long long n, q, p[N];
vector<long long> go;
node* t[N];
bool used[N];
void dfs(long long v) {
  used[v] = true;
  go.push_back(v);
  if (!used[p[v]]) dfs(p[v]);
}
void solve() {
  cin >> n >> q;
  for (long long i = 0; i < n; i++) {
    cin >> p[i];
    p[i]--;
    t[i] = new node(i);
  }
  for (long long i = 0; i < n; i++) {
    if (!used[i]) {
      go.clear();
      dfs(i);
      node* z = t[go[0]];
      for (long long j = 1; j < go.size(); j++) {
        z = merge(z, t[go[j]]);
      }
    }
  }
  for (long long qq = 0; qq < q; qq++) {
    long long ty, x, y;
    cin >> ty >> x >> y;
    if (ty == 1) {
      x--, y--;
      pair<node*, long long> z1 = find(t[x]);
      pair<node*, long long> z2 = find(t[y]);
      if (z1.first == z2.first) {
        if (z1.second > z2.second) swap(z1, z2);
        pair<node*, node*> sp1 = split(z1.first, z2.second + 1);
        pair<node*, node*> sp2 = split(sp1.first, z1.second + 1);
        merge(sp2.first, sp1.second);
      } else {
        pair<node*, node*> sp1 = split(z1.first, z1.second + 1);
        pair<node*, node*> sp2 = split(z2.first, z2.second + 1);
        node* tt = merge(sp2.second, sp2.first);
        merge(merge(sp1.first, tt), sp1.second);
      }
    } else {
      x--;
      pair<node*, long long> z = find(t[x]);
      long long len = size(z.first);
      y %= len;
      node* tt = z.first;
      if (z.second + y < len) {
        y = z.second + y;
      } else {
        y = z.second + y - len;
      }
      pair<node*, node*> e = split(tt, y + 1);
      pair<node*, node*> u = split(e.first, y);
      cout << u.second->x + 1 << '\n';
      merge(merge(u.first, u.second), e.second);
    }
  }
}
