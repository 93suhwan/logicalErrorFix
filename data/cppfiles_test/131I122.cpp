#include <bits/stdc++.h>
using namespace std;
const int N = 4e6 + 10;
int n, idx;
map<int, int> S, S2;
int p[N], v[N], mxs[N];
vector<int> g[N];
int p1, p2, ans;
void dfs(int u) {
  mxs[u] = u, v[u] = 0;
  if (!g[u].size()) return;
  int mx1 = 0, mx2 = 0, P1 = u, P2 = u;
  for (int t : g[u]) {
    dfs(t);
    if (v[t] + 1 >= mx1) {
      mx2 = mx1, P2 = P1;
      mx1 = v[t] + 1, P1 = mxs[t];
    } else if (v[t] + 1 >= mx2)
      mx2 = v[t] + 1, P2 = mxs[t];
  }
  mxs[u] = P1, v[u] = mx1;
  if (mx1 + mx2 > ans) {
    ans = mx1 + mx2;
    p1 = P1, p2 = P2;
  }
}
int main() {
  scanf("%d", &n);
  S[0] = 0;
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    S2[x] = i;
    if (S.count(x)) continue;
    S[x] = ++idx;
    p[idx] = x;
    while (1) {
      int y = 1;
      for (; y < x; y *= 2)
        ;
      y = y - x;
      if (S.count(y)) {
        g[S[y]].push_back(S[x]);
        break;
      } else {
        S[y] = ++idx;
        p[idx] = y;
        g[idx].push_back(S[x]);
      }
      x = y;
    }
  }
  dfs(0);
  printf("%d %d %d", S2[p[p1]], S2[p[p2]], ans);
  return 0;
}
