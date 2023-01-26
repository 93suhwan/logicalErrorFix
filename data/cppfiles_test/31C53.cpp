#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[1 << 20];
int ch[1 << 20][2], maxi[1 << 20], mini[1 << 20], ans[1 << 20], fa[1 << 20],
    prefix[1 << 20], dep[1 << 20];
int output[1 << 20];
vector<int> multi[1 << 20];
int root = 1, cnt = 0;
void all_init() {
  memset(mini, 0x3f, sizeof(mini));
  memset(maxi, -0x3f, sizeof(maxi));
  memset(ans, 0x3f, sizeof(ans));
}
void upgrade(int k, int c, int x) {
  if (k == c) return;
  upgrade(k - 1, c, ch[x][0]);
  upgrade(k - 1, c, ch[x][1]);
  ans[x] =
      min(mini[ch[x][1]] + prefix[ch[x][1]] - maxi[ch[x][0]] - prefix[ch[x][0]],
          min(ans[ch[x][0]], ans[ch[x][1]]));
  maxi[x] = max(maxi[ch[x][0]] + prefix[ch[x][0]] - prefix[x],
                maxi[ch[x][1]] + prefix[ch[x][1]] - prefix[x]);
  mini[x] = min(mini[ch[x][0]] + prefix[ch[x][0]] - prefix[x],
                mini[ch[x][1]] + prefix[ch[x][1]] - prefix[x]);
}
int build(int d, int limit) {
  if (d < 0) return 0;
  int x = ++cnt;
  multi[d].push_back(x);
  prefix[x] = limit;
  dep[x] = d;
  ch[x][0] = build(d - 1, limit);
  ch[x][1] = build(d - 1, limit | (1 << (d - 1)));
  fa[ch[x][0]] = fa[ch[x][1]] = x;
  return x;
}
void insert(int v) {
  int x = root;
  for (int i = k - 1; i >= 0; --i) {
    int s = v >> i & 1;
    x = ch[x][s];
    maxi[x] = max(maxi[x], v - prefix[x]);
    mini[x] = min(mini[x], v - prefix[x]);
  }
}
void flip(int c) {
  for (int i = 0; i < multi[c].size(); ++i) {
    int x = multi[c][i];
    swap(ch[x][0], ch[x][1]);
    swap(prefix[ch[x][0]], prefix[ch[x][1]]);
  }
  upgrade(k, c - 1, root);
}
void DFS(int d, int x) {
  if (d == k) {
    output[x] = ans[root];
    return;
  }
  DFS(d + 1, x);
  flip(d + 1);
  DFS(d + 1, x | (1 << d));
  flip(d + 1);
}
int main() {
  all_init();
  scanf("%d%d", &n, &k);
  build(k, 0);
  fa[0] = 0;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    insert(a[i]);
  }
  upgrade(k, 0, root);
  DFS(0, 0);
  for (int i = 0; i < (1 << k); ++i) printf("%d ", output[i]);
}
