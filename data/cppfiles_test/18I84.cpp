#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long LLINF = 1e18;
const int MAXN = 1e6 + 10;
const int mod = 1e9 + 7;
int arr[MAXN];
int vis[MAXN];
int n, d;
vector<vector<int> > cyc;
void dfs(int cur) {
  vis[cur] = 1;
  cyc.back().push_back(arr[cur]);
  int step = n - d;
  int nxt = (cur + step) % n;
  if (vis[nxt]) return;
  dfs(nxt);
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &d);
    for (int i = 0; i < n; ++i) {
      scanf("%d", &arr[i]);
      vis[i] = 0;
    }
    cyc.clear();
    int step = n - d;
    for (int i = 0; i < n; ++i) {
      if (!vis[i]) {
        cyc.push_back({});
        dfs(i);
      }
    }
    bool can = true;
    long long ans = 0;
    for (auto c : cyc) {
      bool flag = false;
      for (auto it : c) {
        if (it == 0) flag = true;
      }
      if (!flag) {
        can = false;
        break;
      }
      int sz = c.size();
      int sta = -1;
      for (int i = 0; i < sz; ++i) {
        int pre = (i - 1 + sz) % sz;
        if (c[i] == 1 && c[pre] == 0) {
          sta = i;
          break;
        }
      }
      if (sta == -1) continue;
      int cur = sta;
      int pre = sta;
      int mx = 0;
      int len = 0;
      while (true) {
        if (c[cur] == 0) {
          mx = max(mx, len);
          len = 0;
        } else {
          ++len;
        }
        cur = (cur + 1) % sz;
        if (cur == sta) break;
      }
      ans += mx;
    }
    if (!can)
      printf("-1\n");
    else
      printf("%lld\n", ans);
  }
  return 0;
}
