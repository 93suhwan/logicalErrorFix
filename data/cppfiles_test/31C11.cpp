#include <bits/stdc++.h>
const int K = 19;
const int N = 1 << K;
const int S = N << 2;
int n, k, a[N];
bool tag[N];
int order[N], ans[N];
int lv[S], rv[S], dis[S], len[S];
int ch[S][2], total = 0, root;
void pushup(int x) {
  len[x] = len[ch[x][0]] + len[ch[x][1]];
  lv[x] = std::min(lv[ch[x][0]], lv[ch[x][1]] + len[ch[x][0]]);
  rv[x] = std::max(rv[ch[x][0]], rv[ch[x][1]] + len[ch[x][0]]);
  dis[x] = std::min({dis[ch[x][0]], dis[ch[x][1]],
                     lv[ch[x][1]] + len[ch[x][0]] - rv[ch[x][0]]});
}
int build(int l, int r) {
  int x = ++total;
  if (l + 1 == r) {
    len[x] = 1;
    if (tag[l]) lv[x] = rv[x] = 0;
    return x;
  }
  ch[x][0] = build(l, (l + r) / 2);
  ch[x][1] = build((l + r) / 2, r);
  return pushup(x), x;
}
void flip(int x, int tar, int height = k - 1) {
  if (height == tar) {
    std::swap(ch[x][0], ch[x][1]);
  } else {
    flip(ch[x][0], tar, height - 1);
    flip(ch[x][1], tar, height - 1);
  }
  pushup(x);
}
signed main() {
  memset(lv, 0x3f, sizeof(lv));
  memset(rv, -0x3f, sizeof(rv));
  memset(dis, 0x3f, sizeof(dis));
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) scanf("%d", a + i), tag[a[i]] = 1;
  for (int i = 0; i < (1 << k); i++) order[i] = i ^ (i >> 1);
  for (int i = 0; i < (1 << k); i++) {
    int cur = 0;
    for (int j = 0; j < k; j++) cur = cur << 1 | (order[i] >> j & 1);
    order[i] = cur;
  }
  root = build(0, 1 << k);
  ans[0] = dis[root];
  for (int i = 1; i < (1 << k); i++) {
    int layer_id = __builtin_ctz(order[i] ^ order[i - 1]);
    flip(root, layer_id), ans[order[i]] = dis[root];
  }
  for (int i = 0; i < (1 << k); i++)
    printf("%d%c", ans[i], " \n"[i == (1 << k) - 1]);
  return 0;
}
