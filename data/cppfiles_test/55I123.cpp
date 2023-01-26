#include <bits/stdc++.h>
using namespace std;
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << ' ' << H;
  debug_out(T...);
}
const int N = 1e6 + 5;
vector<pair<int, int>> v[N];
int vis[N], mx[N * 4], las[N], id[N * 4], dp[N], b[N], tot;
void update(int l, int r, int rt, int a, int b, int c, int i) {
  if (l >= a && r <= b) {
    if (mx[rt] < c) {
      mx[rt] = c;
      id[rt] = i;
    }
    return;
  }
  int m = l + r >> 1;
  if (a <= m) update(l, m, rt << 1, a, b, c, i);
  if (b > m) update(m + 1, r, rt << 1 | 1, a, b, c, i);
}
pair<int, int> query(int l, int r, int rt, int a, int b) {
  if (l >= a && r <= b) return {mx[rt], id[rt]};
  int m = l + r >> 1;
  pair<int, int> ans = {mx[rt], id[rt]};
  if (a <= m) ans = max(ans, query(l, m, rt << 1, a, b));
  if (b > m) ans = max(ans, query(m + 1, r, rt << 1 | 1, a, b));
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 1, j, l, r; i <= m; i++) {
    cin >> j >> l >> r;
    v[j].emplace_back(l, r);
    b[++tot] = l, b[++tot] = r;
  }
  sort(b + 1, b + tot + 1);
  tot = unique(b + 1, b + tot + 1) - b - 1;
  int mx = 0, p = 0;
  for (int i = 1; i <= n; i++) {
    pair<int, int> tmp = {0, 0};
    for (auto& e : v[i]) {
      int l = lower_bound(b + 1, b + tot + 1, e.first) - b;
      int r = lower_bound(b + 1, b + tot + 1, e.second) - b;
      auto pi = query(1, tot, 1, l, r);
      tmp = max(tmp, pi);
    }
    dp[i] = tmp.first + 1, las[i] = tmp.second;
    for (auto& e : v[i]) {
      int l = lower_bound(b + 1, b + tot + 1, e.first) - b;
      int r = lower_bound(b + 1, b + tot + 1, e.second) - b;
      update(1, tot, 1, l, r, dp[i], i);
    }
    if (mx < dp[i]) {
      mx = dp[i];
      p = i;
    }
  }
  while (p) {
    vis[p] = 1;
    p = las[p];
  }
  vector<int> ans;
  for (int i = 1; i <= n; i++)
    if (!vis[i]) ans.push_back(i);
  cout << (int)ans.size() << '\n';
  for (int& x : ans) cout << x << ' ';
  return 0;
}
