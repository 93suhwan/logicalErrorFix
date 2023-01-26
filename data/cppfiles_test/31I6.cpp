#include <bits/stdc++.h>
using namespace std;
const int N = (1 << 20);
const int T = (1 << 22);
const long long mod = 1000000007;
int TOT = 1;
int a[N];
int n, k;
vector<int> order;
void rec(int l, int r, int bit) {
  if (l == r) return;
  int m = (l + r) / 2;
  rec(l, m, bit + 1);
  order.push_back(bit);
  rec(m + 1, r, bit + 1);
}
struct node {
  int go[2];
  int best, mn, mx;
  node() {
    go[0] = go[1] = 0;
    best = 100000000;
    mn = 100000000;
    mx = -100000000;
  }
};
node t[T];
void add(int x) {
  int v = 1;
  for (int i = k - 1; i >= 0; i--) {
    t[v].mn = min(t[v].mn, x);
    t[v].mx = max(t[v].mx, x);
    int cur = (x >> i) % 2;
    if (!t[v].go[cur]) t[v].go[cur] = ++TOT;
    v = t[v].go[cur];
    x ^= (cur << i);
  }
  t[v].mn = min(t[v].mn, x);
  t[v].mx = max(t[v].mx, x);
}
void build(int v, int bt) {
  if (!v || bt == -1) return;
  build(t[v].go[0], bt - 1);
  build(t[v].go[1], bt - 1);
  t[v].best = min({t[t[v].go[0]].best, t[t[v].go[1]].best,
                   t[t[v].go[1]].mn + (1 << bt) - t[t[v].go[0]].mx});
}
void upd(int v, int bt, int need) {
  if (bt == need) {
    swap(t[v].go[0], t[v].go[1]);
  } else {
    upd(t[v].go[0], bt - 1, need);
    upd(t[v].go[1], bt - 1, need);
  }
  t[v].best = min({t[t[v].go[0]].best, t[t[v].go[1]].best,
                   t[t[v].go[1]].mn + (1 << bt) - t[t[v].go[0]].mx});
  t[v].mn = min(t[t[v].go[0]].mn, t[t[v].go[1]].mn + (1 << bt));
  t[v].mx = max(t[t[v].go[0]].mx, t[t[v].go[1]].mx + (1 << bt));
}
int ans[N];
void solve() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> a[i];
  rec(0, (1 << k) - 1, 0);
  for (int i = 1; i <= n; i++) {
    add(a[i]);
  }
  build(1, k - 1);
  ans[0] = t[1].best;
  int x = 0;
  for (int i : order) {
    x ^= (1 << i);
    upd(1, k - 1, i);
    ans[x] = t[1].best;
  }
  for (int i = 0; i < (1 << k); i++) cout << ans[i] << " ";
  cout << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tt = 1;
  while (tt--) {
    solve();
  }
  return 0;
}
