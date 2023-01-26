#include <bits/stdc++.h>
int n, K, L[200010], R[200010], P[200010][20];
char s[200010];
char ans[200010], nxt[200010];
int clk1, cnt[200010], who[200010], idx[200010];
int clk2, bgn[200010], fin[200010];
bool tree[800010];
void dfs(int sn, int fa) {
  P[sn][0] = fa;
  for (int i = 1; i < 20; i++) P[sn][i] = P[P[sn][i - 1]][i - 1];
  bgn[sn] = ++clk2;
  if (L[sn]) dfs(L[sn], sn);
  who[++clk1] = sn;
  idx[sn] = clk1;
  ans[clk1] = s[sn];
  cnt[clk1] = 1;
  if (R[sn]) dfs(R[sn], sn);
  fin[sn] = clk2;
}
void modify(int id, int l, int r, int ql, int qr) {
  if (ql <= l && r <= qr)
    tree[id] = true;
  else {
    int nxt = id << 1, mid = (l + r) >> 1;
    if (ql <= mid) modify(nxt, l, mid, ql, qr);
    if (qr > mid) modify(nxt | 1, mid + 1, r, ql, qr);
  }
}
bool query(int id, int l, int r, int qv) {
  if (l == r)
    return tree[id];
  else if (tree[id])
    return tree[id];
  else {
    int nxt = id << 1, mid = (l + r) >> 1;
    return qv <= mid ? query(nxt, l, mid, qv) : query(nxt | 1, mid + 1, r, qv);
  }
}
int main() {
  scanf("%d%d%s", &n, &K, s + 1);
  for (int i = 1; i <= n; i++) scanf("%d%d", &L[i], &R[i]);
  dfs(1, 0);
  for (int i = n; i; i--)
    nxt[i] = ans[i] == ans[i + 1] ? nxt[i + 1] : ans[i + 1];
  for (int i = 1; i <= n; i++) {
    if (cnt[i] == 2) continue;
    if (ans[i] > nxt[i])
      modify(1, 1, n, bgn[who[i]], fin[who[i]]);
    else if (!query(1, 1, n, bgn[who[i]])) {
      int sm = 0;
      for (int j = who[i], k = 19; k >= 0; k--)
        if (P[j][k] && cnt[idx[P[j][k]]] != 2) sm |= 1 << k, j = P[j][k];
      if (sm + 1 > K) continue;
      for (int j = i; j && cnt[j] != 2; j = idx[P[who[j]][0]]) cnt[j] = 2, K--;
    }
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= cnt[i]; j++) printf("%c", ans[i]);
  printf("\n");
  return 0;
}
