#include <bits/stdc++.h>
using namespace std;
const int N = 1 << 20;
int n, k, a[N], cnt;
struct trie {
  int son[2], de;
} sh[N];
struct node {
  int l, r, ans;
};
vector<node> p[N];
inline int read() {
  int f = 1, x = 0;
  char s = getchar();
  while (s < '0' || s > '9') {
    if (s == '-') f = -1;
    s = getchar();
  }
  while (s >= '0' && s <= '9') {
    x = x * 10 + s - '0';
    s = getchar();
  }
  return x * f;
}
void insert(int num) {
  int x = 0;
  for (int i = k - 1; i >= 0; i--) {
    int now = ((num >> i) & 1), p = sh[x].son[now];
    if (!p) p = ++cnt;
    sh[x].son[now] = p;
    sh[p].de = sh[x].de + 1;
    x = p;
  }
  p[x].push_back((node){num, num, 0x3f3f3f3f});
}
void upd(int x, int s) {
  int now = (int)p[s].size();
  p[x] = p[s];
  p[x].resize(now << 1);
  for (int i = now; i < (int)p[x].size(); i++) {
    p[x][i] = p[x][i - now];
    swap(p[x][i].l, p[x][i].r);
  }
}
inline void pushup(int x) {
  int ls = sh[x].son[0], rs = sh[x].son[1];
  if (!ls) {
    upd(x, rs);
    return;
  }
  if (!rs) {
    upd(x, ls);
    return;
  }
  int now = (int)p[ls].size();
  p[x].resize(now << 1);
  for (int i = 0; i < now; i++) {
    p[x][i].l = p[ls][i].l;
    p[x][i].r = p[rs][i].r;
    p[x][i].ans = min(p[ls][i].ans, p[rs][i].ans);
    p[x][i].ans = min(p[x][i].ans, (p[rs][i].l ^ i) - (p[ls][i].r ^ i));
  }
  for (int i = now; i < (int)p[x].size(); i++) {
    p[x][i].l = p[rs][i - now].l;
    p[x][i].r = p[ls][i - now].r;
    p[x][i].ans = min(p[ls][i - now].ans, p[rs][i - now].ans);
    p[x][i].ans =
        min(p[x][i].ans, (p[ls][i - now].l ^ i) - (p[rs][i - now].r ^ i));
  }
}
void dfs(int x) {
  if (sh[x].de == k) return;
  if (sh[x].son[0]) dfs(sh[x].son[0]);
  if (sh[x].son[1]) dfs(sh[x].son[1]);
  pushup(x);
}
signed main() {
  n = read();
  k = read();
  for (int i = 1; i <= n; i++) insert(read());
  for (int i = 0; i <= cnt; i++)
    if (sh[i].de != k) p[i].resize(1 << (k - sh[i].de));
  dfs(0);
  assert((int)p[0].size() == (1 << k));
  for (int i = 0; i < (int)p[0].size(); i++) printf("%d ", p[0][i].ans);
  printf("\n");
}
