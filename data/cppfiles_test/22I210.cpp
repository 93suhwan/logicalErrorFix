#include <bits/stdc++.h>
using namespace std;
const int maxn = 41, maxm = 11;
const int BLEN = 16, BMSK = (1 << BLEN) - 1, maxd = BMSK + 2;
const int mod = (int)1e9 + 7, INF = 0x3f3f3f3f;
const long long INFLL = (long long)INF << 32 | INF;
const double eps = (double)1e-12, pi = acos((double)-1);
inline int sgn(double x) { return (x > eps) - (x < -eps); }
inline bool is_prime(int x) {
  if (x <= 2 || !(x & 1)) return x == 2;
  for (int i = 3; i * i <= x; i += 2)
    if (x % i == 0) return 0;
  return 1;
}
inline long long mod_mul(long long x, long long y, long long mod) {
  long long ret = x * y - (long long)((long double)x * y / mod + 1e-3) * mod;
  for (; ret < 0; ret += mod)
    ;
  return ret;
}
inline long long mod_pow(long long x, long long k, long long mod) {
  long long ret = mod > 1 ? 1 : 0;
  for (; k > 0; k >>= 1, x = mod_mul(x, x, mod))
    if (k & 1) ret = mod_mul(ret, x, mod);
  return ret;
}
int n, m, bits[maxd], adt[maxm];
unsigned long long fir[maxm], msk[maxm], nxt[maxm][maxn];
inline int popcount(unsigned long long x) {
  int ret = 0;
  while (x > 0) {
    ret += bits[(unsigned int)x & BMSK];
    x >>= BLEN;
  }
  return ret;
}
bool dfs(int dep, unsigned long long state) {
  if (dep == m) return state == (1ULL << popcount(state)) - 1;
  int cnt = popcount(state & msk[dep]);
  state &= ~msk[dep];
  for (int i = 0; i <= adt[dep]; ++i)
    if (!dfs(dep + 1, state | nxt[dep][cnt + i])) return 0;
  return 1;
}
void solve() {
  scanf("%d%d", &n, &m);
  long long vis = 0;
  for (int i = 0; i < m; ++i) {
    vector<int> pos;
    int sz, x;
    scanf("%d", &sz);
    fir[i] = msk[i] = adt[i] = 0;
    while (sz--) {
      scanf("%d", &x);
      --x;
      if (!(vis & (1ULL << x))) {
        vis |= 1ULL << x;
        fir[i] |= 1ULL << x;
        ++adt[i];
      }
      msk[i] |= 1ULL << x;
      pos.push_back(x);
    }
    sort(pos.begin(), pos.end());
    nxt[i][0] = 0;
    for (int j = 0, sz = (int)pos.size(); j < sz; ++j)
      nxt[i][j + 1] = nxt[i][j] | (1ULL << pos[j]);
  }
  puts(vis == (1ULL << n) - 1 && dfs(0, 0LL) ? "ACCEPTED" : "REJECTED");
}
int main() {
  for (int i = 1; i < maxd; ++i) bits[i] = bits[i >> 1] + (i & 1);
  int T = 1;
  for (int Case = 1; Case <= T; ++Case) {
    solve();
  }
  return 0;
}
