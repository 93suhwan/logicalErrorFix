#include <bits/stdc++.h>
using namespace std;
int ch[20005][26], len[20005], fa[20005];
bool tg[20005];
int tot = 1;
int las = 1;
void insert(int x) {
  int np = ++tot;
  len[np] = len[las] + 1;
  int p = las;
  las = np;
  for (; p && !ch[p][x]; p = fa[p]) ch[p][x] = np;
  if (!p) {
    fa[np] = 1;
    return;
  }
  int q = ch[p][x];
  if (len[q] == len[p] + 1) {
    fa[np] = q;
    return;
  }
  int nq = ++tot;
  memcpy(ch[nq], ch[q], sizeof(ch[q]));
  fa[nq] = fa[q];
  len[nq] = len[p] + 1;
  fa[q] = fa[np] = nq;
  for (; p && ch[p][x] == q; p = fa[p]) ch[p][x] = nq;
  return;
}
long long ans = 0;
int llen;
int rk[5005], f[5005];
int rkk;
int val[5005];
int n;
bool ins[5005];
void dfs(int x, int ll) {
  if (llen && tg[x]) {
    for (int i = llen + 1; i <= n + 1; i++)
      f[llen] = max(f[llen], f[i] + llen - val[i]);
    rk[llen] = ++rkk, val[llen] = llen;
  }
  for (int i = 0; i <= 25; i++) {
    int to = ch[x][i];
    if (!to) continue;
    llen++;
    dfs(to, ll + 1);
    llen--;
  }
  for (int i = 1; i <= n; i++)
    if (rk[i] && val[i]) val[i]--;
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    rkk = 0;
    las = tot = 1;
    int ans = 0;
    scanf("%d", &n);
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) insert(s[i] - 'a');
    for (int i = las; i; i = fa[i]) tg[i] = 1;
    dfs(1, 0);
    for (int i = n; i >= 1; i--) {
      ans = max(ans, f[i]);
      f[i] = 0;
      rk[i] = 0;
      val[i] = 0;
    }
    printf("%d\n", ans);
    for (int ii = 1; ii <= tot; ii++)
      for (int i = 0; i <= 25; i++)
        ch[ii][i] = 0, len[ii] = 0, fa[ii] = 0, tg[ii] = 0;
  }
  return 0;
}
