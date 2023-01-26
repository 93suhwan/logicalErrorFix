#include <bits/stdc++.h>
using namespace std;
const int Maxn = 1e6 + 10;
int cnt = 0;
bool f[Maxn];
struct segmentree {
  int Max[4 * Maxn];
  int lazy[4 * Maxn];
  int Id[4 * Maxn];
  segmentree() {
    memset(Max, 0, sizeof Max);
    memset(lazy, 0, sizeof lazy);
  }
  void Down(int x) {
    if (lazy[x] == 0) return;
    for (int j = 2 * x; j <= 2 * x + 1; j++)
      Max[j] = lazy[x], lazy[j] = lazy[x], Id[j] = Id[x];
    lazy[x] = 0;
  }
  void update(int l, int r, int x, int ql, int qr, int val, int id) {
    if (r < ql || l > qr) return;
    if (l >= ql && r <= qr) {
      Max[x] = val;
      lazy[x] = val;
      Id[x] = id;
      return;
    }
    int mid = l + r >> 1;
    Down(x);
    update(l, mid, x * 2, ql, qr, val, id);
    update(mid + 1, r, x * 2 + 1, ql, qr, val, id);
    Max[x] = max(Max[x * 2], Max[x * 2 + 1]);
    if (Max[x] == Max[2 * x])
      Id[x] = Id[2 * x];
    else
      Id[x] = Id[2 * x + 1];
  }
  pair<int, int> Get(int l, int r, int x, int ql, int qr) {
    if (l > qr || r < ql) return {0, 0};
    if (l >= ql && r <= qr) return {Max[x], Id[x]};
    Down(x);
    int mid = l + r >> 1;
    return max(Get(l, mid, x * 2, ql, qr), Get(mid + 1, r, x * 2 + 1, ql, qr));
  }
} Tree;
vector<pair<int, int> > a[Maxn];
int trace[Maxn];
int n, m;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  map<int, int> d;
  for (int i = 1; i <= m; i++) {
    int k, l, r;
    cin >> k >> l >> r;
    a[k].push_back({l, r});
    d[l] = d[r] = 1;
  }
  for (auto &x : d) {
    x.second = ++cnt;
  }
  pair<int, int> ans = {0, 0};
  for (int i = 1; i <= n; i++) {
    pair<int, int> Max = {0, 0};
    for (auto seg : a[i]) {
      int l = d[seg.first];
      int r = d[seg.second];
      pair<int, int> x = Tree.Get(1, cnt, 1, l, r);
      x.first++;
      Max = max(Max, x);
    }
    ans = max(ans, {Max.first, i});
    trace[i] = Max.second;
    for (auto seg : a[i]) {
      int l = d[seg.first];
      int r = d[seg.second];
      Tree.update(1, cnt, 1, l, r, Max.first, i);
    }
  }
  int s = ans.second;
  while (s) {
    f[s] = true;
    s = trace[s];
  }
  cout << n - ans.first << "\n";
  for (int i = 1; i <= n; i++) {
    if (!f[i]) cout << i << " ";
  }
  return 0;
}
