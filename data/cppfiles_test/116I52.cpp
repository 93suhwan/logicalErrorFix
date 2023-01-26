#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5, mod = 998244353;
int t, vis[N], p[2 * N], n, m, K, cnt[N], dp[N], l, r, F, first[N];
set<int> second[N];
vector<int> a[N], V[N];
void dfs(int u, int id) {
  if (vis[u]) return;
  vis[u] = 1;
  while (second[u].size()) {
    int x = *second[u].begin();
    for (int i = 0; i < a[x].size(); i++) second[a[x][i]].erase(x);
    int first = 0;
    for (int j = 0; j < a[x].size(); j++) {
      if (a[x][j] == u) first = j;
    }
    for (int j = 0; j < a[x].size(); j++) {
      int d = a[x][j];
      l = min(l, id + j - first);
      r = max(r, id + j - first);
      if (l <= 0) {
        F = 1;
        return;
      }
      if (!p[id + j - first])
        p[id + j - first] = d;
      else if (p[id + j - first] != d) {
        F = 1;
        return;
      }
      if (!vis[d]) {
        dfs(d, id + j - first);
      }
    }
  }
}
int main() {
  cin >> n >> m >> K;
  for (int i = 1; i <= n; i++) {
    int c;
    cin >> c;
    while (c--) {
      int x;
      cin >> x;
      a[i].push_back(x);
    }
    sort(a[i].begin(), a[i].end());
    int F = 0;
    for (int j = 1; j < a[i].size(); j++) {
      if (a[i][j] == a[i][j - 1]) F = 1;
    }
    if (F) {
      for (int j = 0; j < a[i].size(); j++) first[a[i][j]] = 1;
    }
  }
  for (int i = 1; i <= n; i++) {
    int F = 0;
    for (int j = 0; j < a[i].size(); j++) {
      if (first[a[i][j]]) F = 1;
    }
    if (F) continue;
    for (int j = 0; j < a[i].size(); j++) {
      second[a[i][j]].insert(i);
    }
  }
  for (int i = 1; i <= K; i++) {
    if (!vis[i] && !first[i]) {
      l = r = m + 1;
      dfs(i, m + 1);
      if (r - l + 1 > m || F) continue;
      int F = 0;
      for (int j = l; j <= r; j++) {
        if (cnt[p[j]]) F = 1;
        cnt[p[j]]++;
      }
      for (int j = l; j <= r; j++) cnt[p[j]] = 0, p[j] = 0;
      if (!F) cnt[r - l + 1]++;
    }
  }
  dp[0] = 1;
  vector<pair<int, int> > x;
  for (int j = 1; j <= m; j++) {
    if (cnt[j]) x.push_back({j, cnt[j]});
  }
  for (int i = 1; i <= m; i++) {
    for (int j = 0; j < x.size(); j++)
      if (i - x[j].first >= 0)
        dp[i] =
            (dp[i] + (long long)dp[i - x[j].first] * x[j].second % mod) % mod;
  }
  cout << endl;
  cout << dp[m];
}
