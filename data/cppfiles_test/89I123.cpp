#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, pd[N], fa[N];
vector<int> e[N];
inline void clear() {
  for (int i = 1; i <= n; ++i) e[i].clear(), pd[i] = 0;
}
void pdfs(int u, int f) {
  fa[u] = f;
  if (e[u].size() == 1 && f) {
    pd[u] = 1;
    return;
  }
  int ct1 = 0, ct2 = 0, cd = 0;
  for (int v : e[u]) {
    if (v == f) continue;
    pdfs(v, u);
    ++cd;
    if (pd[v] == 1) ++ct1;
    if (pd[v] == 2) ++ct2;
  }
  if (cd == ct1)
    pd[u] = 2;
  else if (cd == ct2)
    pd[u] = 1;
}
int main() {
  int T;
  scanf("%d", &T);
  while (T-- > 0) {
    scanf("%d", &n);
    if (n == 1) {
      puts("1");
      continue;
    }
    for (int i = 1, u, v; i < n; ++i)
      scanf("%d%d", &u, &v), e[u].push_back(v), e[v].push_back(u);
    pdfs(1, 0);
    pd[1] = 0;
    int ans = count(pd + 1, pd + n + 1, 1) - count(pd + 1, pd + n + 1, 2) + 1;
    for (int i = 2; i <= n; ++i)
      if (pd[i] == 1 && pd[fa[i]] != 2) {
        --ans;
        break;
      }
    printf("%d\n", ans);
    clear();
  }
  return 0;
}
