#include <bits/stdc++.h>
using namespace std;
const int maxn = 4e5 + 5;
const int mod = 1e9 + 7;
int match[maxn], n, t[maxn << 2], val[maxn], matchid[maxn];
void pushup(int rt) { t[rt] = (t[rt << 1] + t[rt << 1 | 1]) % mod; }
void cg(int x, int val, int rt = 1, int l = 1, int r = 2 * n) {
  if (l == r) {
    t[rt] = val;
    return;
  }
  int mid = l + r >> 1;
  if (x <= mid)
    cg(x, val, rt << 1, l, mid);
  else
    cg(x, val, rt << 1 | 1, mid + 1, r);
  pushup(rt);
}
int qry(int ql, int qr, int rt = 1, int l = 1, int r = 2 * n) {
  if (l >= ql && r <= qr) {
    return t[rt];
  }
  int mid = l + r >> 1;
  int ans = 0;
  if (ql <= mid) ans = (ans + qry(ql, qr, rt << 1, l, mid)) % mod;
  if (qr >= mid + 1) ans = (ans + qry(ql, qr, rt << 1 | 1, mid + 1, r)) % mod;
  return ans;
}
struct Node {
  int l, r, id;
  bool operator<(const Node a) const { return r < a.r; }
} a[maxn];
struct Node2 {
  int l, r, id;
  bool operator<(const Node2 a) const { return l < a.l; }
};
int main() {
  scanf("%d", &n);
  set<Node> all;
  set<Node2> all2;
  for (int i = 1; i <= n; ++i) {
    scanf("%d%d", &a[i].l, &a[i].r);
    a[i].id = i;
    match[a[i].l] = a[i].r;
    match[a[i].r] = a[i].l;
    matchid[a[i].l] = i;
    matchid[a[i].r] = i;
    all.insert(a[i]);
    all2.insert(Node2{a[i].l, a[i].r, a[i].id});
  }
  for (int i = 1; i <= 2 * n; ++i) {
    if (match[i] > i) continue;
    cg(match[i], val[matchid[i]] = qry(match[i], i) + 1);
  }
  int k;
  scanf("%d", &k);
  set<Node> s;
  for (int i = 1; i <= k; ++i) {
    int u;
    scanf("%d", &u);
    s.insert(a[u]);
  }
  int ans = 0;
  while (!s.empty()) {
    Node u = *s.rbegin();
    auto it = all.lower_bound(Node{0, u.r, 0});
    while (it != all.end()) {
      cg(it->l, 0);
      s.erase(*it);
      all.erase(*it);
      all2.erase(Node2{it->l, it->r, it->id});
      it = all.lower_bound(Node{0, u.r, 0});
    }
    ans = (ans + qry(1, u.r) + 1) % mod;
    auto it2 = all2.lower_bound(Node2{u.l, 0, 0});
    if (it2 != all2.begin()) {
      it2--;
      while (true) {
        all2.erase(it2);
        s.erase(Node{it2->l, it2->r, it2->id});
        all.erase(Node{it2->l, it2->r, it2->id});
        it2 = all2.lower_bound({u.l, 0, 0});
        if (it2 == all2.begin()) break;
        it2--;
      }
    }
  }
  printf("%d\n", ans);
}
