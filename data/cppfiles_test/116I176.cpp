#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
const long long mod = 998244353;
int n, m, k;
int Pre[N], Suc[N];
int cnt[N], nxt[N];
bool CanId[N], CanVec[N], tVis[N];
long long dp[N << 1];
vector<int> vec[N], Sons[N];
int fa[N];
int _Find(int u) { return u == fa[u] ? u : fa[u] = _Find(fa[u]); }
void check(int Col) {
  for (int now = Suc[Col]; now; now = Suc[now]) {
    int fu = _Find(Pre[now]), fv = _Find(now);
    if (fu == fv)
      CanId[Pre[now]] = CanId[now] = 0;
    else
      fa[fu] = fv;
  }
}
bool CheckCircle(int Col) {
  if (tVis[Col]) return 1;
  for (int now = Suc[Col]; now; now = Suc[now])
    if (Col == now)
      return 0;
    else
      tVis[now] = 1;
  return 1;
}
bool CheckVec(int Id) {
  bool ret = 1;
  for (int i = 0; i < vec[Id].size(); i++)
    if (tVis[vec[Id][i]]) {
      ret = 0;
      break;
    } else
      tVis[vec[Id][i]] = 1;
  for (int i = 0; i < vec[Id].size(); i++) tVis[vec[Id][i]] = 0;
  if (!ret) CanId[vec[Id][0]] = 0;
  return ret;
}
long long fA[1 << 20 | 5], fB[1 << 20 | 5], Ans[1 << 20 | 5];
int Rev[1 << 20 | 5];
long long qpow(long long n, long long p, long long mod) {
  long long ret = 1;
  while (p) {
    if (p & 1) (ret *= n) %= mod;
    (n *= n) %= mod;
    p >>= 1;
  }
  return ret;
}
void NTT(long long *F, int n, int Sign) {
  for (int i = 0; i < n; i++)
    if (i < Rev[i]) swap(F[i], F[Rev[i]]);
  for (int len = 2; len <= n; len <<= 1) {
    int mid = (len >> 1);
    long long wl = qpow(3, (mod - 1) / len, mod);
    for (int i = 0; i < n; i += len) {
      long long Ang = 1;
      for (int j = 0; j < mid; j++) {
        long long tx = F[i + j], ty = (F[i + j + mid] * Ang) % mod;
        F[i + j] = (tx + ty) % mod;
        F[i + j + mid] = (tx - ty + mod) % mod;
        (Ang *= wl) %= mod;
      }
    }
  }
  if (Sign == -1) {
    long long Invn = qpow(n, mod - 2, mod);
    for (int i = 1; i < (n >> 1); i++) swap(F[i], F[n - i]);
    for (int i = 0; i < n; i++) (F[i] *= Invn) %= mod;
  }
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= k; i++) fa[i] = i, CanId[i] = CanVec[i] = 1;
  for (int C, i = 1; i <= n; i++) {
    scanf("%d", &C);
    for (int x; C--;) scanf("%d", &x), vec[i].push_back(x);
    CheckVec(i);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j < vec[i].size(); j++) {
      int Up = vec[i][j - 1], Down = vec[i][j];
      if ((!Pre[Down] || Pre[Down] == Up) && (!Suc[Up] || Suc[Up] == Down)) {
        Pre[Down] = Up;
        Suc[Up] = Down;
      } else
        CanId[Up] = CanId[Down] = 0;
    }
  }
  for (int i = 1; i <= k; i++)
    if (!Pre[i]) check(i);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j < vec[i].size(); j++) {
      int Up = vec[i][j - 1], Down = vec[i][j];
      int fu = _Find(Up), fv = _Find(Down);
      if (fu != fv) fa[fu] = fv;
    }
  for (int i = 1; i <= k; i++) _Find(i);
  for (int i = 1; i <= k; i++) tVis[i] = 0;
  for (int i = 1; i <= k; i++) Sons[fa[i]].push_back(i);
  for (int i = 1; i <= k; i++)
    if (!CheckCircle(i)) CanId[i] = 0;
  for (int i = 1; i <= k; i++)
    if (!CanId[i]) CanVec[fa[i]] = 0;
  for (int i = 1; i <= k; i++)
    if (CanVec[i] && Sons[i].size() > 0U) cnt[Sons[i].size()]++;
  int p = 0;
  while ((1 << p) <= m + m) p++;
  for (int i = 1, End = (1 << p); i < End; i++) {
    Rev[i] = (Rev[i >> 1] >> 1) | ((i & 1) << (p - 1));
  }
  for (int i = 1; i <= min(m, k); i++) fA[i] = cnt[i];
  Ans[0] = 1;
  for (int tm = m; tm; tm >>= 1) {
    if (tm & 1) {
      NTT(Ans, 1 << p, 1);
      NTT(fA, 1 << p, 1);
      for (int i = 0; i < (1 << p); i++) (Ans[i] *= fA[i]) %= mod;
      NTT(Ans, 1 << p, -1);
      NTT(fA, 1 << p, -1);
      for (int i = m + 1; i < (1 << p); i++) Ans[i] = 0;
    }
    for (int i = 0; i < (1 << p); i++)
      printf("%lld%c", fA[i], " \n"[i == (1 << p) - 1]);
    NTT(fA, 1 << p, 1);
    for (int i = 0; i < (1 << p); i++)
      printf("%lld%c", fA[i], " \n"[i == (1 << p) - 1]);
    for (int i = 0; i < (1 << p); i++) (fA[i] *= fA[i]) %= mod;
    NTT(fA, 1 << p, -1);
    for (int i = m + 1; i < (1 << p); i++) fA[i] = 0;
  }
  printf("%lld\n", Ans[m]);
  return 0;
}
