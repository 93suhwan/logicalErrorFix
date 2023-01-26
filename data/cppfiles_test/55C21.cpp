#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(time(0));
struct Node {
  int val, pos;
  bool operator<(const Node& ot) const { return val < ot.val; }
};
struct lazy_segment_tree {
  static const int N = 1e6 + 10;
  const Node good_value = {0, 0};
  Node t[4 * N], ch[4 * N];
  Node merge(Node a, Node b) { return max(a, b); }
  void build(int v = 1, int tl = 1, int tr = N - 1) {
    if (tl == tr) {
      t[v] = {0, 0};
      return;
    }
    int tm = (tl + tr) / 2;
    build(v + v, tl, tm);
    build(v + v + 1, tm + 1, tr);
    t[v] = merge(t[v + v], t[v + v + 1]);
  }
  void push(int v, int tl, int tr) {
    if (!ch[v].val) return;
    t[v] = ch[v];
    if (tl < tr) {
      ch[v + v] = ch[v];
      ch[v + v + 1] = ch[v];
    }
    ch[v] = {0, 0};
  }
  void update(int l, int r, Node x, int v = 1, int tl = 1, int tr = N - 1) {
    push(v, tl, tr);
    if (r < tl || tr < l) return;
    if (l <= tl && tr <= r) {
      ch[v] = x;
      push(v, tl, tr);
      return;
    }
    int tm = (tl + tr) / 2;
    update(l, r, x, v + v, tl, tm);
    update(l, r, x, v + v + 1, tm + 1, tr);
    t[v] = merge(t[v + v], t[v + v + 1]);
  }
  Node get(int l, int r, int v = 1, int tl = 1, int tr = N - 1) {
    push(v, tl, tr);
    if (r < tl || tr < l) return good_value;
    if (l <= tl && tr <= r) return t[v];
    int tm = (tl + tr) / 2;
    Node res =
        merge(get(l, r, v + v, tl, tm), get(l, r, v + v + 1, tm + 1, tr));
    t[v] = merge(t[v + v], t[v + v + 1]);
    return res;
  }
} tree;
const int N = 3e5 + 10;
vector<pair<int, int> > a[N];
vector<int> all;
map<int, int> mp;
int mem[N];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int id, l, r;
    cin >> id >> l >> r;
    a[id].push_back({l, r});
    all.push_back(l);
    all.push_back(r);
  }
  sort(all.begin(), all.end());
  all.erase(unique(all.begin(), all.end()), all.end());
  for (int i = 0; i < all.size(); i++) {
    mp[all[i]] = i + 1;
  }
  tree.build();
  for (int i = 1; i <= n; i++) {
    int cur = 0;
    for (auto& [l, r] : a[i]) {
      l = mp[l];
      r = mp[r];
      Node tmp = tree.get(l, r);
      tmp.val++;
      if (cur < tmp.val) {
        cur = tmp.val;
        mem[i] = tmp.pos;
      }
    }
    for (int j = 0; j < a[i].size(); j++) {
      tree.update(a[i][j].first, a[i][j].second, {cur, i});
    }
  }
  Node res = tree.get(1, tree.N - 1);
  cout << n - res.val << "\n";
  vector<int> ans;
  int ptr = res.pos;
  for (int i = n; i >= ptr + 1; i--) {
    ans.push_back(i);
  }
  while (ptr != mem[ptr]) {
    for (int i = ptr - 1; i >= mem[ptr] + 1; i--) {
      ans.push_back(i);
    }
    ptr = mem[ptr];
  }
  reverse(ans.begin(), ans.end());
  for (int i : ans) {
    cout << i << " ";
  }
  cout << "\n";
  return 0;
}
