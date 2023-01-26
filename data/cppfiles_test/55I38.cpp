#include <bits/stdc++.h>
using namespace std;
struct Node {
  int val;
  Node *l, *r;
  int lazy;
  int idx;
  Node() {
    l = r = nullptr;
    lazy = val = 1e9 + 1;
  }
};
const int NMAX = 200001;
vector<vector<pair<int, int> > > seg(NMAX);
void push(Node *&v) {
  if (v->lazy == 1e9 + 1) return;
  if (v->l == nullptr) v->l = new Node();
  if (v->r == nullptr) v->r = new Node();
  if (v->lazy < v->l->val)
    v->l->val = v->lazy, v->l->lazy = v->lazy, v->l->idx = v->idx;
  if (v->lazy < v->r->val)
    v->r->val = v->lazy, v->r->lazy = v->lazy, v->r->idx = v->idx;
  v->lazy = 1e9 + 1;
}
pair<int, int> get(Node *&v, int l, int r, int st, int fin) {
  if (v == nullptr) return {1e9 + 1, 1e9 + 1};
  if (st > r || fin < l) return {1e9 + 1, 1e9 + 1};
  if (l >= st && r <= fin) {
    return {v->val, v->idx};
  }
  push(v);
  int m = (l + r) / 2;
  pair<int, int> x = get(v->l, l, m, st, fin);
  pair<int, int> y = get(v->r, m + 1, r, st, fin);
  return min(x, y);
}
void update(Node *&v, int l, int r, int st, int fin, int nw, int idx) {
  if (v == nullptr) v = new Node();
  if (st > r || fin < l) return;
  if (l >= st && r <= fin) {
    if (v->val > nw) {
      v->lazy = nw;
      v->val = nw;
      v->idx = idx;
    }
    return;
  }
  push(v);
  int m = (l + r) / 2;
  update(v->l, l, m, st, fin, nw, idx);
  update(v->r, m + 1, r, st, fin, nw, idx);
  if (v->l->val < v->r->val)
    v->val = v->l->val, v->idx = v->l->idx;
  else
    v->val = v->r->val, v->idx = v->r->idx;
}
void solve() {
  int n;
  cin >> n;
  int m;
  cin >> m;
  for (int i = 1; i <= m; i++) {
    int pos;
    int l, r;
    cin >> pos >> l >> r;
    seg[pos].push_back({l, r});
  }
  Node *root = new Node();
  int dp[n + 1];
  int par[n + 1];
  update(root, 0, 1e9, 0, 1e9, n, 0);
  for (int i = 1; i <= n; i++) {
    pair<int, int> ans = {1e9 + 1, 1e9 + 1};
    for (int j = 0; j < seg[i].size(); j++) {
      pair<int, int> x = get(root, 0, 1e9, seg[i][j].first, seg[i][j].second);
      ans = min(ans, x);
    }
    dp[i] = ans.first + ans.second - n;
    dp[i] += i - ans.second - 1;
    par[i] = ans.second;
    for (int j = 0; j < seg[i].size(); j++) {
      update(root, 0, 1e9, seg[i][j].first, seg[i][j].second, dp[i] + n - i, i);
    }
  }
  int mn = 1e9 + 1;
  int mni;
  for (int i = 1; i <= n; i++) {
    if (dp[i] + n - i < mn) {
      mn = dp[i] + n - i;
      mni = i;
    }
  }
  set<int> ans;
  for (int i = 1; i <= n; i++) {
    ans.insert(i);
  }
  cout << mn << "\n";
  while (mni) {
    ans.erase(mni);
    mni = par[mni];
  }
  for (int to : ans) {
    cout << to << ' ';
  }
}
int main() {
  int test = 1;
  while (test--) {
    solve();
  }
}
