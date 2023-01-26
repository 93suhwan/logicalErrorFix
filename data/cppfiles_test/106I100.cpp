#include <bits/stdc++.h>
using namespace std;
unsigned int X;
void srand_() {
  struct timeval tv;
  gettimeofday(&tv, NULL);
  X = tv.tv_sec ^ tv.tv_usec | 1;
}
int rand_() { return (X *= 3) >> 1; }
int *ej[((200 * 20 * 2) * 2)], eo[((200 * 20 * 2) * 2)],
    aa_[((200 * 20 * 2) * 2)], mate[((200 * 20 * 2) * 2)], n_;
char visited[((200 * 20 * 2) * 2)];
int newnode(int a) {
  aa_[n_] = a;
  ej[n_] = (int *)malloc(2 * sizeof *ej[n_]);
  return n_++;
}
void append(int i, int j) {
  int o = eo[i]++;
  if (o >= 2 && (o & o - 1) == 0)
    ej[i] = (int *)realloc(ej[i], o * 2 * sizeof *ej[i]);
  ej[i][o] = j;
}
int a_, i_, j_;
void dfs1(int s, int i) {
  int o;
  if (visited[i]) return;
  visited[i] = 1;
  for (o = eo[i]; o--;) {
    int j = ej[i][o];
    if (mate[j] == -1) {
      if (a_ < aa_[s] + aa_[j]) a_ = aa_[s] + aa_[j], i_ = s, j_ = j;
    } else
      dfs1(s, mate[j]);
  }
}
int dfs2(int i, int t) {
  int o;
  if (visited[i]) return 0;
  visited[i] = 1;
  for (o = eo[i]; o--;) {
    int j = ej[i][o];
    if (mate[j] == -1 && j == t || mate[j] != -1 && dfs2(mate[j], t)) {
      mate[i] = j, mate[j] = i;
      return 1;
    }
  }
  return 0;
}
int main() {
  static int aa[1 << 20], idx[1 << 20], kk[2000000 + 1],
      ii[((200 * 20 * 2) * 2)];
  int n, k, k_, i, a, b, ans;
  srand_();
  scanf("%d%d", &n, &k);
  for (b = 0; b < 1 << n; b++) scanf("%d", &aa[b]);
  for (b = 0; b < 1 << n; b++)
    for (i = 0; i < n; i++)
      if ((b & 1 << i) == 0) kk[aa[b] + aa[b | 1 << i]]++;
  k_ = k * 20 * 2;
  for (a = 2000000; a >= 0; a--)
    if (k_ > kk[a])
      k_ -= kk[a];
    else
      kk[a] = k_, k_ = 0;
  n_ = 0;
  memset(idx, -1, (1 << n) * sizeof *idx);
  for (b = 0; b < 1 << n; b++)
    for (i = 0; i < n; i++)
      if ((b & 1 << i) == 0 && kk[aa[b] + aa[b | 1 << i]]-- > 0) {
        if (idx[b] == -1) idx[b] = newnode(aa[b]);
        if (idx[b | 1 << i] == -1) idx[b | 1 << i] = newnode(aa[b | 1 << i]);
        append(idx[b], idx[b | 1 << i]), append(idx[b | 1 << i], idx[b]);
      }
  memset(mate, -1, n_ * sizeof *mate);
  for (i = 0; i < n_; i++) ii[i] = i;
  sort(ii, ii + n_);
  ans = 0;
  while (k--) {
    memset(visited, 0, n_ * sizeof *visited);
    a_ = i_ = j_ = -1;
    for (i = n_ - 1; i >= 0; i--)
      if (mate[ii[i]] == -1) dfs1(ii[i], ii[i]);
    if (a_ == -1) break;
    memset(visited, 0, n_ * sizeof *visited);
    ans += a_, dfs2(i_, j_);
  }
  printf("%d\n", ans);
  return 0;
}
