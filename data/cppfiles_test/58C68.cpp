#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 998244353;
int qpow(int a, int n) {
  int ans = 1;
  for (; n; n >>= 1, a = (ll)a * a % mod)
    if (n & 1) ans = (ll)ans * a % mod;
  return ans;
}
const int maxn = 400400;
int fac[maxn], ifac[maxn];
int C(int n, int m) {
  return fac[n] * (ll)ifac[m] % mod * (ll)ifac[n - m] % mod;
}
struct node {
  int val, tag;
  int pa, ch[2];
} buf[maxn];
int tot, rt;
int init(int v) {
  buf[++tot] = (node){v, 0, 0, 0, 0};
  return tot;
}
void push_down(int rt) {
  if (buf[rt].tag) {
    if (buf[rt].ch[0]) {
      buf[buf[rt].ch[0]].val += buf[rt].tag;
      buf[buf[rt].ch[0]].tag += buf[rt].tag;
    }
    if (buf[rt].ch[1]) {
      buf[buf[rt].ch[1]].val += buf[rt].tag;
      buf[buf[rt].ch[1]].tag += buf[rt].tag;
    }
    buf[rt].tag = 0;
  }
}
void rot(int x, int c) {
  int g = buf[buf[x].pa].pa;
  int p = buf[x].pa;
  int b = buf[x].ch[!c];
  push_down(g);
  push_down(p);
  push_down(x);
  if (g) {
    if (buf[g].ch[0] == p)
      buf[g].ch[0] = x;
    else
      buf[g].ch[1] = x;
  }
  buf[x].pa = g;
  buf[x].ch[!c] = p;
  buf[p].pa = x;
  buf[p].ch[c] = b;
  if (b) buf[b].pa = p;
}
void splay(int x) {
  while (buf[x].pa) {
    int p = buf[x].pa, g = buf[p].pa;
    if (g) {
      if (x == buf[p].ch[0] && p == buf[g].ch[0]) {
        rot(p, 0);
        rot(x, 0);
      } else if (x == buf[p].ch[0] && p == buf[g].ch[1]) {
        rot(x, 0);
        rot(x, 1);
      } else if (x == buf[p].ch[1] && p == buf[g].ch[0]) {
        rot(x, 1);
        rot(x, 0);
      } else {
        rot(p, 1);
        rot(x, 1);
      }
    } else {
      if (x == buf[p].ch[0])
        rot(x, 0);
      else
        rot(x, 1);
    }
  }
}
int ask(int v) {
  int ans = 0;
  int u = rt;
  while (u) {
    push_down(u);
    if (buf[u].val >= v) {
      ans = u;
      u = buf[u].ch[0];
    } else {
      u = buf[u].ch[1];
    }
  }
  if (ans) {
    splay(ans);
    rt = ans;
  }
  return ans;
}
int main(void) {
  int N = 400004;
  fac[0] = 1;
  for (int i = 1; i <= N; i++) fac[i] = fac[i - 1] * (ll)i % mod;
  ifac[N] = qpow(fac[N], mod - 2);
  for (int i = N - 1; i >= 0; i--) ifac[i] = ifac[i + 1] * (ll)(i + 1) % mod;
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, m;
    scanf("%d%d", &n, &m);
    tot = rt = 0;
    int cnt = 0;
    for (int i = 0; i < m; i++) {
      int x, y;
      scanf("%d%d", &x, &y);
      int u = ask(y);
      if (buf[u].val == y) {
        buf[u].val++;
        if (buf[u].ch[1]) {
          buf[buf[u].ch[1]].val++;
          buf[buf[u].ch[1]].tag++;
        }
        continue;
      }
      cnt++;
      int v = init(y);
      if (!u) {
        buf[v].ch[0] = rt;
        if (rt) buf[rt].pa = v;
        rt = v;
      } else {
        push_down(u);
        int lch = buf[u].ch[0];
        buf[u].ch[0] = 0;
        buf[v].ch[0] = lch;
        buf[v].ch[1] = u;
        if (lch) buf[lch].pa = v;
        if (u) buf[u].pa = v;
        rt = v;
      }
      buf[v].val++;
      if (buf[v].ch[1]) {
        buf[buf[v].ch[1]].val++;
        buf[buf[v].ch[1]].tag++;
      }
    }
    printf("%d\n", C(n + n - 1 - cnt, n));
  }
  return 0;
}
