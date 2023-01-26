#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 7;
const int BASE = 1 << 30;
const int INF = 1e9 + 7;
struct segment_tree {
  vector<pair<int, int>> values;
  vector<pair<int, int>> nxt;
  vector<pair<int, int>> add;
  int size;
  segment_tree() {
    size = -1;
    newVertex();
  }
  void newVertex() {
    ++size;
    values.push_back({0, -1});
    nxt.push_back({-1, -1});
    add.push_back({0, -1});
  }
  pair<int, int> best(pair<int, int> lhs, pair<int, int> rhs) {
    if (lhs.first < rhs.first) return lhs;
    return rhs;
  }
  void push(int v) {
    int l = nxt[v].first;
    int r = nxt[v].second;
    if (l == -1) {
      newVertex();
      nxt[v].first = l = size;
    }
    if (r == -1) {
      newVertex();
      nxt[v].second = r = size;
    }
    values[l] = best(values[l], add[v]);
    values[r] = best(values[r], add[v]);
    add[l] = best(add[l], add[v]);
    add[r] = best(add[r], add[v]);
    add[v] = {INF, -1};
  }
  pair<int, int> minn(int l, int r, int v = 0, int b = 0, int e = BASE - 1) {
    if (r < b || e < l) return {INF, -1};
    if (l <= b && e <= r) return values[v];
    push(v);
    int mid = (b + e) / 2;
    pair<int, int> lVal = minn(l, r, nxt[v].first, b, mid);
    pair<int, int> rVal = minn(l, r, nxt[v].second, mid + 1, e);
    values[v] = best(values[nxt[v].first], values[nxt[v].second]);
    return best(lVal, rVal);
  }
  void change(int l, int r, pair<int, int> val, int v = 0, int b = 0,
              int e = BASE - 1) {
    if (r < b || e < l) return;
    if (l <= b && e <= r) {
      add[v] = val;
      values[v] = val;
      return;
    }
    push(v);
    int mid = (b + e) / 2;
    change(l, r, val, nxt[v].first, b, mid);
    change(l, r, val, nxt[v].second, mid + 1, e);
    values[v] = best(values[nxt[v].first], values[nxt[v].second]);
  }
};
vector<pair<int, int>> segments[MAXN];
int dp[MAXN];
int prv[MAXN];
bool ok[MAXN];
void solve() {
  segment_tree tree;
  int n, m;
  cin >> n >> m;
  map<int, int> scaled;
  vector<int> sorted;
  for (int i = 1; i <= m; ++i) {
    int h, l, r;
    cin >> h >> l >> r;
    segments[h].push_back({l, r});
    sorted.push_back(l);
    sorted.push_back(r);
  }
  sort(sorted.begin(), sorted.end());
  int last = -1;
  int cnt = 0;
  for (int i = 0; i < sorted.size(); ++i) {
    if (sorted[i] != last) {
      scaled[sorted[i]] = ++cnt;
      last = sorted[i];
    }
  }
  for (int h = 1; h <= n; ++h) {
    for (auto& [l, r] : segments[h]) {
      l = scaled[l];
      r = scaled[r];
    }
  }
  for (int h = 1; h <= n; ++h) {
    dp[h] = INF;
    for (auto [l, r] : segments[h]) {
      auto [val, ind] = tree.minn(l, r);
      if (val + h - 1 < dp[h]) {
        dp[h] = val + h - 1;
        prv[h] = ind;
      }
    }
    for (auto [l, r] : segments[h]) {
      tree.change(l, r, {dp[h] - h, h});
    }
  }
  auto [ans, ind] = tree.minn(0, BASE - 1);
  cout << ans + n << '\n';
  while (ind != 0) {
    ok[ind] = true;
    ind = prv[ind];
  }
  for (int i = 1; i <= n; ++i) {
    if (!ok[i]) cout << i << ' ';
  }
  cout << '\n';
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int T;
  T = 1;
  while (T--) solve();
  return 0;
}
