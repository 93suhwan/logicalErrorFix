#include <bits/stdc++.h>
using namespace std;
int N, M;
int X[500010], Y[500010];
int A[500010];
long long tr[2000010], xs[2000010];
bool tg[2000010], tg2[2000010];
long long info[2000010];
const long long Md = 998244353;
void bul(int o, int l, int r) {
  tg[o] = tg2[o] = false;
  if (l == r) {
    xs[o] = A[l];
    return;
  }
  int m = (l + r) >> 1;
  bul(o << 1, l, m), bul((o << 1) + 1, m + 1, r);
  xs[o] = (xs[o << 1] + xs[(o << 1) + 1]) % Md;
}
inline void pd(int o) {
  if (tg2[o]) {
    info[o << 1] = tr[o << 1] = info[(o << 1) + 1] = tr[(o << 1) + 1] = 0;
    tg[o << 1] = tg[(o << 1) + 1] = false;
    tg2[o << 1] = tg2[(o << 1) + 1] = true;
    tg2[o] = false;
  }
  info[o << 1] =
      (tg[o] ? info[o] - info[o << 1] + Md : info[o] + info[o << 1]) % Md;
  tg[o << 1] ^= tg[o];
  info[(o << 1) + 1] = (tg[o] ? info[o] - info[(o << 1) + 1] + Md
                              : info[o] + info[(o << 1) + 1]) %
                       Md;
  tg[(o << 1) + 1] ^= tg[o];
  if (tg[o]) {
    tr[o << 1] = (1ll * info[o] * xs[o << 1] - tr[o << 1] + Md) % Md;
    tr[(o << 1) + 1] =
        (1ll * info[o] * xs[(o << 1) + 1] - tr[(o << 1) + 1] + Md) % Md;
  } else {
    tr[o << 1] = (1ll * info[o] * xs[o << 1] + tr[o << 1]) % Md;
    tr[(o << 1) + 1] =
        (1ll * info[o] * xs[(o << 1) + 1] + tr[(o << 1) + 1]) % Md;
  }
  tg[o] = false;
  info[o] = 0;
}
void mdf(int o, int l, int r, int ll, int rr, long long k) {
  if (ll <= l && r <= rr) {
    tr[o] = (1ll * k * xs[o] - tr[o] + Md) % Md;
    info[o] = (k - info[o] + Md) % Md;
    tg[o] ^= 1;
    return;
  }
  pd(o);
  int m = (l + r) >> 1;
  if (ll <= m) mdf(o << 1, l, m, ll, rr, k);
  if (rr > m) mdf((o << 1) + 1, m + 1, r, ll, rr, k);
  (tr[o] = tr[o << 1] + tr[(o << 1) + 1]) %= Md;
}
void mdf2(int o, int l, int r, int ll, int rr) {
  if (ll <= l && r <= rr) {
    tr[o] = info[o] = 0;
    tg[o] = false;
    tg2[o] = true;
    return;
  }
  pd(o);
  int m = (l + r) >> 1;
  if (ll <= m) mdf2(o << 1, l, m, ll, rr);
  if (rr > m) mdf2((o << 1) + 1, m + 1, r, ll, rr);
  (tr[o] = tr[o << 1] + tr[(o << 1) + 1]) %= Md;
}
int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) scanf("%d", &X[i]), Y[i] = X[i];
  sort(Y + 1, Y + N + 1);
  M = unique(Y + 1, Y + N + 1) - Y - 1;
  for (int i = 1; i <= N; i++) X[i] = lower_bound(Y + 1, Y + M + 1, X[i]) - Y;
  for (int i = 1; i <= M; i++) A[i] = Y[i] - Y[i - 1];
  bul(1, 1, M);
  mdf(1, 1, M, 1, X[1], 1);
  for (int i = 2; i <= N; i++) {
    long long q = tr[1];
    mdf(1, 1, M, 1, X[i], q);
    if (X[i] != M) mdf2(1, 1, M, X[i] + 1, M);
  }
  printf("%lld", tr[1]);
  return 0;
}
