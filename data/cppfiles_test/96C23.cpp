#include <bits/stdc++.h>
using namespace std;
struct node {
  long long first, last, pref, suff, size, ans;
  node(int v) : first(v), last(v), pref(1), suff(1), size(1), ans(1) {}
  node() : ans(0) {}
};
vector<node> tree;
int n;
node operator+(node l, node r) {
  if (l.ans == 0) return r;
  if (r.ans == 0) return l;
  node res;
  res.first = l.first;
  res.last = r.last;
  res.pref = (l.last <= r.first && l.pref == l.size ? l.size + r.pref : l.pref);
  res.suff = (l.last <= r.first && r.suff == r.size ? r.size + l.suff : r.suff);
  res.size = l.size + r.size;
  res.ans = l.ans + r.ans + (l.last <= r.first ? l.suff * r.pref : 0);
  return res;
}
void init(const vector<int>& a, int xi = 0, int xl = 0, int xr = n) {
  if (xr - xl == 1) {
    tree[xi] = a[xl];
    return;
  }
  init(a, (xi * 2 + 1), xl, ((xl + xr) / 2));
  init(a, (xi * 2 + 2), ((xl + xr) / 2), xr);
  tree[xi] = tree[(xi * 2 + 1)] + tree[(xi * 2 + 2)];
}
void set(int i, int v, int xi = 0, int xl = 0, int xr = n) {
  if (xr - xl == 1) {
    tree[xi] = node(v);
    return;
  }
  if (i < ((xl + xr) / 2)) {
    set(i, v, (xi * 2 + 1), xl, ((xl + xr) / 2));
  } else {
    set(i, v, (xi * 2 + 2), ((xl + xr) / 2), xr);
  }
  tree[xi] = tree[(xi * 2 + 1)] + tree[(xi * 2 + 2)];
}
node get(int l, int r, int xi = 0, int xl = 0, int xr = n) {
  if (r <= xl || xr <= l) {
    return node();
  }
  if (l <= xl && xr <= r) {
    return tree[xi];
  }
  return get(l, r, (xi * 2 + 1), xl, ((xl + xr) / 2)) +
         get(l, r, (xi * 2 + 2), ((xl + xr) / 2), xr);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int q;
  cin >> n >> q;
  vector<int> a(n);
  for (auto& e : a) {
    cin >> e;
  }
  tree.resize(4 * n);
  init(a);
  while (q--) {
    int t, a, b;
    cin >> t >> a >> b;
    if (t == 1) {
      set(a - 1, b);
    } else {
      cout << get(a - 1, b).ans << "\n";
    }
  }
}
