#include <bits/stdc++.h>
using namespace std;
int read() {
  int a = 0;
  char c = getchar();
  while (!isdigit(c)) c = getchar();
  while (isdigit(c)) {
    a = a * 10 + c - 48;
    c = getchar();
  }
  return a;
}
const long long _ = 1e5 + 7;
long long dp[_][20], T, N, K, prm[_], phi[_], cprm;
bool nprm[_];
vector<long long> pot[_];
struct segt {
  long long mrk[_ << 2], mn[_ << 2];
  void upd(long long x) {
    mn[x] = min(mn[(x << 1)], mn[(x << 1 | 1)]) + mrk[x];
  }
  void init(long long x, long long l, long long r) {
    mn[x] = 1e9;
    mrk[x] = 0;
    if (l != r) {
      init((x << 1), l, ((l + r) >> 1));
      init((x << 1 | 1), ((l + r) >> 1) + 1, r);
    }
  }
  void mdf(long long x, long long l, long long r, long long t, long long v) {
    mn[x] = min(mn[x], v);
    if (l == r) return;
    ((l + r) >> 1) >= t ? mdf((x << 1), l, ((l + r) >> 1), t, v)
                        : mdf((x << 1 | 1), ((l + r) >> 1) + 1, r, t, v);
  }
  void mdf(long long x, long long l, long long r, long long L, long long R,
           long long v) {
    if (l >= L && r <= R) {
      mrk[x] += v;
      mn[x] += v;
      return;
    }
    if (((l + r) >> 1) >= L) mdf((x << 1), l, ((l + r) >> 1), L, R, v);
    if (((l + r) >> 1) < R) mdf((x << 1 | 1), ((l + r) >> 1) + 1, r, L, R, v);
    upd(x);
  }
} mn;
signed main() {
  phi[1] = 1;
  for (long long i = 2; i <= 1e5; ++i) {
    if (!nprm[i]) {
      prm[++cprm] = i;
      phi[i] = i - 1;
    }
    for (long long j = 1; prm[j] * i <= 1e5; ++j) {
      nprm[prm[j] * i] = 1;
      if (i % prm[j] == 0) {
        phi[i * prm[j]] = phi[i] * prm[j];
        break;
      }
      phi[i * prm[j]] = phi[i] * (prm[j] - 1);
    }
  }
  for (long long i = 1; i <= 1e5; ++i) {
    dp[i][0] = 1e9;
    for (long long j = 2 * i; j <= 1e5; j += i) pot[j].push_back(i);
  }
  for (long long j = 0; j < 17; ++j) {
    mn.init(1, 0, 1e5);
    for (long long i = 1; i <= 1e5; ++i) {
      mn.mdf(1, 0, 1e5, i - 1, dp[i - 1][j]);
      for (auto t : pot[i]) mn.mdf(1, 0, 1e5, 0, t - 1, phi[i / t]);
      dp[i][j + 1] = mn.mn[1];
    }
  }
  for (T = read(); T; --T) {
    N = read();
    K = read();
    printf("%lld\n", dp[N][min(K, 17ll)] + N);
  }
  return 0;
}
