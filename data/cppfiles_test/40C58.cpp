#include <bits/stdc++.h>
using namespace std;
const int N = 6e5 + 5;
int n, m, q;
int f[N];
int target[N], pre[N], last[N], tot = 0;
int frmm[N], to[N], qwqwq;
void add(int u, int v) {
  target[++tot] = v;
  pre[tot] = last[u];
  last[u] = tot;
}
int find(int x) { return x == f[x] ? x : f[x] = find(f[x]); }
int frm[N], frme[N];
void dfs(int u, int fa) {
  for (int ptr = last[u]; ptr; ptr = pre[ptr]) {
    int v = target[ptr];
    if (v != fa) {
      frm[v] = u;
      frme[v] = (ptr + 1) / 2;
      dfs(v, u);
    }
  }
}
int vis[N];
vector<int> qs[N];
bool used[N];
int d[N];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = (1); i <= (n); ++i) f[i] = i;
  for (int i = (1); i <= (m); ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    int uu = find(u), vv = find(v);
    if (uu == vv) continue;
    add(u, v);
    add(v, u);
    f[uu] = vv;
    frmm[++qwqwq] = u, to[qwqwq] = v;
  }
  scanf("%d", &q);
  for (int i = (1); i <= (q); ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    ++d[a], ++d[b];
    dfs(a, 0);
    while (b != a) ++vis[frme[b]], qs[i].push_back(b), b = frm[b];
    qs[i].push_back(a);
    reverse(qs[i].begin(), qs[i].end());
    for (int j = (1); j <= (n); ++j) frme[j] = frm[j] = 0;
  }
  bool flg = 1;
  for (int i = (1); i <= (n - 1); ++i)
    if (vis[i] % 2) {
      flg = 0;
      break;
    }
  if (flg) {
    puts("YES");
    for (int i = (1); i <= (q); ++i) {
      printf("%d\n", qs[i].size());
      for (auto x : qs[i]) printf("%d ", x);
      puts("");
    }
  } else {
    puts("NO");
    int ans = 0;
    for (int i = (1); i <= (n); ++i)
      if (d[i] % 2) {
        ++ans;
      }
    printf("%d\n", ans / 2);
  }
  return 0;
}
