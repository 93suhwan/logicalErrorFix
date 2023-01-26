#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 2e5 + 5;
int tt;
int n, k;
bool vis[maxn];
int t[maxn];
int x[maxn], y[maxn];
vector<int> E[maxn];
void dfs(int nd) {
  vis[nd] = 1;
  for (auto i : E[nd])
    if (!vis[i]) dfs(i);
}
bool check(int x) {
  for (int i = 1; i <= n; i++) vis[i] = 0;
  for (int i = 1; i <= n; i++)
    if (t[i] <= x and !vis[i]) dfs(i);
  int jg = 0;
  for (int i = 1; i <= n; i++)
    if (!vis[i]) dfs(i), jg++;
  return (jg <= x + 1);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> tt;
  while (tt--) {
    cin >> n >> k;
    map<int, vector<pair<int, int>>> ed[2];
    for (int i = 1; i <= n; i++) E[i].clear();
    for (int i = 1; i <= n; i++) {
      cin >> x[i] >> y[i] >> t[i];
      ed[0][x[i]].push_back({y[i], i});
      ed[1][y[i]].push_back({x[i], i});
    }
    for (int i = 0; i < 2; i++) {
      for (auto j : ed[i]) {
        vector<pair<int, int>> v = j.second;
        sort(v.begin(), v.end());
        for (int l = 0; l < (int)v.size() - 1; l++) {
          if (v[l + 1].first - v[l].first <= k) {
            E[v[l].second].push_back(v[l + 1].second);
            E[v[l + 1].second].push_back(v[l].second);
          }
        }
      }
    }
    int l = 0, r = n - 1, md, jog = n;
    while (l <= r) {
      md = (l + r) >> 1;
      if (check(md))
        jog = md, r = md - 1;
      else
        l = md + 1;
    }
    cout << jog << '\n';
  }
}
