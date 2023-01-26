#include <bits/stdc++.h>
using namespace std;
vector<int> g[300005];
int a[300005], b[300005], cnt[300005], f[300005], level[300005];
int n, m;
void dfs(int x) {
  for (auto v : g[x]) {
    if (v == f[x] || f[v]) continue;
    f[v] = x;
    level[v] = level[x] + 1;
    dfs(v);
  }
}
vector<int> vecs, vect;
void solve(int s, int t) {
  vecs.clear();
  vect.clear();
  vecs.push_back(s);
  vect.push_back(t);
  while (s != t) {
    if (level[s] < level[t]) {
      t = f[t];
      vect.push_back(t);
    } else {
      s = f[s];
      vecs.push_back(s);
    }
  }
}
int main() {
  int i, q, j, ans = 0, u, v;
  scanf("%d%d", &n, &m);
  for (i = 0; i < m; i++) {
    scanf("%d%d", &u, &v);
    g[u].push_back(v);
    g[v].push_back(u);
  }
  scanf("%d", &q);
  for (i = 0; i < q; i++) {
    scanf("%d%d", &a[i], &b[i]);
    cnt[a[i]]++;
    cnt[b[i]]++;
  }
  for (i = 1; i <= n; i++) {
    if (cnt[i] % 2 != 0) ans++;
  }
  if (ans == 0) {
    f[1] = 1;
    level[1] = 1;
    dfs(1);
    printf("YES\n");
    for (i = 0; i < q; i++) {
      solve(a[i], b[i]);
      printf("%d\n", vecs.size() + vect.size() - 1);
      for (j = 0; j < vecs.size() - 1; j++) {
        printf("%d ", vecs[j]);
      }
      for (j = vect.size() - 1; j >= 0; j--) {
        printf("%d ", vect[j]);
      }
      printf("\n");
    }
  } else {
    printf("NO\n%d\n", ans / 2);
  }
  return 0;
}
