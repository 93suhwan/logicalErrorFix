#include <bits/stdc++.h>
using namespace std;
int i, j, k, n, m, t, x[200500], y[200500], ed[200500], l, r, res, md,
    a[200500], mn;
int vis[200500];
vector<int> v[200500];
map<int, vector<pair<int, int> > > mp;
void dfs(int x) {
  mn = min(mn, ed[x]);
  vis[x] = 1;
  for (auto i : v[x]) {
    if (!vis[i]) dfs(i);
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin >> t;
  while (t--) {
    cin >> n >> k;
    for (i = 1; i <= n; i++) {
      cin >> x[i] >> y[i] >> ed[i];
    }
    mp.clear();
    for (i = 1; i <= n; i++) {
      v[i].clear();
      mp[x[i]].push_back({y[i], i});
    }
    for (auto [x, s] : mp) {
      if (s.size() <= 1) continue;
      sort(s.begin(), s.end());
      m = s.size();
      for (i = 0; i < m; i++) {
        if (i && (s[i].first - s[i - 1].first <= k)) {
          v[s[i].second].push_back(s[i - 1].second);
          v[s[i - 1].second].push_back(s[i].second);
        }
      }
    }
    mp.clear();
    for (i = 1; i <= n; i++) {
      mp[y[i]].push_back({x[i], i});
    }
    for (auto [x, s] : mp) {
      if (s.size() <= 1) continue;
      sort(s.begin(), s.end());
      m = s.size();
      for (i = 0; i < m; i++) {
        if (i && (s[i].first - s[i - 1].first <= k)) {
          v[s[i].second].push_back(s[i - 1].second);
          v[s[i - 1].second].push_back(s[i].second);
        }
      }
    }
    memset(vis, 0, n * 4 + 50);
    memset(a, 0, n * 4 + 50);
    r = 0;
    for (i = 1; i <= n; i++) {
      if (!vis[i]) {
        mn = 200005;
        dfs(i);
        a[mn]++;
        r++;
      }
    }
    for (res = 0;; res++) {
      r -= a[res];
      if (r <= res + 1) break;
    }
    cout << res << '\n';
  }
}
