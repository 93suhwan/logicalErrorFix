#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > vec[2102100];
pair<int, int> tr[2102100];
int lz[2102100];
int id[2102100];
int l[2102100];
int r[2102200];
int b[2102100];
int path[2102100];
int st[2102100];
void build(int p, int l, int r) {
  tr[p] = {0, -1};
  lz[p] = 0;
  if (l == r) {
    return;
  }
  int mid = l + r >> 1;
  build(p << 1, l, mid);
  build(p << 1 | 1, mid + 1, r);
}
void pushup(int p) { tr[p] = max(tr[p << 1], tr[p << 1 | 1]); }
void pushdown(int p) {
  if (lz[p]) {
    lz[p << 1] = lz[p << 1 | 1] = lz[p];
    lz[p] = 0;
    tr[p << 1] = tr[p << 1 | 1] = tr[p];
  }
}
pair<int, int> query(int p, int l, int r, int ll, int rr) {
  if (ll <= l && rr >= r) {
    return tr[p];
  }
  pushdown(p);
  int mid = l + r >> 1;
  pair<int, int> res = {0, -1};
  if (ll <= mid) res = max(query(p << 1, l, mid, ll, rr), res);
  if (rr > mid) res = max(query(p << 1 | 1, mid + 1, r, ll, rr), res);
  return res;
}
void update(int p, int l, int r, int ll, int rr, pair<int, int> res) {
  if (ll <= l && rr >= r) {
    tr[p] = res;
    lz[p] = 1;
    return;
  }
  pushdown(p);
  int mid = l + r >> 1;
  if (ll <= mid) update(p << 1, l, mid, ll, rr, res);
  if (rr > mid) update(p << 1 | 1, mid + 1, r, ll, rr, res);
  pushup(p);
}
int main() {
  int n, t;
  cin >> n >> t;
  for (int i = 1; i <= t; i++) {
    cin >> id[i] >> l[i] >> r[i];
    b[i * 2 - 1] = l[i];
    b[i * 2] = r[i];
  }
  sort(b + 1, b + 1 + t * 2);
  int len = unique(b + 1, b + 1 + t * 2) - b - 1;
  build(1, 1, len);
  for (int i = 1; i <= t; i++) {
    l[i] = lower_bound(b + 1, b + 1 + len, l[i]) - b;
    r[i] = lower_bound(b + 1, b + 1 + len, r[i]) - b;
    vec[id[i]].push_back({l[i], r[i]});
  }
  for (int i = 1; i <= n; i++) {
    pair<int, int> mx = {0, -1};
    for (auto tt : vec[i]) {
      mx = max(mx, query(1, 1, len, tt.first, tt.second));
    }
    mx.first++;
    path[i] = mx.second;
    mx.second = i;
    for (auto tt : vec[i]) {
      update(1, 1, len, tt.first, tt.second, mx);
    }
  }
  pair<int, int> ans = query(1, 1, len, 1, len);
  int u = ans.second;
  int aa = n;
  while (u != -1) {
    st[u] = 1;
    aa--;
    u = path[u];
  }
  cout << aa << endl;
  for (int i = 1; i <= n; i++) {
    if (!st[i]) cout << i << " ";
  }
}
