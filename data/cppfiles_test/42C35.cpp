#include <bits/stdc++.h>
#pragma optimize(Ofast)
using namespace std;
struct node {
  node *l, *r;
  int a, b;
  long long sum, val;
  node(int _a, int _b) : a(_a), b(_b), l(NULL), r(NULL), sum(0), val(0) {}
} * root, *root2;
const int mod = 1e9 + 7;
void pull(node *n) { n->sum = (n->l->sum + n->r->sum) % mod; }
void build(node *n) {
  if (n->a == n->b) return;
  int mid = (n->a + n->b) / 2;
  n->l = new node(n->a, mid);
  n->r = new node(mid + 1, n->b);
  build(n->l);
  build(n->r);
}
void update(node *n, int k, int w, int v) {
  if (n->a == n->b) {
    n->sum = w;
    return;
  }
  int mid = (n->a + n->b) / 2;
  if (k <= mid)
    update(n->l, k, w, v);
  else
    update(n->r, k, w, v);
  pull(n);
}
long long query(node *n, int l, int r, int val) {
  if (n->a >= l && n->b <= r) return n->sum;
  if (n->b < l || n->a > r) return 0;
  return (query(n->l, l, r, val) + query(n->r, l, r, val)) % mod;
}
void solve() {
  int n;
  scanf("%d", &n);
  root = new node(1, 2 * n);
  build(root);
  root2 = new node(1, 2 * n);
  build(root2);
  pair<pair<int, int>, int> p[200005];
  for (int i = 0; i < n; i++) {
    int first, second;
    scanf("%d %d", &first, &second);
    p[i] = make_pair(make_pair(second, first), 0);
  }
  int qq;
  scanf("%d", &qq);
  for (int i = 1; i <= qq; i++) {
    int first;
    scanf("%d", &first);
    p[first - 1].second = 1;
  }
  sort(p, p + n);
  long long val[200005];
  for (int i = 0; i < n; i++) {
    long long res = query(root, p[i].first.second, p[i].first.first, 0);
    long long v = res + 1;
    val[i] = v;
    update(root, p[i].first.second, v, p[i].first.first);
    update(root2, p[i].first.first, v, p[i].first.first);
  }
  long long res = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (p[i].second == 1) {
      for (int j = 0; j < i; j++) res += val[j];
      res++;
      res %= mod;
      int val = p[i].first.second;
      for (int j = n - 1; j >= i; j--) update(root, p[j].first.second, 0, 0);
      for (int j = i - 1; j >= 0; j--) {
        update(root, p[j].first.second, 0, 0);
        if (p[j].first.second > val && p[j].second) {
          res += query(root, val, p[j].first.first - 1, 0);
          res++;
          res %= mod;
          val = p[j].first.second;
        }
      }
      printf("%lld\n", res);
      return;
    }
  }
}
int main() {
  int t = 1;
  0000;
  for (int i = 1; i <= t; i++) {
    solve();
  }
  return 0;
}
