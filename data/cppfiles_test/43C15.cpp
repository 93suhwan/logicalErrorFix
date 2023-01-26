#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
int n, q, e[200005], a[200005], b[200005], c[200005], t[2000005];
int perm[200005], pre[400005];
int root(int x) { return pre[x] == x ? x : pre[x] = root(pre[x]); }
bool cmp0(int i, int j) { return c[i] > c[j]; }
bool cmp1(int i, int j) { return t[i] < t[j]; }
int w0[400005], w1[400005], par0[400005][19], par1[400005][19], dfn1[400005],
    dep1[400005], seq1[400005], tot;
vector<int> T0[400005], T1[400005];
void dfs1(int v) {
  seq1[tot] = v;
  dfn1[v] = tot++;
  for (int i = 0; i < (int)(T1[v].size()); i++) {
    dep1[T1[v][i]] = dep1[v] + 1;
    dfs1(T1[v][i]);
  }
}
int findp0(int v, int w) {
  for (int i = 18; i >= 0; i--)
    if (w0[par0[v][i]] >= w) v = par0[v][i];
  return v;
}
int lca1(int u, int v) {
  if (dep1[u] < dep1[v]) swap(u, v);
  for (int i = 18; i >= 0; i--)
    if ((dep1[u] - dep1[v]) >> i) u = par1[u][i];
  if (u == v) return u;
  for (int i = 18; i >= 0; i--)
    if (par1[u][i] != par1[v][i]) {
      u = par1[u][i];
      v = par1[v][i];
    }
  return par1[u][0];
}
pair<int, pair<int, int> > dp[400005];
pair<int, pair<int, int> > unite(pair<int, pair<int, int> > A,
                                 pair<int, pair<int, int> > B) {
  if (A.first > B.first) swap(A, B);
  if (A.first == B.first)
    return make_pair(A.first, make_pair(min(A.second.first, B.second.first),
                                        max(A.second.second, B.second.second)));
  else
    return B;
}
int main() {
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= (int)(n); i++) scanf("%d", &e[i]);
  for (int i = 0; i < (int)(n - 1); i++)
    scanf("%d%d%d%d", &a[i], &b[i], &c[i], &t[i]);
  for (int i = 1; i <= (int)(n); i++) pre[i] = i;
  for (int i = 0; i < (int)(n - 1); i++) perm[i] = i;
  sort(perm, perm + n - 1, cmp0);
  for (int i = 0; i < (int)(n - 1); i++) {
    int ce = perm[i], u = root(a[ce]), v = root(b[ce]);
    w0[n + i + 1] = c[ce];
    par0[u][0] = par0[v][0] = pre[u] = pre[v] = pre[n + i + 1] = n + i + 1;
  }
  for (int i = 2 * n - 1; i >= 1; i--)
    for (int j = 1; j <= (int)(18); j++)
      par0[i][j] = par0[par0[i][j - 1]][j - 1];
  for (int i = 1; i <= (int)(2 * n - 2); i++) T0[par0[i][0]].push_back(i);
  for (int i = 1; i <= (int)(n); i++) pre[i] = i;
  for (int i = 0; i < (int)(n - 1); i++) perm[i] = i;
  sort(perm, perm + n - 1, cmp1);
  for (int i = 0; i < (int)(n - 1); i++) {
    int ce = perm[i], u = root(a[ce]), v = root(b[ce]);
    w1[n + i + 1] = t[ce];
    par1[u][0] = par1[v][0] = pre[u] = pre[v] = pre[n + i + 1] = n + i + 1;
  }
  for (int i = 2 * n - 1; i >= 1; i--)
    for (int j = 1; j <= (int)(18); j++)
      par1[i][j] = par1[par1[i][j - 1]][j - 1];
  for (int i = 1; i <= (int)(2 * n - 2); i++) T1[par1[i][0]].push_back(i);
  dfs1(2 * n - 1);
  for (int i = 1; i <= (int)(2 * n - 1); i++)
    if (i <= n)
      dp[i] = make_pair(e[i], make_pair(dfn1[i], dfn1[i]));
    else
      dp[i] = unite(dp[T0[i][0]], dp[T0[i][1]]);
  for (int i = 0; i < (int)(q); i++) {
    int v, w;
    scanf("%d%d", &w, &v);
    w = findp0(v, w);
    printf(
        "%d %d\n", dp[w].first,
        w1[lca1(lca1(seq1[dp[w].second.first], seq1[dp[w].second.second]), v)]);
  }
  return 0;
}
