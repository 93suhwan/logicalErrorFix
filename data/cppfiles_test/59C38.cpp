#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int T, n, m, in[N], vis[N], a[N], b[N];
vector<int> e[N];
long long cur;
bool dfs(int k1, int k2) {
  if (vis[k1] || in[k1]) return 1;
  if (cur < a[k1]) return 0;
  vis[k1] = 1;
  cur += b[k1];
  for (int x : e[k1])
    if (x != k2 && dfs(x, k1)) {
      vis[k1] = 0, in[k1] = 1;
      return 1;
    }
  cur -= b[k1];
  vis[k1] = 0;
  return 0;
}
bool chk(int mid) {
  for (int i = (1); i <= (n); ++i) in[i] = 0;
  in[1] = 1, cur = mid;
  while (1) {
    for (int i = (1); i <= (n); ++i)
      if (in[i]) {
        for (auto x : e[i])
          if (!in[x]) {
            if (dfs(x, i)) {
              goto qaq;
            }
          }
      }
    return 0;
  qaq:;
    if (count(in + 1, in + 1 + n, 1) == n) return 1;
  }
}
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &m);
    for (int i = (1); i <= (n); ++i) e[i].clear();
    for (int i = (2); i <= (n); ++i) scanf("%d", &a[i]);
    for (int i = (2); i <= (n); ++i) scanf("%d", &b[i]);
    for (int i = (1); i <= (m); ++i) {
      int k1, k2;
      scanf("%d%d", &k1, &k2);
      e[k1].push_back(k2), e[k2].push_back(k1);
    }
    int l = 0, r = 1000000000, ans = 0;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (chk(mid)) {
        r = mid - 1;
        ans = mid;
      } else {
        l = mid + 1;
      }
    }
    printf("%d\n", ans + 1);
  }
  return 0;
}
