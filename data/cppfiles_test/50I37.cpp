#include <bits/stdc++.h>
using namespace std;
const int dr[]{-1, -1, 0, 1, 1, 1, 0, -1};
const int dc[]{0, 1, 1, 1, 0, -1, -1, -1};
void run() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
const int MOD = 998244353;
int add(int a, int b) {
  if ((a += b) >= MOD)
    a -= MOD;
  else if (a < 0)
    a += MOD;
  return a;
}
int mul(int a, int b) { return (1LL * a * b) % MOD; }
struct segtree {
  segtree *left = nullptr, *right = nullptr;
  int sum = 0, lazy = 0;
  char sign = 1;
  segtree() {}
  void extend() {
    if (left == nullptr) {
      left = new segtree();
      right = new segtree();
    }
  }
  void pushdown(int start, int end) {
    if (lazy == 0 && sign == 1) return;
    sum = add(mul(end - start + 1, lazy), sign * sum);
    if (start != end) {
      extend();
      left->sign *= sign;
      left->lazy = add(lazy, -left->lazy);
      right->sign *= sign;
      right->lazy = add(lazy, -right->lazy);
    }
    lazy = 0;
    sign = 1;
  }
  void pushup() { sum = add(left->sum, right->sum); }
  ~segtree() {
    if (left == nullptr) return;
    delete left;
    delete right;
  }
};
class extened_segment_tree {
  void update(segtree *root, int start, int end, int l, int r, int val) {
    root->pushdown(start, end);
    if (r < start || end < l) return;
    if (l <= start && end <= r) {
      root->sign *= -1;
      root->lazy = val;
      root->pushdown(start, end);
      return;
    }
    root->extend();
    update(root->left, start, ((start + end) >> 1), l, r, val);
    update(root->right, ((start + end) >> 1) + 1, end, l, r, val);
    root->pushup();
  }
  void clear(segtree *&root, int start, int end, int l, int r) {
    root->pushdown(start, end);
    if (r < start || end < l) return;
    if (l <= start && end <= r) {
      delete root;
      root = new segtree();
      return;
    }
    root->extend();
    clear(root->left, start, ((start + end) >> 1), l, r);
    clear(root->right, ((start + end) >> 1) + 1, end, l, r);
    root->pushup();
  }

 public:
  int start, end;
  segtree *root;
  extened_segment_tree() {}
  extened_segment_tree(int start, int end) : start(start), end(end) {
    root = new segtree();
  }
  void clear(int l, int r) { clear(root, start, end, l, r); }
  void update(int l, int r, int val) { update(root, start, end, l, r, val); }
  int query() { return root->sum; }
};
const int N = 1e9;
int main() {
  run();
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &it : a) cin >> it;
  extened_segment_tree seg(1, N);
  seg.update(1, a[0], 1);
  for (int i = 1; i < n; i++) {
    int sum = seg.query();
    seg.update(1, a[i], sum);
    seg.clear(a[i] + 1, N);
  }
  cout << seg.query() << "\n";
}
