#include <bits/stdc++.h>
using namespace std;
const int MAXN = 300100;
struct DSU {
  int p[MAXN];
  DSU() { iota(p, p + MAXN, 0); }
  int find(int x) {
    if (x == p[x]) return x;
    return p[x] = find(p[x]);
  }
  void unite(int a, int b) { p[find(a)] = find(b); }
  int ask(int a, int b) { return find(a) == find(b); }
};
int n, m;
vector<int> E[MAXN];
const int LOG = 20;
int lca[MAXN][LOG];
int dub[MAXN];
void dfs(int cvor, int par) {
  for (auto ncvor : E[cvor]) {
    if (ncvor == par) continue;
    lca[ncvor][0] = cvor;
    dub[ncvor] = dub[cvor] + 1;
    dfs(ncvor, cvor);
  }
}
int get_lca(int a, int b) {
  if (dub[a] < dub[b]) swap(a, b);
  for (int i = LOG - 1; i >= 0; i--) {
    if (dub[a] - (1 << i) >= dub[b]) {
      a = lca[a][i];
    }
  }
  if (a == b) return a;
  for (int i = LOG - 1; i >= 0; i--) {
    if (lca[a][i] != lca[b][i]) {
      a = lca[a][i];
      b = lca[b][i];
    }
  }
  return lca[a][0];
}
int cnt[MAXN];
int kraj[MAXN];
int main() {
  scanf("%d %d", &n, &m);
  DSU U;
  for (int i = (0); i < int(m); i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    if (!U.ask(a, b)) {
      E[a].push_back(b);
      E[b].push_back(a);
      U.unite(a, b);
    }
  }
  dfs(1, -1);
  for (int i = 1; i < LOG; i++) {
    for (int j = (1); j < int(n + 1); j++) {
      lca[j][i] = lca[lca[j][i - 1]][i - 1];
    }
  }
  int q;
  scanf("%d", &q);
  vector<vector<int> > ans;
  for (int i = (0); i < int(q); i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    int l = get_lca(a, b);
    cnt[a]++;
    cnt[b]++;
    cnt[l] -= 2;
    vector<int> tmp;
    ans.push_back(tmp);
    int cvor = a;
    while (cvor != l) {
      ans.back().push_back(cvor);
      cvor = lca[cvor][0];
    }
    ans.back().push_back(l);
    cvor = b;
    while (cvor != l) {
      tmp.push_back(cvor);
      cvor = lca[cvor][0];
    }
    reverse((tmp).begin(), (tmp).end());
    for (auto x : tmp) ans.back().push_back(x);
  }
  int sol = 0;
  vector<int> bio(n + 2);
  vector<int> P;
  for (int i = (1); i < int(n + 1); i++) P.push_back(i);
  sort((P).begin(), (P).end(), [&](int a, int b) { return dub[a] > dub[b]; });
  for (int ii = (0); ii < int(n); ii++) {
    int i = P[ii];
    if (cnt[i] % 2 == 0) continue;
    sol++;
    int cvor = i;
    while (cvor > 0 && cnt[cvor] % 2) {
      cnt[cvor]++;
      cvor = lca[cvor][0];
    }
    if (cvor > 0 && kraj[cvor])
      sol--;
    else if (cvor > 0)
      kraj[cvor]++;
  }
  if (!sol) {
    puts("YES");
    for (int i = (0); i < int((int)ans.size()); i++) {
      printf("%d\n", (int)ans[i].size());
      for (auto x : ans[i]) printf("%d ", x);
      puts("");
    }
  } else {
    puts("NO");
    printf("%d\n", sol);
  }
  return 0;
}
