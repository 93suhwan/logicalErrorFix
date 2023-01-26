#include <bits/stdc++.h>
using namespace std;
const int lim = 5e5;
int T, n, m, w, fc[500005], invF[500005];
int rt, cntP;
struct Point {
  int vl, w, sz, tg, ch[2];
} pt[500005];
int New(int vl, int w = rand()) {
  pt[++cntP] = (Point){vl, w, 1, 0, {0, 0}};
  return cntP;
}
void mdf(int p, int vl) {
  pt[p].vl += vl;
  pt[p].tg += vl;
}
void pu(int p) { pt[p].sz = pt[pt[p].ch[0]].sz + pt[pt[p].ch[1]].sz + 1; }
void pd(int p) {
  if (pt[p].tg) {
    if (pt[p].ch[0]) mdf(pt[p].ch[0], pt[p].tg);
    if (pt[p].ch[1]) mdf(pt[p].ch[1], pt[p].tg);
    pt[p].tg = 0;
  }
}
void split(int p, int vl, int &pL, int &pR) {
  if (!p) {
    pL = pR = 0;
    return;
  }
  pd(p);
  if (pt[p].vl <= vl)
    pL = p, split(pt[p].ch[1], vl, pt[p].ch[1], pR);
  else
    pR = p, split(pt[p].ch[0], vl, pL, pt[p].ch[0]);
  pu(p);
}
int merge(int pL, int pR) {
  if (!pL || !pR) return pL | pR;
  if (pt[pL].w < pt[pR].w) {
    pd(pL);
    pt[pL].ch[1] = merge(pt[pL].ch[1], pR);
    pu(pL);
    return pL;
  } else {
    pd(pR);
    pt[pR].ch[0] = merge(pL, pt[pR].ch[0]);
    pu(pR);
    return pR;
  }
}
void ins(int x) {
  int p1 = 0, p2 = 0, t;
  if (x < 3)
    p2 = rt;
  else
    split(rt, x - 2, p1, p2);
  t = p2;
  while (pt[t].ch[0]) pd(t), t = pt[t].ch[0];
  if (t && pt[t].vl == x - 1) {
    mdf(p2, 1);
    rt = merge(p1, p2);
    return;
  }
  ++w;
  mdf(p2, 1);
  rt = merge(merge(p1, New(x)), p2);
}
int qPow(int x, int y) {
  int res = 1;
  for (; y; y /= 2, x = 1ll * x * x % 998244353)
    if (y & 1) res = 1ll * res * x % 998244353;
  return res;
}
int C(int x, int y) {
  return 1ll * fc[x] * invF[y] % 998244353 * invF[x - y] % 998244353;
}
void slv() {
  scanf("%d %d", &n, &m);
  w = rt = cntP = 0;
  for (int i = 1, x, y; i <= m; ++i) scanf("%d %d", &x, &y), ins(y);
  printf("%d\n", C(n * 2 - w - 1, n));
}
int main() {
  srand(time(0));
  fc[0] = invF[0] = 1;
  for (int i = 1; i <= lim; ++i) fc[i] = 1ll * fc[i - 1] * i % 998244353;
  invF[lim] = qPow(fc[lim], 998244353 - 2);
  for (int i = lim - 1; i; --i)
    invF[i] = 1ll * invF[i + 1] * (i + 1) % 998244353;
  scanf("%d", &T);
  while (T--) slv();
  return 0;
}
