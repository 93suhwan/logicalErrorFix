#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
const int maxn = 200020;
struct Splay {
  long long rt, val[maxn], fa[maxn], ch[maxn][2], tg[maxn], nodecnt;
  void push_down(long long x) {
    val[x] += tg[x];
    if (ch[x][0] != -1) val[ch[x][0]] += tg[x];
    if (ch[x][1] != -1) val[ch[x][1]] += tg[x];
    tg[x] = 0;
    return;
  }
  long long son_type(long long x) { return (ch[fa[x]][1] == x); }
  void del_node(long long x) {
    fa[x] = ch[x][0] = ch[x][1] = -1, val[x] = tg[x] = 0;
    return;
  }
  void rotate(long long x) {
    long long y = fa[x], z = fa[y], tp = son_type(x);
    ch[y][tp] = ch[x][tp ^ 1];
    if (ch[x][tp ^ 1] != -1) fa[ch[x][tp ^ 1]] = y;
    ch[x][tp ^ 1] = y;
    fa[y] = x, fa[x] = z;
    if (z != -1) ch[z][ch[z][1] == y] = x;
    return;
  }
  void splay(long long x, long long dest) {
    long long f = fa[x];
    while (f != dest) {
      if (fa[f] == dest) {
        rotate(x);
        break;
      }
      if (son_type(x) == son_type(f))
        rotate(f), rotate(x), f = fa[x];
      else
        rotate(x), rotate(x), f = fa[x];
    }
    if (dest == -1) rt = x;
    return;
  }
  void ins(long long x) {
    long long cur = rt, f;
    if (rt == -1) {
      rt = nodecnt, del_node(nodecnt), fa[nodecnt] = -1, val[nodecnt] = x,
      nodecnt++;
      return;
    }
    while (true) {
      push_down(cur);
      f = cur, cur = ch[cur][val[cur] < x];
      if (cur == -1) {
        del_node(nodecnt), fa[nodecnt] = f, ch[f][val[f] < x] = nodecnt,
                           val[nodecnt] = x, splay(nodecnt, -1), nodecnt++;
        return;
      }
    }
    return;
  }
  long long qry_next() {
    long long cur = ch[cur][1];
    while (cur != -1) {
      if (ch[cur][0] == -1) {
        splay(cur, -1);
        return cur;
      }
      cur = ch[cur][0];
    }
    return 1000000000;
  }
  long long fnd(long long x) {
    long long cur = rt;
    while (cur != -1) {
      push_down(cur);
      if (val[cur] == x) return cur;
      cur = ch[cur][val[cur] < x];
    }
    return -1;
  }
  void upd_one(long long x) {
    splay(x, -1);
    val[rt]++;
    if (ch[rt][1] != -1) tg[ch[rt][1]]++;
    return;
  }
} spl;
long long n, m, dx[maxn], dy[maxn], fac[maxn << 1], inv[maxn << 1],
    inv2[maxn << 1];
long long C(long long x, long long y) {
  return (x < 0 || y < 0 || x < y)
             ? 0
             : (fac[x] * ((inv2[y] * inv2[x - y]) % mod)) % mod;
}
int main() {
  long long t, tot;
  fac[0] = fac[1] = inv[1] = inv2[0] = inv2[1] = 1;
  for (int i = 2; i < (maxn << 1); i++) {
    fac[i] = (fac[i - 1] * i) % mod;
    inv[i] = (mod - (((mod / i) * inv[mod % i]) % mod)) % mod;
    inv2[i] = (inv2[i - 1] * inv[i]) % mod;
  }
  scanf("%lld", &t);
  for (int testcases = 0; testcases < t; testcases++) {
    for (int i = 0; i < spl.nodecnt; i++) spl.del_node(i);
    spl.nodecnt = 0, spl.rt = -1;
    scanf("%lld%lld", &n, &m);
    for (int i = 0; i < m; i++) scanf("%lld%lld", &dx[i], &dy[i]);
    tot = 0;
    for (int i = 0; i < m; i++) {
      long long plc = spl.fnd(dy[i] - 1);
      if (plc == -1) tot++;
      plc = spl.fnd(dy[i]);
      if (plc == -1) {
        spl.ins(dy[i]);
        plc = spl.qry_next();
        if (plc != 1000000000) spl.upd_one(plc);
      } else {
        spl.upd_one(plc);
        spl.ins(dy[i]);
      }
    }
    printf("%lld\n", C(n + n - tot - 1, n));
  }
  return 0;
}
