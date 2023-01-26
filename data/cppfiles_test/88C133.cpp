#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long inf = 1e9;
const long long N = 3e5 + 9;
struct segtree {
  long long size;
  vector<long long> tree;
  void init(long long n) {
    size = 1;
    while (size < n) size *= 2;
    tree.assign(2 * size, 0LL);
  }
  long long merge(long long u, long long v) { return u + v; }
  void update(long long x, long long lx, long long rx, long long i,
              long long v) {
    if (lx == rx) {
      tree[x] = v;
      return;
    }
    long long mid = (lx + rx) / 2;
    if (i <= mid)
      update(2 * x, lx, mid, i, v);
    else
      update(2 * x + 1, mid + 1, rx, i, v);
    tree[x] = merge(tree[2 * x], tree[2 * x + 1]);
  }
  long long query(long long l, long long r, long long x, long long lx,
                  long long rx) {
    if (lx > r || rx < l) return 0LL;
    if (lx >= l && rx <= r) return tree[x];
    long long mid = (lx + rx) / 2;
    long long s1 = query(l, r, 2 * x, lx, mid);
    long long s2 = query(l, r, 2 * x + 1, mid + 1, rx);
    return merge(s1, s2);
  }
};
void solve() {
  long long n, m;
  cin >> n >> m;
  map<long long, vector<long long>> mp;
  for (long long i = 1; i <= n * m; i++) {
    long long x;
    cin >> x;
    mp[x].push_back(i);
  }
  long long ans = 0;
  vector<long long> row;
  for (auto c : mp) {
    vector<long long> v = c.second;
    sort(v.rbegin(), v.rend());
    while (!v.empty()) {
      vector<long long> cur;
      while (!v.empty()) {
        cur.push_back(v.back());
        v.pop_back();
        if (cur.size() + row.size() == m) {
          break;
        }
      }
      reverse(cur.begin(), cur.end());
      for (auto x : cur) row.push_back(x);
      if (row.size() == m) {
        segtree st;
        st.init(n * m);
        for (long long i = 0; i < m; i++) {
          ans += st.query(1, row[i], 1, 1, n * m);
          st.update(1, 1, n * m, row[i], 1);
        }
        row.clear();
      }
    }
  }
  cout << ans << "\n";
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
