#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const int MAXN = 200005;
long long qpow(long long d, long long z) {
  long long res = 1;
  for (; z; z >>= 1) {
    if (z & 1) res = res * d % MOD;
    d = d * d % MOD;
  }
  return res;
}
int n, m, x, y, tx, ty;
vector<long long> g;
long long Q = 0, p, rp;
long long con(int x, int y, int z) {
  if (x <= z && z < y) {
    return Q + z - x;
  } else if (y < z && z <= x) {
    return Q + x - z;
  }
  return MOD;
}
long long calc(pair<int, int> &d, pair<int, int> &pos) {
  int sx = pos.first, sy = pos.second, ux, uy;
  if (1 == d.first) {
    ux = n - sx;
  } else {
    ux = sx - 1;
  }
  if (1 == d.second) {
    uy = m - sy;
  } else {
    uy = sy - 1;
  }
  int mv = min(ux, uy);
  pos.first = sx + d.first * mv;
  pos.second = sy + d.second * mv;
  long long hh = con(sx, pos.first, tx);
  long long jj = con(sy, pos.second, ty);
  if (hh > jj) swap(hh, jj);
  if (hh < MOD) g.push_back(hh);
  if (jj > hh && jj < MOD) g.push_back(jj);
  if (ux <= uy) d.first = -d.first;
  if (uy <= ux) d.second = -d.second;
  return mv;
}
long long Ex(long long t, long long c) {
  return t * qpow(rp, c - 1) % MOD * p % MOD;
}
void solve() {
  Q = 0;
  int PP;
  scanf("%d%d%d%d%d%d%d", &n, &m, &x, &y, &tx, &ty, &PP);
  p = qpow(100, MOD - 2) * PP % MOD;
  rp = qpow(100, MOD - 2) * (100 - PP) % MOD;
  pair<int, int> d = make_pair(1, 1), pos = make_pair(x, y);
  g.clear();
  long long Q0 = 0;
  Q0 = calc(d, pos);
  vector<long long> ini;
  swap(g, ini);
  long long ans = 0;
  for (int i = 0; i < ini.size(); i++) ans = (ans + Ex(ini[i], i + 1)) % MOD;
  long long E = 0;
  int c0 = ini.size() + 1;
  pair<int, int> D = d, POS = pos;
  do {
    Q += calc(d, pos);
  } while (d != D || pos != POS);
  for (int i = 0; i < g.size(); i++) E = (E + Ex(g[i] + Q0, i + c0)) % MOD;
  long long Z = qpow(rp, g.size());
  long long Zsigma = qpow(1 - Z + MOD, MOD - 2);
  ans = (ans + E * Zsigma % MOD) % MOD;
  long long FQ = 0;
  for (int i = 0; i < g.size(); i++) FQ = (FQ + Ex(Q, i + c0)) % MOD;
  ans = (ans + FQ * Z % MOD * Zsigma % MOD * Zsigma % MOD) % MOD;
  printf("%lld\n", ans);
  return;
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}
