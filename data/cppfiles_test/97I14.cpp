#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
int n;
int ovo[N], del[N], ans[N];
int Head[N], Next[N << 1], V[N << 1], cnt;
void add(int u, int v) {
  V[cnt] = v;
  Next[cnt] = Head[u];
  Head[u] = cnt++;
}
struct d {
  int nam, vi, ki;
  bool operator<(const d x) const { return ki > x.ki; }
} qwq[N];
set<pair<int, int> > qaq;
int fat[N], vis[N];
void dfs(int u, int fa) {
  fat[u] = fa;
  for (int i = Head[u]; i != -1; i = Next[i]) {
    if (V[i] != fa) {
      ovo[u]++;
      dfs(V[i], u);
    }
  }
  qaq.insert(make_pair(ovo[u], u));
}
int getf(int x) {
  if (x == 0) return 0;
  if (vis[fat[x]] == 0)
    return fat[x];
  else
    fat[x] = getf(fat[x]);
  return fat[x];
}
int main() {
  memset(Head, -1, sizeof(Head));
  scanf("%d", &n);
  for (int i = 1; i <= n - 1; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    add(u, v);
    add(v, u);
  }
  int q;
  scanf("%d", &q);
  for (int i = 1; i <= q; i++) {
    scanf("%d%d", &qwq[i].vi, &qwq[i].ki);
    qwq[i].nam = i;
  }
  sort(qwq + 1, qwq + q + 1);
  dfs(1, 0);
  for (int i = 1; i <= q; i++) {
    set<pair<int, int> >::iterator it = qaq.end();
    if (it == qaq.begin()) {
      ans[qwq[i].nam] = ovo[qwq[i].vi] - del[qwq[i].vi] * qwq[i].ki;
      continue;
    }
    it--;
    while (it != qaq.begin() && (*it).first - 1 > qwq[i].ki) {
      vis[(*it).second] = 1;
      ovo[getf((*it).second)] += ovo[(*it).second] - 1;
      del[getf((*it).second)] += del[(*it).second] + 1;
      it = qaq.erase(it);
      it--;
    }
    if ((*it).first - 1 > qwq[i].ki) {
      vis[(*it).second] = 1;
      ovo[getf((*it).second)] += ovo[(*it).second] - 1;
      del[getf((*it).second)] += del[(*it).second] + 1;
      qaq.erase(it);
      ans[qwq[i].nam] = ovo[qwq[i].vi] - del[qwq[i].vi] * qwq[i].ki;
    } else {
      ans[qwq[i].nam] = ovo[qwq[i].vi] - del[qwq[i].vi] * qwq[i].ki;
    }
  }
  for (int i = 1; i <= q; i++) {
    printf("%d\n", ans[i]);
  }
  return 0;
}
