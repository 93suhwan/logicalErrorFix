#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 200005, S = 440;
int n;
vector<int> g[N];
int d[N];
int u[N];
int t[N];
bool sot(int x, int y) { return t[x] > t[y]; }
void dfs00(int x, int p) {
  if (x == p)
    d[x] = 0;
  else
    d[x] = d[p] + 1;
  for (int i = 0; i < g[x].size(); ++i) {
    int h = g[x][i];
    if (h == p) continue;
    dfs00(h, x);
  }
  for (int i = 0; i < g[x].size(); ++i) {
    int h = g[x][i];
    if (h == p) {
      swap(g[x][i], g[x].back());
      g[x].pop_back();
      break;
    }
  }
  u[x] = x;
  int q = 0;
  for (int i = 0; i < g[x].size(); ++i) {
    int h = g[x][i];
    if (t[h] >= S) {
      ++q;
    }
  }
  if (q == 1) {
    for (int i = 0; i < g[x].size(); ++i) {
      int h = g[x][i];
      if (t[h] >= S) {
        u[x] = u[h];
        break;
      }
    }
  }
  if (g[x].empty())
    t[x] = 1;
  else {
    for (int i = 0; i < g[x].size(); ++i) {
      int h = g[x][i];
      t[x] += t[h];
    }
  }
}
int dp0[N][S];
void dfs0(int x) {
  for (int i = 0; i < g[x].size(); ++i) {
    int h = g[x][i];
    dfs0(h);
    for (int k = 0; k < S; ++k) dp0[x][k] += max(1, dp0[h][k] - k);
  }
}
int dp[N];
void dfs(int x, int k) {
  dp[x] = 0;
  for (int i = 0; i < g[x].size(); ++i) {
    int h = g[x][i];
    if (t[h] <= k) {
      dp[x] += (((int)(g[x]).size()) - i);
      break;
    }
    dfs(u[h], k);
    dp[x] += max(1LL, dp[u[h]] + (d[x] - d[u[h]]) * 1LL * k);
  }
}
void solv() {
  cin >> n;
  for (int i = 0; i < n - 1; ++i) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dfs00(1, 1);
  dfs0(1);
  for (int x = 1; x <= n; ++x) sort((g[x]).begin(), (g[x]).end(), sot);
  int qq;
  cin >> qq;
  while (qq--) {
    int x, k;
    cin >> x >> k;
    if (k < S) {
      cout << dp0[x][k] << "\n";
      continue;
    }
    dfs(x, k);
    cout << dp[x] << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);
  int tt = 1;
  while (tt--) solv();
  return 0;
}
