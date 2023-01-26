#include <bits/stdc++.h>
using namespace std;
template <typename T>
class SegmentTree {
 private:
  static const int N = 20;
  int n;
  T maxv[2 << N];
  int ql, qr, qp;
  T qv;
  T q_max;
  void init(int o, int l, int r) {
    maxv[o] = 0;
    if (l == r) return;
    int lc = o << 1, rc = o << 1 | 1, mid = (l + r) >> 1;
    init(lc, l, mid);
    init(rc, mid + 1, r);
  }
  void up(int o, int l, int r) {
    int lc = o << 1, rc = o << 1 | 1, mid = (l + r) >> 1;
    maxv[o] = max(maxv[lc], maxv[rc]);
  }
  void update(int o, int l, int r) {
    if (l == r) {
      maxv[o] = max(maxv[o], qv);
      return;
    }
    int lc = o << 1, rc = o << 1 | 1, mid = (l + r) >> 1;
    if (qp <= mid)
      update(lc, l, mid);
    else
      update(rc, mid + 1, r);
    up(o, l, r);
  }
  void query(int o, int l, int r) {
    if (ql <= l && r <= qr) {
      q_max = max(q_max, maxv[o]);
      return;
    }
    int lc = o << 1, rc = o << 1 | 1, mid = (l + r) >> 1;
    if (ql <= mid) query(lc, l, mid);
    if (qr > mid) query(rc, mid + 1, r);
  }

 public:
  void Build(int n) {
    this->n = n;
    init(1, 0, n - 1);
  }
  void Update(int p, T v) {
    qp = p;
    qv = v;
    update(1, 0, n - 1);
  }
  T Max(int l, int r) {
    ql = l;
    qr = r;
    q_max = 0;
    query(1, 0, n - 1);
    return q_max;
  }
};
SegmentTree<int> tree;
int main() {
  cin.tie(0), cout.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> a(n + 1);
  vector<int> b;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    b.push_back(a[i] - i);
  }
  sort(b.begin(), b.end());
  b.erase(unique(b.begin(), b.end()), b.end());
  tree.Build(b.size());
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (i >= a[i]) {
      int idx = lower_bound(b.begin(), b.end(), a[i] - i) - b.begin();
      int prev_f = tree.Max(0, idx);
      tree.Update(idx, prev_f + 1);
      ans = max(ans, prev_f + 1);
    }
  }
  cout << ans << endl;
}
