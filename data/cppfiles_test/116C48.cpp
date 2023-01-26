#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5, mod = 998244353;
int t, vis[N], p[2 * N], n, m, K, cnt[N], dp[N], l, r, F, first[N], c[N];
set<int> second[N];
vector<int> a[N], V[N];
void dfs(int u, int id) {
  if (vis[u]) return;
  vis[u] = 1;
  while (second[u].size()) {
    int x = *second[u].begin();
    for (int i = 0; i < a[x].size(); i++) second[a[x][i]].erase(x);
    int first = -1;
    for (int j = 0; j < a[x].size(); j++) {
      if (a[x][j] == u) first = j;
    }
    assert(first != -1);
    for (int j = (int)a[x].size() - 1; j >= 0; j--) {
      int d = a[x][j];
      l = min(l, id + j - first);
      r = max(r, id + j - first);
      if (l <= 0) {
        F = 1;
      } else {
        if (!p[id + j - first])
          p[id + j - first] = d;
        else if (p[id + j - first] != d) {
          F = 1;
        }
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
  }
  for (int i = 1; i <= n; i++) {
    int F = 0;
    for (int j = 0; j < a[i].size(); j++) {
      second[a[i][j]].insert(i);
    }
  }
  for (int i = 1; i <= K; i++) {
    if (!vis[i] && !first[i]) {
      l = r = m + 1;
      F = 0;
      p[m + 1] = i;
      dfs(i, m + 1);
      for (int j = max(0, l); j <= r; j++) {
        if (c[p[j]] && p[j]) F = 1;
        c[p[j]]++;
      }
      for (int j = max(0, l); j <= r; j++) c[p[j]] = 0, p[j] = 0;
      if (!(r - l + 1 > m || F)) cnt[r - l + 1]++;
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
