#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
const double EPS = 1e-7;
const double PI = acos(-1);
struct segtree {
  int size;
  vector<int> st;
  int join(int a, int b) { return a + b; }
  segtree(int n) : size(n), st(4 * n + 10) {}
  segtree(vector<int>& v) : segtree(v.size()) { build(v, 1, 0, size - 1); }
  void build(vector<int>& v, int id, int l, int r) {
    if (l == r)
      st[id] = v[l];
    else {
      int mid = (l + r) >> 1;
      build(v, id << 1, l, mid);
      build(v, id << 1 | 1, mid + 1, r);
      st[id] = join(st[id << 1], st[id << 1 | 1]);
    }
  }
  void update(int id, int l, int r, int pos, int val) {
    if (l == r)
      st[id] = val;
    else {
      int mid = (l + r) >> 1;
      if (pos <= mid)
        update(id << 1, l, mid, pos, val);
      else
        update(id << 1 | 1, mid + 1, r, pos, val);
      st[id] = join(st[id << 1], st[id << 1 | 1]);
    }
  }
  int query(int id, int l, int r, int a, int b) {
    if (l > b or r < a) return 0;
    if (a <= l and r <= b) return st[id];
    int mid = (l + r) >> 1;
    return join(query(id << 1, l, mid, a, b),
                query(id << 1 | 1, mid + 1, r, a, b));
  }
  void update(int pos, int val) { update(1, 0, size - 1, pos, val); }
  int query(int l, int r) { return query(1, 0, size - 1, l, r); }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int> > a(n * m);
    for (int i = 0; i < n * m; i++) {
      cin >> a[i].first;
      a[i].second = i;
    }
    sort(a.begin(), a.end());
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      segtree st(n * m);
      sort(a.begin() + i * m, a.begin() + (i + 1) * m,
           [](pair<int, int> a, pair<int, int> b) {
             return a.first == b.first ? a.second > b.second
                                       : a.first < b.first;
           });
      for (int j = 0; j < m; j++) {
        auto& [v, p] = a[i * m + j];
        ans += st.query(0, p - 1);
        st.update(p, 1);
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
