#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
struct node {
  int l, r, idx;
  bool operator<(const node &x) const {
    if (r != x.r) return r < x.r;
    return l < x.l;
  }
};
map<int, int> mp;
int a[N], b[N], m[N];
int res[N];
vector<node> g[N];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    mp.clear();
    int n;
    scanf("%d", &n);
    for (int i = 0; i <= n; i++) g[i].clear();
    int tot = 0;
    for (int i = 1; i <= n; i++) {
      scanf("%d%d%d", &a[i], &b[i], &m[i]);
      int now = a[i] + b[i] - m[i];
      int l, r;
      l = max(0, a[i] - m[i]);
      r = a[i] - (m[i] - min(m[i], b[i]));
      if (!mp.count(now)) mp[now] = ++tot;
      node p;
      p.l = l, p.r = r, p.idx = i;
      g[mp[now]].push_back(p);
    }
    int num = 0;
    for (int i = 1; i <= tot; i++) {
      int k = -1;
      sort(g[i].begin(), g[i].end());
      for (int j = 0; j < g[i].size(); j++) {
        node now = g[i][j];
        if (now.l > k) {
          num++;
          k = now.r;
        }
        res[now.idx] = k;
      }
    }
    printf("%d\n", num);
    for (int i = 1; i <= n; i++)
      printf("%d %d\n", a[i] - res[i], m[i] - (a[i] - res[i]));
  }
  return 0;
}
