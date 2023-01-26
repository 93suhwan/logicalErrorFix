#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 7;
const int BASE = 1 << 30;
int cnt = -1;
vector<pair<int, int>> segments[MAXN];
vector<int> segTree;
vector<pair<int, int>> nxt;
vector<int> add;
int dp[MAXN];
int prv[MAXN];
bool ok[MAXN];
void newVertex() {
  ++cnt;
  segTree.push_back(0);
  nxt.push_back({-1, -1});
  add.push_back(0);
}
void push(int v) {
  int l = nxt[v].first;
  int r = nxt[v].second;
  if (l == -1) {
    newVertex();
    nxt[v].first = l = cnt;
  }
  if (r == -1) {
    newVertex();
    nxt[v].second = r = cnt;
  }
  if (add[v] == 0) return;
  segTree[l] = add[v];
  segTree[r] = add[v];
  add[l] = add[v];
  add[r] = add[v];
  add[v] = 0;
}
int maxx(int l, int r, int v = 0, int b = 0, int e = BASE - 1) {
  if (r < b || e < l) return 0;
  if (l <= b && e <= r) return segTree[v];
  push(v);
  int mid = (b + e) / 2;
  int lVal = maxx(l, r, nxt[v].first, b, mid);
  int rVal = maxx(l, r, nxt[v].second, mid + 1, e);
  segTree[v] = max(segTree[nxt[v].first], segTree[nxt[v].second]);
  return max(lVal, rVal);
}
void change(int l, int r, int val, int v = 0, int b = 0, int e = BASE - 1) {
  if (r < b || e < l) return;
  if (l <= b && e <= r) {
    add[v] = val;
    segTree[v] = val;
    return;
  }
  push(v);
  int mid = (b + e) / 2;
  change(l, r, val, nxt[v].first, b, mid);
  change(l, r, val, nxt[v].second, mid + 1, e);
  segTree[v] = max(segTree[nxt[v].first], segTree[nxt[v].second]);
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int T;
  T = 1;
  while (T--) {
    newVertex();
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
      int h, l, r;
      cin >> h >> l >> r;
      segments[h].push_back({l, r});
    }
    for (int h = 1; h <= n; ++h) {
      int best = 0;
      for (auto [l, r] : segments[h]) best = max(maxx(l, r), best);
      dp[h] = dp[best] + (h - best - 1);
      prv[h] = best;
      for (auto [l, r] : segments[h]) change(l, r, h);
    }
    dp[n + 1] = 1e9 + 7;
    int last = n + 1;
    for (int h = n; h >= 1; --h) {
      if ((dp[last] + (n - last)) > (dp[h] + (n - h))) last = h;
    }
    cout << dp[last] + (n - last) << '\n';
    while (last != 0) {
      ok[last] = true;
      last = prv[last];
    }
    for (int i = 1; i <= n; ++i) {
      if (!ok[i]) cout << i << ' ';
    }
    cout << '\n';
  }
  return 0;
}
