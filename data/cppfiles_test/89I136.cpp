#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, pd[N], ans, res, tot;
vector<int> e[N];
inline void clear() {
  for (int i = 1; i <= n; ++i) e[i].clear(), pd[i] = 0;
  res = 114514;
}
void pdfs(int u, int f) {
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
void work(int u, int f) {
  if (pd[u] == 1) --ans;
  if (pd[u] == 2) --tot;
  res = min(res, ans - tot + 1);
  for (int v : e[u]) {
    if (v == f) continue;
    work(v, u);
  }
  if (pd[u] == 1) ++ans;
  if (pd[u] == 2) ++tot;
}
int main() {
  int T;
  scanf("%d", &T);
  while (T-- > 0) {
    scanf("%d", &n);
    for (int i = 1, u, v; i < n; ++i)
      scanf("%d%d", &u, &v), e[u].push_back(v), e[v].push_back(u);
    pdfs(1, 0);
    res = count(pd + 1, pd + n + 1, 1);
    ans = res;
    tot = count(pd + 1, pd + n + 1, 2);
    work(1, 0);
    printf("%d\n", res);
    clear();
  }
  return 0;
}
