#include <bits/stdc++.h>
int ll[200000], rr[200000], pp[200000];
char cc[200000 + 1], profit[200000];
int i_, j_;
void dfs1(int i) {
  if (i == -1) return;
  dfs1(rr[i]);
  if (i_ == -1 || cc[i_] != cc[i]) j_ = i_, i_ = i;
  profit[i] = j_ != -1 && cc[i] < cc[j_];
  dfs1(ll[i]);
}
char bad[200000], dup[200000];
int kk[200000], k_;
int count(int i) {
  if (i != -1 && bad[i]) return 0x3f3f3f3f;
  if (i == -1 || dup[i]) return 0;
  if (kk[i]) return kk[i];
  return (kk[i] = count(pp[i]) + 1);
}
void mark(int i) {
  while (i != -1 && !dup[i]) dup[i] = 1, i = pp[i];
}
void dfs2(int i) {
  int k;
  if (i == -1) return;
  dfs2(ll[i]);
  if (!dup[i]) {
    if (profit[i] && (k = count(i)) <= k_)
      k_ -= k, mark(i);
    else
      bad[i] = 1;
  }
  dfs2(rr[i]);
}
char ans[200000 * 2 + 1];
int n_;
void dfs3(int i) {
  if (i == -1) return;
  dfs3(ll[i]);
  ans[n_++] = cc[i];
  if (dup[i]) ans[n_++] = cc[i];
  dfs3(rr[i]);
}
int main() {
  int n, i;
  scanf("%d%d%s", &n, &k_, cc);
  pp[0] = -1;
  for (i = 0; i < n; i++) {
    scanf("%d%d", &ll[i], &rr[i]), ll[i]--, rr[i]--;
    if (ll[i] != -1) pp[ll[i]] = i;
    if (rr[i] != -1) pp[rr[i]] = i;
  }
  i_ = j_ = -1, dfs1(0);
  dfs2(0);
  dfs3(0);
  printf("%s\n", ans);
  return 0;
}
