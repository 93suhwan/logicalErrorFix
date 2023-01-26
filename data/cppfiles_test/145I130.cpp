#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5, INF = 0x3f3f3f3f;
int T;
int n, k, x, y, t[N], ans;
unordered_map<int, vector<pair<int, int>>> mp;
vector<int> res;
int dis[N];
int find(int x) { return x == dis[x] ? x : dis[x] = find(dis[x]); }
void uni(int x, int y) {
  x = find(x);
  y = find(y);
  if (x != y) {
    dis[x] = y;
    t[x] = min(t[x], t[y]);
  }
}
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &k);
    mp.clear();
    res.clear();
    for (int i = 1; i <= n; i++) {
      scanf("%d%d%d", &x, &y, &t[i]);
      dis[i] = i;
      mp[x].push_back(pair<int, int>(y, i));
      mp[y].push_back(pair<int, int>(x, i));
    }
    for (auto it : mp) {
      auto& e = it.second;
      sort(e.begin(), e.end());
      for (int i = 0; i < e.size(); i++) {
        if (i && e[i].first - e[i - 1].first <= k) {
          uni(e[i].second, e[i - 1].second);
        }
      }
    }
    for (int i = 1; i <= n; i++) {
      if (i == find(i)) {
        res.push_back(t[i]);
      }
    }
    sort(res.begin(), res.end());
    ans = res.size() - 1;
    for (int i = 0; i < res.size(); i++) {
      ans = min(ans, max(res[i], int(res.size() - i - 2)));
    }
    printf("%d\n", ans);
  }
}
