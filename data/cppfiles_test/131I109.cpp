#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 * 30;
vector<int> G[N];
map<int, int> P;
map<int, bool> vis;
int Dis[N], Pos[N], n, V[N], vnt = 0, ans, P1, P2, A[N], tag[N];
void DFS(int u) {
  int mp = 0, smp = 0, mx = 0, smx = 0;
  for (auto v : G[u]) {
    DFS(v);
    if (!mp || Dis[v] + 1 > mx) {
      smx = mx;
      smp = mp;
      mx = Dis[v] + 1;
      mp = Pos[v];
    } else if (!smp || Dis[v] + 1 > smx) {
      smx = Dis[v] + 1;
      smp = Pos[v];
    }
  }
  if (!mp)
    mp = u;
  else if (!smp)
    smp = u;
  if (mp && smp && mx + smx > ans) {
    ans = mx + smx;
    P1 = smp;
    P2 = mp;
  }
  Pos[u] = mp, Dis[u] = mx;
}
int main() {
  scanf("%d", &n);
  for (int i = 1, a; i <= n; i++) {
    scanf("%d", &a);
    A[i] = a;
    P[a] = i;
    while (a) {
      V[++vnt] = a;
      int cur = 1;
      while (cur < a) cur <<= 1;
      a = cur - a;
    }
  }
  V[++vnt] = 0;
  sort(V + 1, V + vnt + 1);
  vnt = unique(V + 1, V + vnt + 1) - V - 1;
  for (int i = 1; i <= n; i++) {
    tag[lower_bound(V + 1, V + vnt + 1, A[i]) - V] = 1;
    while (A[i] && !vis[A[i]]) {
      vis[A[i]] = 1;
      int cur = 1;
      while (cur < A[i]) cur <<= 1;
      G[lower_bound(V + 1, V + vnt + 1, cur - A[i]) - V].push_back(
          lower_bound(V + 1, V + vnt + 1, A[i]) - V);
      A[i] = cur - A[i];
    }
  }
  DFS(1);
  printf("%d %d %d", P[V[P1]], P[V[P2]], ans);
  return 0;
}
