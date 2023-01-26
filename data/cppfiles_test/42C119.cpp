#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
struct node {
  int l, r, val, lazy;
  node *left, *right;
};
node *build(int l, int r) {
  if (l == r) return new node{l, r, 0, 0, nullptr, nullptr};
  node *left = build(l, (l + r) / 2), *right = build((l + r) / 2 + 1, r);
  return new node{l, r, 0, 0, left, right};
}
void propagate(node *cur) {
  if (cur->lazy == 0) return;
  cur->val += cur->lazy;
  if (cur->left != nullptr) {
    cur->left->lazy += cur->lazy;
    cur->right->lazy += cur->lazy;
  }
  cur->lazy = 0;
}
int query(node *cur, int l, int r) {
  propagate(cur);
  if (l > cur->r || r < cur->l) return INF;
  if (l <= cur->l && cur->r <= r) return cur->val;
  return min(query(cur->left, l, r), query(cur->right, l, r));
}
void update(node *cur, int l, int r, int val) {
  propagate(cur);
  if (l > cur->r || r < cur->l) return;
  if (l <= cur->l && cur->r <= r) {
    cur->lazy += val;
    propagate(cur);
    return;
  }
  update(cur->left, l, r, val);
  update(cur->right, l, r, val);
  cur->val = min(cur->left->val, cur->right->val);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int> > > a((int)1e6 + 1);
  for (int i = 0; i < n; i++) {
    int l, r, w;
    cin >> l >> r >> w;
    a[w].push_back({l, r - 1});
  }
  node *root = build(1, m);
  for (auto &p : a[1]) update(root, p.first, p.second, +1);
  int ans = INF;
  for (int l = 1, r = 1; l <= (int)1e6; l++) {
    if (r < l) r = l - 1;
    while (r < (int)1e6 && query(root, 1, m - 1) < 1) {
      r++;
      for (auto &p : a[r]) update(root, p.first, p.second, +1);
    }
    if (query(root, 1, m - 1) >= 1) ans = min(ans, r - l);
    for (auto &p : a[l]) update(root, p.first, p.second, -1);
  }
  cout << ans << '\n';
  return 0;
}
