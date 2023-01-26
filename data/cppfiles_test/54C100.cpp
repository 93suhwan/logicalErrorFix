#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e6 + 5;
vector<vector<pair<long long, long long> > > dis(maxn);
long long flag[maxn];
long long c1, c2;
bool ok;
void dfs(long long index, long long p) {
  flag[index] = p;
  for (long long i = 0; i < dis[index].size(); i++) {
    if (flag[dis[index][i].first] != -1 &&
        flag[dis[index][i].first] != (dis[index][i].second == p))
      ok = false;
    if (flag[dis[index][i].first] == -1) {
      if (dis[index][i].second == p) {
        c1++;
      } else
        c2++;
      dfs(dis[index][i].first, dis[index][i].second == p);
    }
  }
}
signed main() {
  long long t;
  cin >> t;
  memset(flag, -1, sizeof(flag));
  while (t--) {
    long long n, m;
    cin >> n >> m;
    long long x, y;
    string s;
    while (m--) {
      cin >> x >> y >> s;
      if (s[0] == 'c') {
        dis[x].push_back({y, 1});
        dis[y].push_back({x, 1});
      } else {
        dis[x].push_back({y, 0});
        dis[y].push_back({x, 0});
      }
    }
    long long ans = 0;
    ok = true;
    for (long long i = 1; i <= n; i++) {
      if (flag[i] == -1) {
        c1 = 1, c2 = 0;
        dfs(i, 1);
        ans += max(c1, c2);
      }
    }
    for (long long i = 1; i <= n; i++) {
      dis[i].clear();
      flag[i] = -1;
    }
    if (!ok)
      cout << "-1" << endl;
    else
      cout << ans << endl;
  }
  return 0;
}
