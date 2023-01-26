#include <bits/stdc++.h>
using namespace std;
long long read() {
  long long qrx = 0, qry = 1;
  char qrc = getchar();
  while (qrc < '0' || qrc > '9') {
    if (qrc == '-') {
      qry = -1, qrc = getchar();
    }
    qrc = getchar();
  }
  while (qrc >= '0' && qrc <= '9') qrx = qrx * 10 + qrc - 48, qrc = getchar();
  return qrx * qry;
}
const long long N = 2e5 + 7, Mod = 998244353, INF = 1e9 + 7;
long long n, q, a[N], sum[N << 2], lm[N << 2], rm[N << 2];
void pushup(long long id, long long L, long long R) {
  if (L == R) return;
  long long Lid = id << 1, Rid = (id << 1) | 1, M = (L + R) >> 1,
            len = R - L + 1, llen = M - L + 1, rlen = len - llen;
  sum[id] = sum[Lid] + sum[Rid];
  lm[id] = (lm[Lid] == llen && a[M] <= a[M + 1]) ? lm[Lid] + lm[Rid] : lm[Lid];
  rm[id] = (rm[Rid] == rlen && a[M] <= a[M + 1]) ? rm[Rid] + rm[Lid] : rm[Rid];
  if (a[M] <= a[M + 1]) sum[id] += (rm[Lid] * lm[Rid]);
  return;
}
void build(long long L, long long R, long long id) {
  if (L == R)
    sum[id] = lm[id] = rm[id] = 1;
  else {
    long long M = (L + R) >> 1;
    build(L, M, id << 1), build(M + 1, R, (id << 1) | 1);
    pushup(id, L, R);
  }
  return;
}
long long query(long long L, long long R, long long id, long long l,
                long long r) {
  if (L >= l && R <= r) {
    return sum[id];
  }
  long long res = 0, M = (L + R) >> 1;
  if (l <= M) res += query(L, M, id << 1, l, r);
  if (r > M) res += query(M + 1, R, (id << 1) | 1, l, r);
  long long LL = max(l, M - rm[id << 1] + 1),
            RR = min(r, M + lm[(id << 1) | 1]);
  LL = M - LL + 1, RR = RR - M;
  if (a[M] <= a[M + 1]) res += LL * RR;
  return res;
}
void chg(long long L, long long R, long long id, long long x, long long y) {
  if (L == R)
    a[x] = y;
  else {
    long long M = (L + R) >> 1;
    if (x <= M)
      chg(L, M, id << 1, x, y);
    else
      chg(M + 1, R, (id << 1) | 1, x, y);
    pushup(id, L, R);
  }
  return;
}
signed main() {
  n = read(), q = read();
  for (long long i = 1; i <= n; i++) a[i] = read();
  build(1, n, 1);
  while (q--) {
    long long ty = read(), x = read(), y = read();
    if (ty == 1) chg(1, n, 1, x, y);
    if (ty == 2) printf("%lld\n", query(1, n, 1, x, y));
  }
  return 0;
}
