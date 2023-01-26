#include <bits/stdc++.h>
using namespace std;
int n, k, s[55][55], tp[55], fu[305][2], vl[305], fa[55], ct, s1[55][2], c1,
    as1 = 1e8, is[305], f1[305], f2[305], vis[305], ds[305], t1[55], t2[55],
    ls[305];
int finds(int x) { return fa[x] == x ? x : fa[x] = finds(fa[x]); }
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= k; i++) scanf("%d", &tp[i]);
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++) scanf("%d", &s[i][j]), s[j][i] = s[i][j];
  for (int i = 1; i <= n; i++) fa[i] = i;
  for (int i = 1; i <= k; i++)
    for (int j = k + 1; j <= n; j++)
      fu[++ct][0] = i, fu[ct][1] = j, vl[ct] = s[i][j];
  for (int i = 1; i <= 100; i++)
    for (int j = k + 1; j <= n; j++)
      for (int l = j + 1; l <= n; l++)
        if (s[j][l] == i && fa[finds(j)] != finds(l))
          fa[finds(j)] = finds(l), fu[++ct][0] = j, fu[ct][1] = l,
          vl[ct] = s[j][l];
  for (int i = 1; i <= k; i++)
    for (int j = i + 1; j <= k; j++) s1[++c1][0] = i, s1[c1][1] = j;
  for (int i = 0; i < 1 << c1; i++) {
    int su = 0, sr = 0;
    for (int j = 1; j <= ct; j++) is[j] = 0;
    for (int j = 1; j <= k; j++) fa[j] = j, t1[j] = tp[j], t2[j] = 0;
    for (int j = 1; j <= c1; j++)
      if ((i >> j - 1) & 1) {
        su += s[s1[j][0]][s1[j][1]];
        sr++;
        t1[s1[j][0]]--;
        t1[s1[j][1]]--;
        if (fa[finds(s1[j][0])] == finds(s1[j][1]))
          su = 1e8;
        else
          fa[finds(s1[j][0])] = finds(s1[j][1]);
      }
    for (int j = 1; j <= k; j++)
      if (t1[j] < 0) su = 1e8;
    if (su > 1e7) continue;
    for (int j = 1; j <= n - 1 - sr; j++) {
      for (int l = 1; l <= ct; l++) f1[l] = f2[l] = vis[l] = 0, ds[l] = 1e8;
      for (int l = 1; l <= n; l++) fa[l] = l;
      for (int l = 1; l <= c1; l++)
        if ((i >> l - 1) & 1) fa[finds(s1[l][0])] = finds(s1[l][1]);
      for (int l = 1; l <= ct; l++)
        if (is[l]) fa[finds(fu[l][0])] = finds(fu[l][1]);
      for (int l = 1; l <= k; l++) t2[l] = 0;
      for (int l = 1; l <= ct; l++)
        if (is[l] && fu[l][0] <= k) t2[fu[l][0]]++;
      for (int l = 1; l <= ct; l++)
        if (!is[l])
          f2[l] = fu[l][0] > k || t2[fu[l][0]] < t1[fu[l][0]],
          f1[l] = fa[finds(fu[l][0])] != finds(fu[l][1]);
      for (int l = 1; l <= ct; l++)
        if (f1[l]) ds[l] = vl[l], ls[l] = 0;
      int as = 1e9, tp = 0;
      for (int t = 1; t <= ct; t++) {
        int fr = 1;
        for (int l = 1; l <= ct; l++)
          if (!vis[l] && ds[l] < ds[fr]) fr = l;
        vis[fr] = 1;
        if (f2[fr]) {
          as = ds[fr], tp = fr;
          break;
        }
        if (!is[fr]) {
          if (fu[fr][0] <= k) t2[fu[fr][0]]++;
          for (int l = 1; l <= ct; l++)
            if (is[l] &&
                (t2[fu[fr][0]] <= t1[fu[fr][0]] || fu[l][0] == fu[fr][0]) &&
                ds[l] > ds[fr] - vl[l])
              ds[l] = ds[fr] - vl[l], ls[l] = fr;
          if (fu[fr][0] <= k) t2[fu[fr][0]]--;
        } else {
          for (int l = 1; l <= n; l++) fa[l] = l;
          for (int l = 1; l <= c1; l++)
            if ((i >> l - 1) & 1) fa[finds(s1[l][0])] = finds(s1[l][1]);
          for (int l = 1; l <= ct; l++)
            if (is[l] && l != fr) fa[finds(fu[l][0])] = finds(fu[l][1]);
          for (int l = 1; l <= ct; l++)
            if (!is[l] && (finds(fu[l][0]) != finds(fu[l][1])) &&
                ds[l] > ds[fr] + vl[l])
              ds[l] = ds[fr] + vl[l], ls[l] = fr;
        }
      }
      su += as;
      while (tp) is[tp] ^= 1, tp = ls[tp];
    }
    if (as1 > su) as1 = su;
  }
  printf("%d\n", as1);
}
