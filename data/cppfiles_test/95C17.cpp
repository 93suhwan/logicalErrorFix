#include <bits/stdc++.h>
using namespace std;
int T, n, m;
vector<vector<int> > v;
vector<int> suf[2][500003], pre[2][500003];
bool vis[500003];
int main() {
  cin >> T;
  while (T--) {
    cin >> n >> m;
    vector<int> qwq;
    for (int i = 0; i < n; i++)
      suf[0][i].clear(), pre[0][i].clear(), suf[1][i].clear(),
          pre[1][i].clear();
    v.clear();
    for (int i = 0; i < n; i++) {
      v.push_back(qwq);
      v[i].push_back(-233);
      for (int j = 0; j < m; j++) {
        int x;
        scanf("%d", &x);
        v[i].push_back(x);
      }
      for (int j = 0; j <= m + 1; j++)
        suf[0][i].push_back(0), suf[1][i].push_back(19260817),
            pre[0][i].push_back(0), pre[1][i].push_back(19260817);
      for (int j = 1; j <= m; j++)
        pre[0][i][j] = max(pre[0][i][j - 1], v[i][j]),
        pre[1][i][j] = min(pre[1][i][j - 1], v[i][j]);
      for (int j = m; j > 0; j--)
        suf[0][i][j] = max(suf[0][i][j + 1], v[i][j]),
        suf[1][i][j] = min(suf[1][i][j + 1], v[i][j]);
    }
    vector<pair<pair<int, int>, int> > g;
    vector<int> V;
    vector<int> ans;
    int res = -1;
    for (int i = 1; i < m; i++) {
      g.clear();
      V.clear();
      for (int j = 0; j < n; j++)
        g.push_back(make_pair(make_pair(pre[1][j][i], -1), j)),
            g.push_back(make_pair(make_pair(pre[0][j][i], 1), j));
      sort(g.begin(), g.end());
      int cnt = 0;
      multiset<int> minn, maxn;
      for (int j = 0; j < n; j++) maxn.insert(-suf[0][j][i + 1]), vis[j] = 0;
      for (int j = 0; j < g.size(); j++) {
        cnt += g[j].first.second;
        if (vis[g[j].second]) {
          V.push_back(g[j].second);
          maxn.erase(maxn.find(-suf[0][g[j].second][i + 1]));
          minn.insert(suf[1][g[j].second][i + 1]);
        }
        vis[g[j].second] = 1;
        if (cnt == 0)
          if (maxn.size() && minn.size())
            if (-*maxn.begin() < *minn.begin()) {
              res = i;
              ans = V;
              break;
            }
      }
      if (res != -1) break;
    }
    if (res == -1) {
      printf("NO\n");
      continue;
    }
    printf("YES\n");
    for (int j = 0; j < n; j++) vis[j] = 0;
    for (int j = 0; j < ans.size(); j++) vis[ans[j]] = 1;
    for (int j = 0; j < n; j++)
      if (vis[j])
        putchar('B');
      else
        putchar('R');
    printf(" %d\n", res);
  }
}
