#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
struct seg_tree {
  int max1[maxn << 2], lazy[maxn << 2];
  int ls(int x) { return x << 1; }
  int rs(int x) { return x << 1 | 1; }
  void push_up(int p) { max1[p] = max(max1[ls(p)], max1[rs(p)]); }
  void f(int id, int l, int r, int k) {
    lazy[id] += k;
    max1[id] += k;
  }
  void push_down(int id, int l, int r) {
    int mid = (l + r) >> 1;
    f(ls(id), l, mid, lazy[id]);
    f(rs(id), mid + 1, r, lazy[id]);
    lazy[id] = 0;
  }
  void add(int id, int l, int r, int x, int y, int k) {
    if (x > y || x > r || y < l) return;
    if (x <= l && r <= y) {
      max1[id] += k;
      lazy[id] += k;
      return;
    }
    push_down(id, l, r);
    int mid = (l + r) >> 1;
    if (x <= mid) add(ls(id), l, mid, x, y, k);
    if (y > mid) add(rs(id), mid + 1, r, x, y, k);
    push_up(id);
  }
  int query(int id, int l, int r, int x, int y) {
    if (x > y || x > r || y < l) return 0;
    int ans = 0;
    if (x <= l && r <= y) return max1[id];
    int mid = (l + r) >> 1;
    push_down(id, l, r);
    if (x <= mid) ans = max(ans, query(ls(id), l, mid, x, y));
    if (y > mid) ans = max(ans, query(rs(id), mid + 1, r, x, y));
    return ans;
  }
} seg;
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  int n, d;
  cin >> n >> d;
  vector<pair<int, int>> v(n);
  for (int i = 0; i < n; i++) cin >> v[i].second >> v[i].first;
  vector<int> t = {d};
  for (int i = 0; i < n; i++) {
    t.push_back(v[i].first);
    t.push_back(v[i].second);
  }
  sort(t.begin(), t.end());
  t.erase(unique(t.begin(), t.end()), t.end());
  int mx = 0;
  for (int i = 0; i < n; i++) {
    v[i].first = lower_bound(t.begin(), t.end(), v[i].first) - t.begin();
    v[i].second = lower_bound(t.begin(), t.end(), v[i].second) - t.begin();
    mx = max(mx, v[i].first);
    mx = max(mx, v[i].second);
  }
  d = lower_bound(t.begin(), t.end(), d) - t.begin();
  mx = max(mx, d);
  sort(v.begin(), v.end(), [&](pair<int, int> v1, pair<int, int> v2) {
    int mx1 = v1.first + v1.second;
    int mx2 = v2.first + v2.second;
    if (mx1 != mx2)
      return mx1 < mx2;
    else
      return v1.second < v2.second;
  });
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (v[i].second < d)
      continue;
    else if (v[i].first <= d)
      ans++;
    else {
      if (v[i].second <= v[i].first) {
        int now = seg.query(1, 0, mx, v[i].first, v[i].first);
        int val = seg.query(1, 0, mx, 0, v[i].second) + 1;
        if (now < val) seg.add(1, 0, mx, v[i].first, v[i].first, val - now);
      } else {
        int now = seg.query(1, 0, mx, v[i].first, v[i].first);
        int val = seg.query(1, 0, mx, 0, v[i].second) + 1;
        if (now < val) seg.add(1, 0, mx, v[i].first, v[i].first, val - now);
        seg.add(1, 0, mx, v[i].first + 1, v[i].second, 1);
      }
    }
  }
  cout << ans + seg.max1[1] << '\n';
  return 0;
}
