#include <bits/stdc++.h>
using namespace std;
const int N = 6e5;
const int M = N + 7;
const double EPS = 1e-10;
const int MOD = 1e9 + 7;
const long long INF = 1e18 + 17;
int n, m, dp[M];
vector<pair<int, int> > g[M];
int t[4 * M], add[4 * M];
void push(int v, int tl, int tr) {
  int tm = (tl + tr) >> 1;
  if (add[v] != -1) {
    t[v + v] = add[v];
    add[v + v] = add[v];
    t[v + v + 1] = add[v];
    add[v + v + 1] = add[v];
    add[v] = -1;
  }
}
void upd(int v, int tl, int tr, int l, int r, int x) {
  if (l > r) return;
  if (tl == l && tr == r) {
    t[v] = x;
    add[v] = x;
    return;
  }
  push(v, tl, tr);
  int tm = (tl + tr) >> 1;
  upd(v + v, tl, tm, l, min(r, tm), x);
  upd(v + v + 1, tm + 1, tr, max(l, tm + 1), r, x);
  t[v] = max(t[v + v], t[v + v + 1]);
}
int get(int v, int tl, int tr, int l, int r) {
  if (l > r) return 0;
  if (tl == l && tr == r) return t[v];
  push(v, tl, tr);
  int tm = (tl + tr) >> 1;
  return max(get(v + v, tl, tm, l, min(tm, r)),
             get(v + v + 1, tm + 1, tr, max(tm + 1, l), r));
}
void solve() {
  cin >> n >> m;
  map<int, int> com;
  for (int i = 0; i < m; i++) {
    int id, l, r;
    cin >> id >> l >> r;
    com[l]++, com[r]++;
    g[id].push_back({l, r});
  }
  int val = 1;
  for (auto &it : com) it.second = val++;
  for (int i = 1; i <= n; i++)
    for (auto &it : g[i]) it.first = com[it.first], it.second = com[it.second];
  int nn = val - 1;
  dp[1] = 1;
  for (auto iv : g[1]) upd(1, 1, nn, iv.first, iv.second, 1);
  for (int i = 2; i <= n; i++) {
    dp[i] = 1;
    for (auto iv : g[i])
      dp[i] = max(dp[i], get(1, 1, nn, iv.first, iv.second) + 1);
    for (auto iv : g[i]) upd(1, 1, nn, iv.first, iv.second, dp[i]);
  }
  int ans = *max_element(dp + 1, dp + n + 1), last = -1;
  cout << n - ans << '\n';
  for (int i = n; i >= 1; i--) {
    bool ok = 0;
    if (last == -1)
      ok = 1;
    else {
      for (auto iv : g[i])
        for (auto lastv : g[last])
          if (max(iv.first, lastv.first) <= min(iv.second, lastv.second))
            ok = 1;
    }
    if (!ok || dp[i] != ans)
      cout << i << ' ';
    else
      last = i, ans--;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tt = 1;
  while (tt--) {
    solve();
    cout << '\n';
  }
  return 0;
}
