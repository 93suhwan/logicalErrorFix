#include <bits/stdc++.h>
constexpr int inf = 1e9;
struct Node {
  int mn, mx, sz, ans;
  Node *l, *r;
  Node(int val = 0) : ans(inf), sz(1) {
    if (val == 1) {
      mn = mx = 0;
    } else {
      mn = inf;
      mx = -inf;
    }
  }
  void recalc() {
    sz = l->sz + r->sz;
    mn = std::min(l->mn, l->sz + r->mn);
    mx = std::max(l->mx, l->sz + r->mx);
    ans = std::min({l->ans, r->ans, (l->sz + r->mn) - l->mx});
  }
  Node(Node *left, Node *right) : l(left), r(right) { recalc(); }
};
constexpr int K = 19;
int n, k, cnt[1 << K];
Node tree[2 << K];
void swapSegments(Node *v, int d) {
  if (d == 0) {
    std::swap(v->l, v->r);
    v->recalc();
  } else {
    swapSegments(v->l, d - 1);
    swapSegments(v->r, d - 1);
    v->recalc();
  }
}
int ans[1 << K], cur = 0;
void solve(int d) {
  if (d == k - 1) {
    ans[cur] = tree[1].ans;
  } else {
    solve(d + 1);
  }
  swapSegments(&tree[1], k - 1 - d);
  cur ^= 1 << d;
  if (d == k - 1) {
    ans[cur] = tree[1].ans;
  } else {
    solve(d + 1);
  }
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cin >> n >> k;
  for (int i = 0; i < n; i++) {
    int x;
    std::cin >> x;
    cnt[x]++;
  }
  for (int i = 0; i < (1 << k); i++) {
    tree[i | 1 << k] = Node(cnt[i]);
  }
  for (int i = (1 << k) - 1; i > 0; i--) {
    tree[i] = Node(&tree[2 * i], &tree[2 * i + 1]);
  }
  solve(0);
  for (int i = 0; i < (1 << k); i++) {
    std::cout << ans[i] << " \n"[i == (1 << k) - 1];
  }
  return 0;
}
