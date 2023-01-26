#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline bool chkmax(T &x, T y) {
  return (x < y) ? ((x = y), 1) : 0;
}
template <typename T>
inline bool chkmin(T &x, T y) {
  return (x > y) ? ((x = y), 1) : 0;
}
const int NN = 2e5 + 10, RN = 2e5, Mod = 998244353;
int T, N, M, x[NN], y[NN];
int tr[NN];
void add(int p, int v) {
  for (; p <= RN; p += ((p) & (-(p)))) tr[p] += v;
}
int query(int p) {
  int ret = 0;
  for (; p; p -= ((p) & (-(p)))) ret += tr[p];
  return ret;
}
int kth(int k) {
  int ret = 0;
  for (int i = 17; i >= 0; --i)
    if (ret + (1 << i) <= RN && k > tr[ret + (1 << i)]) {
      k -= tr[ret + (1 << i)];
      ret += (1 << i);
    }
  return ret + 1;
}
bool tag[NN];
int ad(int x, int y) { return ((x + y) >= Mod) ? (x + y - Mod) : (x + y); }
int dc(int x, int y) { return ((x - y) < 0) ? (x - y + Mod) : (x - y); }
int ml(int x, int y) { return (long long)x * y % Mod; }
int ksm(int x, int y) {
  int ret = 1;
  for (; y; y >>= 1, x = ml(x, x))
    if (y & 1) ret = ml(ret, x);
  return ret;
}
int fac[NN * 2], ifac[NN * 2];
void prepare() {
  fac[0] = 1;
  for (int i = 1; i <= RN * 2; ++i) fac[i] = ml(fac[i - 1], i);
  ifac[RN * 2] = ksm(fac[RN * 2], Mod - 2);
  for (int i = RN * 2 - 1; i >= 0; --i) ifac[i] = ml(ifac[i + 1], i + 1);
}
int binom(int u, int d) {
  if (d < 0 || u < d) return 0;
  return ml(fac[u], ml(ifac[d], ifac[u - d]));
}
vector<int> clr1, clr2;
int main() {
  scanf("%d", &T);
  for (int i = 1; i <= RN; ++i) add(i, 1);
  prepare();
  while (T--) {
    clr1.clear();
    clr2.clear();
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= M; ++i) scanf("%d%d", &x[i], &y[i]);
    int cnt = N - 1;
    for (int i = M; i >= 1; --i) {
      int t1 = kth(y[i]), t2 = kth(y[i] + 1);
      add(t1, -1);
      clr1.push_back(t1);
      if (!tag[t2]) {
        tag[t2] = 1;
        --cnt;
        clr2.push_back(t2);
      }
    }
    printf("%d\n", binom(N + cnt, N));
    for (int i = 0; i < (int)clr1.size(); ++i) {
      add(clr1[i], 1);
    }
    for (int i = 0; i < (int)clr2.size(); ++i) {
      tag[clr2[i]] = 0;
    }
  }
  return 0;
}
