#include <bits/stdc++.h>
using namespace std;
const int N = 1 << 19;
const int INF = 1e9;
struct node {
  int mn, pmn;
  bool operator<(const node& a) const { return mn < a.mn; }
} tree[N << 1];
int n, arr[N], brr[N], dp[N], to[N];
vector<int> stuff[N];
void build(int v = 1, int tl = 0, int tr = N - 1) {
  if (tl == tr) return void(tree[v] = {INF, tl});
  int tm = (tl + tr) >> 1;
  build(v << 1, tl, tm);
  build(v << 1 | 1, tm + 1, tr);
  tree[v] = min(tree[v << 1], tree[v << 1 | 1]);
}
void upd(int pos, int val, int v = 1, int tl = 0, int tr = N - 1) {
  if (tr < pos || tl > pos) return;
  if (tl == tr) return void(tree[v] = {val, tl});
  int tm = (tl + tr) >> 1;
  upd(pos, val, v << 1, tl, tm);
  upd(pos, val, v << 1 | 1, tm + 1, tr);
  tree[v] = min(tree[v << 1], tree[v << 1 | 1]);
}
node query(int l, int r, int v = 1, int tl = 0, int tr = N - 1) {
  if (tr < l || tl > r) return {INF, -1};
  if (l <= tl && tr <= r) return tree[v];
  int tm = (tl + tr) >> 1;
  return min(query(l, r, v << 1, tl, tm), query(l, r, v << 1 | 1, tm + 1, tr));
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> arr[i];
  for (int i = 1; i <= n; ++i) cin >> brr[i], stuff[i + brr[i]].push_back(i);
  build();
  fill(dp, dp + N, INF);
  dp[0] = 0;
  upd(0, 0);
  for (int i = 1; i <= n; ++i) {
    node res = query(i - arr[i], i - 1);
    if (res.mn == INF) continue;
    dp[i] = 1 + res.mn, to[i] = res.pmn;
    for (auto x : stuff[i]) upd(x, dp[i]);
  }
  if (dp[n] == INF) {
    cout << -1 << '\n';
    exit(0);
  }
  cout << dp[n] << '\n';
  int cur = to[n];
  while (cur) {
    cout << cur << ' ';
    cur = to[cur - brr[cur]];
  }
  cout << 0 << '\n';
}
