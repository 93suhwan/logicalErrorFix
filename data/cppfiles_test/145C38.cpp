#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5, INF = 0x3f3f3f3f;
int T;
int n, k, x, y, t[N], ans;
map<int, vector<pair<int, int>>> mp, mp1;
vector<int> res;
int dis[N];
int find(int x) { return x == dis[x] ? x : dis[x] = find(dis[x]); }
void uni(int x, int y) {
  x = find(x);
  y = find(y);
  if (x != y) {
    dis[x] = y;
    t[y] = min(t[x], t[y]);
  }
}
bool check(int m) {
  int num = upper_bound(res.begin(), res.end(), m) - res.begin();
  return res.size() - num <= m + 1;
}
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &k);
    mp.clear();
    mp1.clear();
    res.clear();
    for (int i = 1; i <= n; i++) {
      scanf("%d%d%d", &x, &y, &t[i]);
      dis[i] = i;
      mp[x].push_back(pair<int, int>(y, i));
      mp1[y].push_back(pair<int, int>(x, i));
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
    for (auto it : mp1) {
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
    int l = 0, r = res.size() - 1, m;
    while (l <= r) {
      m = l + r >> 1;
      if (check(m))
        r = m - 1;
      else
        l = m + 1;
    }
    printf("%d\n", l);
  }
}
