#include <bits/stdc++.h>
using namespace std;
const int MAX = 1000;
int test, n, m, a[MAX + 1], b[MAX + 1], u, v, par[MAX + 1], lef, rig, mid, cnt,
    res;
long long curB;
bool fr[MAX + 1], frInProcess[MAX + 1], found;
vector<int> adj[MAX + 1];
void visit(const int& u, const long long& bInProcess) {
  frInProcess[u] = true;
  for (const int& v : adj[u]) {
    if (v != par[u] && bInProcess >= a[v])
      if (frInProcess[v]) {
        for (int point = u; point != -1; point = par[point])
          if (!fr[point]) {
            fr[point] = true;
            curB += b[point];
            ++cnt;
          }
        for (int point = v; point != -1; point = par[point])
          if (!fr[point]) {
            fr[point] = true;
            curB += b[point];
            ++cnt;
          }
        found = true;
        return;
      } else {
        par[v] = u;
        visit(v, bInProcess + b[v]);
      }
    if (found) return;
  }
}
int main() {
  scanf("%d", &test);
  while (test--) {
    scanf("%d %d", &n, &m);
    lef = 1e9 + 10;
    rig = 0LL;
    for (int i = 2; i <= n; ++i) {
      scanf("%d", a + i);
      ++a[i];
      lef = min(lef, a[i]);
      rig = max(rig, a[i]);
    }
    for (int i = 2; i <= n; ++i) scanf("%d", b + i);
    for (int i = 1; i <= n; ++i) adj[i].clear();
    while (m--) {
      scanf("%d %d", &u, &v);
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    while (lef <= rig) {
      mid = (lef + rig) >> 1;
      curB = mid;
      memset(fr + 1, false, n);
      fr[1] = true;
      cnt = 1;
      while (cnt < n) {
        memcpy(frInProcess + 1, fr + 1, n);
        memset(par + 1, -1, n * sizeof(int));
        found = false;
        for (int start = 1; start <= n; ++start)
          if (!found && fr[start])
            for (const int& u : adj[start])
              if (!found && !fr[u] && curB >= a[u]) {
                par[u] = start;
                visit(u, curB + b[u]);
              }
        if (!found) break;
      }
      if (cnt == n)
        rig = (res = mid) - 1;
      else
        lef = mid + 1;
    }
    printf("%d\n", res);
  }
  return 0;
}
