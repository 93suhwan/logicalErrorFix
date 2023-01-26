#include <bits/stdc++.h>
using namespace std;
int N, M;
const int MAXN = 2e5 + 10;
int les[MAXN];
struct TreeArray {
  int f[MAXN];
  void update(int x, int d) {
    while (x <= N) f[x] += d, x += x & (-x);
  }
  int query(int x) {
    int ret = 0;
    while (x) ret += f[x], x -= x & (-x);
    return ret;
  }
  int find(int x) {
    int L = 0, R = N, mid;
    while (L + 1 < R) {
      mid = (L + R) >> 1;
      int tmp = query(mid);
      if (mid - tmp < x)
        L = mid;
      else
        R = mid;
    }
    return R;
  }
} tr;
int p[MAXN], q[MAXN];
long long fact[MAXN << 1], invfact[MAXN << 1];
const long long mod = 998244353;
long long fastpow(long long a, long long b) {
  long long ret = 1;
  while (b) {
    if (b & 1) ret = ret * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ret;
}
int cnt;
int s[MAXN], n;
int main() {
  fact[0] = fact[1] = 1;
  for (int i = 2; i <= 400000; i++) fact[i] = fact[i - 1] * i % mod;
  invfact[400000] = fastpow(fact[400000], mod - 2);
  for (int i = 399999; i >= 0; i--) invfact[i] = invfact[i + 1] * (i + 1) % mod;
  for (int i = 1; i <= 200000; i++) les[i] = -1;
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &N, &M);
    cnt = N - 1;
    n = 0;
    if (M) {
      for (int i = 1; i <= M; i++) scanf("%d%d", &p[i], &q[i]);
      for (int i = M, last = N + 1, pos; i >= 1; i--) {
        if (last > p[i] + 1) {
          pos = tr.find(p[i] + 1);
          s[++n] = pos;
          if (les[pos - 1] == -1) les[pos - 1] = 0;
          tr.update(pos, 1);
        }
        pos = tr.find(q[i]);
        if (les[pos - 1] == -1) les[pos - 1] = 0;
        if (les[pos] == -1) les[pos] = 1, --cnt;
        tr.update(pos, 1);
        s[++n] = pos;
        last = p[i];
      }
      for (int i = 1; i <= n; i++)
        tr.update(s[i], -1), les[s[i] - 1] = les[s[i]] = -1;
    }
    printf("%lld\n", fact[N + cnt] * invfact[N] % mod * invfact[cnt] % mod);
  }
  return 0;
}
